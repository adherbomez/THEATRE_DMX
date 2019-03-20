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
#include <map>
#include "String.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur

/*	programme*prog;
	scene*scn1;
	sequence*seq1;
	sequence*seq2;
	sequence*seq3;
				  */

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
