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
/*
//chargement pour la dll
HINSTANCE g_dasusbdll = NULL;
typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
DASHARDCOMMAND  DasUsbCommand = NULL;

//vecteurs
std::vector<sequence*>seq;
std::vector<scene*>scn;

//d�claration des attributs
trameManager*trame=new trameManager();
char*dmxx;
int i;
dmxx = new char[512];

	//on impl�mente une trame dmx
		dmxx[0]=185;
		dmxx[1]=116;
		dmxx[2]=100;
		dmxx[3]=100;

trame->dmx=dmxx;

//sequences
seq1=new sequence(1,20,trame);
seq2=new sequence(2,40,trame);
seq3=new sequence(3,60,trame);
	//on remplie le vector avec les s�quences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);

//scene
std::string name= "soleil";
scn1=new scene(1,name,20,seq);
	//on impl�mente le vecteur sc�ne
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
	{
		Shape2->Brush->Color=clGreen;
		DasUsbCommand(DHC_DMXOUT, 512, trame->dmx);
	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);
  */

	server = NULL;
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
char*dmxx;
int i;
dmxx = new char[512];

	//on impl�mente une trame dmx
		dmxx[0]=bar1->Position;
		dmxx[1]=bar2->Position;
		dmxx[2]=bar3->Position;
		dmxx[3]=bar4->Position;
		dmxx[4]=bar5->Position;
		dmxx[5]=bar6->Position;
		Memo1->Lines->Add(bar1->Position);

trame->dmx=dmxx;

//sequences
seq1=new sequence(1,20,trame);
seq2=new sequence(2,40,trame);
seq3=new sequence(3,60,trame);
	//on remplie le vector avec les s�quences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);

//scene
std::string name= "soleil";
scn1=new scene(1,name,20,seq);
	//on impl�mente le vecteur sc�ne
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
	{
		Shape2->Brush->Color=clGreen;
		DasUsbCommand(DHC_DMXOUT, 512, trame->dmx);
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



