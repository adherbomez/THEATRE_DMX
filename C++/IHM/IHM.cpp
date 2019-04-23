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
	lbSeq->Items->Add("Eqp_1");
	lbSeq->Items->Add("Eqp_2");
	lbSeq->Items->Add("Eqp_3");
	lbSeq->Items->Add("Eqp_4");
	lbSeq->Items->Add("Eqp_5");
	lbSeq->Items->Add("Eqp_6");


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
//-------------------------------lumi�re---------------------------------------

//chargement pour la dll
HINSTANCE g_dasusbdll = NULL;
typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
DASHARDCOMMAND  DasUsbCommand = NULL;

//vecteurs
std::vector<sequence*>seq;
std::vector<scene*>scn;

//d�claration des attributs
trameManager*trame=new trameManager();
trameManager*trame1=new trameManager();
trameManager*trame2=new trameManager();

char*dmxx;
char*dmxx1;
char*dmxx2;
int i;
dmxx = new char[512];
dmxx1 = new char[512];
dmxx2 = new char[512];

	//on impl�mente une trame dmx
	//rouge
		dmxx[0]=116;
		dmxx[1]=0;
		dmxx[2]=0;
		dmxx[3]=255;
		dmxx[4]=255;
		dmxx[5]=120;
trame->dmx=dmxx;
	//vert
		dmxx1[0]=116;
		dmxx1[1]=0;
		dmxx1[2]=255;
		dmxx1[3]=0;
		dmxx1[4]=255;
		dmxx1[5]=120;
trame1->dmx=dmxx1;
	//bleu
		dmxx2[0]=116;
		dmxx2[1]=255;
		dmxx2[2]=0;
		dmxx2[3]=0;
		dmxx2[4]=255;
		dmxx2[5]=120;
trame2->dmx=dmxx2;


//sequences
seq1=new sequence(1,1000,trame);
seq2=new sequence(2,1000,trame1);
seq3=new sequence(3,1000,trame2);
	//on remplie le vector avec les s�quences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);

//scene
std::string name= "soleil";
scn1=new scene(1,name,20);
	//on impl�mente le vecteur sc�ne
	scn1->setSequences(seq1);
	scn1->setSequences(seq2);
	scn1->setSequences(seq3);
	scn.push_back(scn1);

//programme
std::string name_prog= "test";
prog=new programme(1,name_prog,scn);

//chargement de la dll
	g_dasusbdll = LoadLibrary("DasHard2006.dll");
	if (g_dasusbdll)
		DasUsbCommand  = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll, "DasUsbCommand");
	if (DasUsbCommand)
		Shape1->Brush->Color=clGreen;

//connexion � l'usb dmx
	DasUsbCommand(DHC_INIT,0,NULL);
	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	{	for (i = 0; i < scn1->getNbSeq(); i++)
		{
			Shape2->Brush->Color=clGreen;
			DasUsbCommand(DHC_DMXOUT, 512, scn1->getSequences()[i]->getTrame()->dmx);
		}
	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);


//-------------------------------serveur---------------------------------------
	if(server != NULL)
	{
		Shape3->Brush->Color=clGreen;
		try
		{   //r�cup�ration du
			 cl = server->shData->Get();
			//on v�rifie l'etat du client stock� dans une structure InfoClient
			if(cl.clInfo.clEtat.connect== true)
			{
				Label6->Caption = cl.message.c_str();
				Shape4->Brush->Color=clGreen;
				//std::string test=Parser::Parse(cl);
				//Edit1->Text=test.c_str();
			}
			else
			{
				Label4->Caption = "Client d�connect�";
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
   	//---------------Fonctionnalit� de L'IHM-----------------------------
	if (edtNameEqp->Text!="" && edtAdr->Text!="" && edtNbCan->Text!="" && btnValideEqp->OnClick)
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
	//TODO: check dans la BDD si l'�quipement n'y est pas via le nom

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnNokEqpClick(TObject *Sender)
{
	//TODO: recharge une page de formulaire
}
//---------------------------------------------------------------------------



void __fastcall TForm1::lbSeqClick(TObject *Sender)
{
	if (lbSeq->OnClick)
	{

		lb2Seq->Items->Add(lbSeq->Items->);
	}
}
//---------------------------------------------------------------------------


