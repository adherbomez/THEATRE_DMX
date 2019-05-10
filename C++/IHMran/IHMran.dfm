object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 317
  ClientWidth = 362
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object GetProgLabel1: TLabel
    Left = 8
    Top = 106
    Width = 17
    Height = 13
    Caption = 'Id :'
    Visible = False
  end
  object GetProgLabel2: TLabel
    Left = 8
    Top = 130
    Width = 28
    Height = 13
    Caption = 'Nom :'
    Visible = False
  end
  object GetProgLabel3: TLabel
    Left = 8
    Top = 160
    Width = 44
    Height = 13
    Caption = 'Nbr Scn :'
    Visible = False
  end
  object ConnectButton: TButton
    Left = 151
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 0
    OnClick = ConnectButtonClick
  end
  object DisconnectButton: TButton
    Left = 151
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Deconnexion'
    TabOrder = 1
    Visible = False
    OnClick = DisconnectButtonClick
  end
  object PanelCheckConnection: TPanel
    Left = 168
    Top = 31
    Width = 41
    Height = 16
    Color = clRed
    ParentBackground = False
    TabOrder = 2
  end
  object GetProgButton: TButton
    Left = 0
    Top = 42
    Width = 75
    Height = 20
    Caption = 'Programme'
    TabOrder = 3
    Visible = False
    OnClick = GetProgButtonClick
  end
  object GetSceneButton: TButton
    Left = 288
    Top = 42
    Width = 75
    Height = 20
    Caption = 'Scene'
    TabOrder = 4
    Visible = False
  end
  object GetProgEdit: TEdit
    Left = 0
    Top = 68
    Width = 75
    Height = 21
    TabOrder = 5
    Text = 'ID'
    Visible = False
  end
  object GetSceneEdit: TEdit
    Left = 288
    Top = 68
    Width = 75
    Height = 21
    TabOrder = 6
    Text = 'ID'
    Visible = False
  end
  object ValiderProgIdButton: TButton
    Left = 0
    Top = 42
    Width = 75
    Height = 20
    Caption = 'OK'
    TabOrder = 7
    Visible = False
    OnClick = ValiderProgIdButtonClick
  end
  object ValiderSceneIdButton: TButton
    Left = 288
    Top = 42
    Width = 75
    Height = 20
    Caption = 'OK'
    TabOrder = 8
    Visible = False
  end
  object GetProgDataEdit1: TEdit
    Left = 58
    Top = 103
    Width = 101
    Height = 21
    TabOrder = 9
    Visible = False
  end
  object GetProgDataEdit2: TEdit
    Left = 58
    Top = 130
    Width = 101
    Height = 21
    TabOrder = 10
    Visible = False
  end
  object GetProgDataEdit3: TEdit
    Left = 58
    Top = 157
    Width = 101
    Height = 21
    TabOrder = 11
    Visible = False
  end
  object GetDataMemo: TMemo
    Left = 0
    Top = 208
    Width = 363
    Height = 113
    Lines.Strings = (
      'GetDataMemo')
    TabOrder = 12
    Visible = False
  end
end
