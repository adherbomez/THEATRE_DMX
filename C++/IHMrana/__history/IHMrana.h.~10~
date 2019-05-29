//---------------------------------------------------------------------------

#ifndef IHMranaH
#define IHMranaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "./Programme/Programme.h"
#include "./Scene/Scene.h"
#include "./MySQL/MySQL.h"
#include "./Manager/Manager.h"
#include <Vcl.ExtCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Composants gérés par l'EDI
	TLabel *IdLabel;
	TLabel *NomLabel;
	TLabel *NbrScnLabel;
	TButton *ConnectButton;
	TButton *DisconnectButton;
	TPanel *PanelCheckConnection;
	TButton *GetProgButton;
	TButton *GetSceneButton;
	TEdit *GetProgEdit;
	TEdit *GetSceneEdit;
	TButton *OkButton;
	TButton *ValiderSceneIdButton;
	TEdit *GetProgDataEdit1;
	TEdit *GetProgDataEdit2;
	TEdit *GetProgDataEdit3;
	TMemo *GetDataMemo;
	TButton *SelectModeButton;
	TButton *InsertModeButton;
	TEdit *InsertEquipmentEdit;
	void __fastcall ConnectButtonClick(TObject *Sender);
	void __fastcall DisconnectButtonClick(TObject *Sender);
	void __fastcall GetProgButtonClick(TObject *Sender);
	void __fastcall OkButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall SelectModeButtonClick(TObject *Sender);
	void __fastcall InsertModeButtonClick(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	manager*M1;
	programme*P1;
	std::vector<scene*>Scenes;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
