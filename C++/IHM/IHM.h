//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Programme.h"
#include "Scene.h"
#include "Sequence.h"
#include <Vcl.ExtCtrls.hpp>
#include <map>
#include "String.h"
#include "_DasHard.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TLabel *Label1;
	TShape *Shape1;
	TLabel *Label2;
	TShape *Shape2;
	TEdit *Edit1;
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur

	programme*prog;
	scene*scn1;
	sequence*seq1;
	sequence*seq2;
	sequence*seq3;


	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
