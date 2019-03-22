//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
//chargement pour la dll
HINSTANCE g_dasusbdll = NULL;
typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
DASHARDCOMMAND  DasUsbCommand = NULL;

//vecteurs
std::vector<sequence*>seq;
std::vector<scene*>scn;

	//déclaration des attributs
trameManager*trame=new trameManager();
char*dmxx;
int i;
dmxx = new char[512];

	//on implémente une trame dmx
	for (i = 0; i < 8; i++)
	{
		dmxx[i]=230+i;
	}
trame->dmx=dmxx;

//sequences
seq1=new sequence(1,20,trame);
seq2=new sequence(2,40,trame);
seq3=new sequence(3,60,trame);
	//on remplie le vector avec les séquences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);


//scene
std::string name= "soleil";
scn1=new scene(1,name,20,seq);
	//on implémente le vecteur scène
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

//connexion à l'usb dmx
	DasUsbCommand(DHC_INIT,0,NULL);
	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	{
		Shape2->Brush->Color=clGreen;
		DasUsbCommand(DHC_DMXOUT, 512, trame->dmx);
	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);


}


//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//chargement pour la dll
HINSTANCE g_dasusbdll = NULL;
typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
DASHARDCOMMAND  DasUsbCommand = NULL;

//vecteurs
std::vector<sequence*>seq;
std::vector<scene*>scn;

	//déclaration des attributs
trameManager*trame=new trameManager();
char*dmxx;
int i;
dmxx = new char[512];

	//on implémente une trame dmx
	for (i = 17; i < 23; i++)
	{
		dmxx[i]=23+i;
	}
trame->dmx=dmxx;

//sequences
seq1=new sequence(1,20,trame);
seq2=new sequence(2,40,trame);
seq3=new sequence(3,60,trame);
	//on remplie le vector avec les séquences
	seq.push_back(seq1);
	seq.push_back(seq2);
	seq.push_back(seq3);


//scene
std::string name= "soleil";
scn1=new scene(1,name,20,seq);
	//on implémente le vecteur scène
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

//connexion à l'usb dmx
	DasUsbCommand(DHC_INIT,0,NULL);
	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	{
		Shape2->Brush->Color=clGreen;
		DasUsbCommand(DHC_DMXOUT, 512, trame->dmx);
	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);


}
//---------------------------------------------------------------------------

