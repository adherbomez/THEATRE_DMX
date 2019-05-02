//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop

#include "IHM.h"
#include "ServerStructs.h"
#include "Parser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	server = NULL;

//vecteurs
std::vector<sequence*>seq;


//déclaration des attributs
trameManager*trame=new trameManager();
trameManager*trame1=new trameManager();
trameManager*trame2=new trameManager();

char*tableau[3];

int i;
tableau[0] = new char[512];
tableau[1] = new char[512];
tableau[2] = new char[512];

	//on implémente une trame dmx
	//bleu
		tableau[0][0]=116;
		tableau[0][1]=0;
		tableau[0][2]=0;
		tableau[0][3]=255;
		tableau[0][4]=255;
		tableau[0][5]=120;
trame->dmx=tableau[0];
	//vert
		tableau[1][0]=116;
		tableau[1][1]=0;
		tableau[1][2]=255;
		tableau[1][3]=0;
		tableau[1][4]=255;
		tableau[1][5]=120;
trame1->dmx=tableau[1];
	//rouge
		tableau[2][0]=116;
		tableau[2][1]=255;
		tableau[2][2]=0;
		tableau[2][3]=0;
		tableau[2][4]=255;
		tableau[2][5]=120;
trame2->dmx=tableau[2];


//sequences
seq1=new sequence(1,2000,trame);
seq2=new sequence(2,3000,trame1);
seq3=new sequence(3,4000,trame2);
	//on remplie le vector avec les séquences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);

//scene
std::string name= "soleil";
scn1=new scene(1,name,20);
	//on implémente le vecteur scène
	scn1->setSequences(seq1);
	scn1->setSequences(seq2);
	scn1->setSequences(seq3);
	scn1->planifyScene();
	scn.push_back(scn1);
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//---------------------------------------------------------------------------
//Connexion TCPServeur
	server= new TCPServer();
	server->bindSocket(9998);

	DWORD dwThreadId;

	CreateThread(
		NULL,
		0,
		TCPServer::connexion,
		server,
		0,
		&dwThreadId);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//-------------------------------lumière---------------------------------------
//chargement pour la dll
	HINSTANCE g_dasusbdll = NULL;
	typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
	DASHARDCOMMAND  DasUsbCommand = NULL;

//programme
	std::string name_prog= "test";
	prog=new programme(1,name_prog,scn);

//chargement de la dll
	g_dasusbdll = LoadLibrary("DasHard2006.dll");
	if (g_dasusbdll)
		DasUsbCommand  = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll, "DasUsbCommand");
	if (DasUsbCommand)
		Shape1->Brush->Color=clGreen;

//connexion à l'usb dmx
	DasUsbCommand(DHC_INIT,0,NULL);
	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	{
		if(scn.size() > 0)
		{
			if(scn.front()->updateScene())
			{
				scn.pop_back();
			}
			DasUsbCommand(DHC_DMXOUT, 512, scn.front()->getSequences()[scn.front()->getSeqIndex()]->getTrame()->dmx);
		}
		Shape2->Brush->Color=clGreen;

	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);


//-------------------------------serveur---------------------------------------
	if(server != NULL)
	{
		Shape3->Brush->Color=clGreen;
		try
		{   //récupération du
			 cl = server->shData->Get();
			//on vérifie l'etat du client stocké dans une structure InfoClient
			if(cl.clInfo.clEtat.connect== true)
			{
				Label6->Caption = cl.message.c_str();
				Shape4->Brush->Color=clGreen;
				//std::string test=Parser::Parse(cl);
				//Edit1->Text=test.c_str();
			}
			else
			{
				Label4->Caption = "Client déconnecté";
				Shape3->Brush->Color=clRed;
				Shape4->Brush->Color=clRed;
			}


		}
		catch(TCPServerException error)
		{
			//MessageBox(this->Handle, error.c_str(), "Erreur", 0);
		}
	}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::menuEqpClick(TObject *Sender)
{
	if (menuEqp->OnClick)
	{
		gbEqp->Visible=true;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::btnValideEqpClick(TObject *Sender)
{
	//---------------Fonctionnalité de L'IHM-----------------------------
	if (edtNameEqp->Text!="" && edtNbCan->Text!="" && btnValideEqp->OnClick)
	{
		lblProp->Visible=true;
		edtProp->Visible=true;
		btnPropEqp->Visible=true;
	}
	else
	{
		MessageBox(this->Handle,"Un ou plusieurs champs sont vides", "Erreur", 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnPropEqpClick(TObject *Sender)
{
	if (edtProp->Text!="" && btnPropEqp->OnClick)
	{
		lblEqpValide->Visible=true;
		btnOkEqp->Visible=true;
        btnNokEqp->Visible=true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnOkEqpClick(TObject *Sender)
{
	//TODO: check dans la BDD si l'équipement n'y est pas via le nom

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnNokEqpClick(TObject *Sender)
{
	//TODO: recharge une page de formulaire
}
//---------------------------------------------------------------------------



//bouton qui permet d'ajouter des equipements pour les séquences
void __fastcall TForm1::btnSeqAddClick(TObject *Sender)
{
	int  NbListSq1;
	int  NbListSq2;
	 NbListSq1=lbSeq->Items->Count;
	  NbListSq2=lb2Seq->Items->Count;
		 for(int i=0;i<NbListSq1;i++)
		 {
			if (lbSeq->Selected[i])
				{
					if (!FileExists(lbSeq->Items->Strings[i]))
					 {
						  lb2Seq->Items->Strings[NbListSq2]=lbSeq->Items->Strings[i];

						  NbListSq2++;


					 }
				}
		 }

}
//---------------------------------------------------------------------------
//bouton qui supprime des équipements pour les séquences
void __fastcall TForm1::btnSeqSuppClick(TObject *Sender)
{
	int  NbListSq1;
	int  NbListSq2;
	 NbListSq1=lbSeq->Items->Count;
	  NbListSq2=lb2Seq->Items->Count;
		 for(int i=0;i<NbListSq2;i++)
		 {
			if (lb2Seq->Selected[i])
				{
					if (!FileExists(lbSeq->Items->Strings[i]))
					 {

						  lb2Seq->Items->Delete(i);
						  NbListSq2--;


					 }
				}
		 }
}
//---------------------------------------------------------------------------
//génére les équipements de la bdd
void __fastcall TForm1::gpSeqClick(TObject *Sender)
{
	//TODO: CODE QUI GENERE LES EQUIPEMENTS DEPUIS LA BDD

	lbSeq->Items->Add("Eqp_1");
	lbSeq->Items->Add("Eqp_2");
	lbSeq->Items->Add("Eqp_3");
	lbSeq->Items->Add("Eqp_4");
	lbSeq->Items->Add("Eqp_5");
	lbSeq->Items->Add("Eqp_6");

}
//---------------------------------------------------------------------------
//génére les séquences de la bdd
void __fastcall TForm1::gpSceneClick(TObject *Sender)
{
	//TODO: CODE QUI GENERE LES SEQUENCES DEPUIS LA BDD

	lbScene->Items->Add("Seq_1");
	lbScene->Items->Add("Seq_2");
	lbScene->Items->Add("Seq_3");
	lbScene->Items->Add("Seq_4");
	lbScene->Items->Add("Seq_5");
	lbScene->Items->Add("Seq_6");
}
//---------------------------------------------------------------------------
//affiche les scenes dans le listbox
void __fastcall TForm1::btnScnAddClick(TObject *Sender)
{
	int  NbListScn1;
	int  NbListScn2;
	 NbListScn1=lbScene->Items->Count;
	  NbListScn2=lb2Scene->Items->Count;
		 for(int i=0;i<NbListScn1;i++)
		 {
			if (lbScene->Selected[i])
				{
					if (!FileExists(lbScene->Items->Strings[i]))
					 {

						 lb2Scene->Items->Strings[NbListScn2]=lbScene->Items->Strings[i];
						 NbListScn2++;


					 }
				}
		 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnScnSuppClick(TObject *Sender)
{
	int  NbListScn1;
	int  NbListScn2;
	 NbListScn1=lbScene->Items->Count;
	  NbListScn2=lb2Scene->Items->Count;
		 for(int i=0;i<NbListScn2;i++)
		 {
			if (lbScene->Selected[i])
				{
					if (!FileExists(lbScene->Items->Strings[i]))
					 {
						 lb2Scene->Items->Delete(i);
						 NbListScn2--;
					 }
				}
		 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::GroupBox4Click(TObject *Sender)
{
  	//TODO: CODE QUI GENERE LES EQUIPEMENTS DEPUIS LA BDD

	lbAdressage->Items->Add("Eqp_1");
	lbAdressage->Items->Add("Eqp_2");
	lbAdressage->Items->Add("Eqp_3");
	lbAdressage->Items->Add("Eqp_4");
	lbAdressage->Items->Add("Eqp_5");
	lbAdressage->Items->Add("Eqp_6");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnAdrClick(TObject *Sender)
{

	int NbList=lbAdressage->Items->Count;
	int i;
	for (i = 0; i < NbList; i++)
	{
		if (lbAdressage->Selected[i] && edtAdr->Text!="")
		{
		  //TODO: Inclure l'adresse à l'équipement sélectionné
		  lblAjoutSucc->Visible=true;
		}
	}
}
//---------------------------------------------------------------------------



