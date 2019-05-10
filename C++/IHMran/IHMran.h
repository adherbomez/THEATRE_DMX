//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "./Programme/Programme.h"
#include "./Scene/Scene.h"
#include "./MySQL/MySQL.h"
#include "./Manager/Manager.h"
#include <Vcl.ExtCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *ConnectButton;
	TButton *DisconnectButton;
	TPanel *PanelCheckConnection;
	TButton *GetProgButton;
	TButton *GetSceneButton;
	TEdit *GetProgEdit;
	TEdit *GetSceneEdit;
	TButton *ValiderProgIdButton;
	TButton *ValiderSceneIdButton;
	TLabel *GetProgLabel1;
	TLabel *GetProgLabel2;
	TLabel *GetProgLabel3;
	TEdit *GetProgDataEdit1;
	TEdit *GetProgDataEdit2;
	TEdit *GetProgDataEdit3;
	TMemo *GetDataMemo;
	void __fastcall ConnectButtonClick(TObject *Sender);
	void __fastcall DisconnectButtonClick(TObject *Sender);
	void __fastcall GetProgButtonClick(TObject *Sender);
	void __fastcall ValiderProgIdButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	manager*M1;
	programme*P1;
	std::vector<scene*>Scenes;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
