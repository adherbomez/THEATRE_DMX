﻿object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 812
  ClientWidth = 1128
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 728
    Top = 8
    Width = 297
    Height = 247
    Caption = 'Module de test 2'
    Color = clMoneyGreen
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label3: TLabel
      Left = 78
      Top = 157
      Width = 61
      Height = 13
      Caption = 'Etat Serveur'
    end
    object Label4: TLabel
      Left = 96
      Top = 168
      Width = 3
      Height = 13
    end
    object Label5: TLabel
      Left = 145
      Top = 157
      Width = 72
      Height = 13
      Caption = 'Message Client'
    end
    object Label6: TLabel
      Left = 128
      Top = 104
      Width = 42
      Height = 13
      Caption = 'Serveur:'
    end
    object Shape3: TShape
      Left = 96
      Top = 187
      Width = 43
      Height = 38
      Brush.Color = clRed
    end
    object Shape4: TShape
      Left = 160
      Top = 187
      Width = 43
      Height = 38
      Brush.Color = clRed
    end
    object Label17: TLabel
      Left = 48
      Top = 40
      Width = 27
      Height = 13
      Caption = 'Port :'
    end
    object Label16: TLabel
      Left = 120
      Top = 67
      Width = 68
      Height = 13
      Caption = 'erreur de port'
      Visible = False
    end
    object Button1: TButton
      Left = 112
      Top = 123
      Width = 75
      Height = 25
      Caption = 'Connexion'
      TabOrder = 0
      OnClick = Button1Click
    end
    object ComboBox1: TComboBox
      Left = -776
      Top = 16
      Width = 145
      Height = 21
      TabOrder = 1
      Text = 'ComboBox1'
    end
    object edtPort: TEdit
      Left = 89
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit1: TEdit
      Left = 89
      Top = 86
      Width = 121
      Height = 21
      TabOrder = 3
    end
  end
  object GroupBox1: TGroupBox
    Left = 993
    Top = 351
    Width = 112
    Height = 22
    Caption = 'Module de test 1'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 1
  end
  object gbEqp: TGroupBox
    Left = 66
    Top = 30
    Width = 607
    Height = 532
    Caption = 'Equipement'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 2
    object Label12: TLabel
      Left = 24
      Top = 46
      Width = 25
      Height = 13
      Caption = 'Nom:'
    end
    object lblNbCan: TLabel
      Left = 23
      Top = 193
      Width = 122
      Height = 13
      Caption = 'Nombre de propri'#233't'#233'e(s):'
    end
    object lblProp: TLabel
      Left = 298
      Top = 8
      Width = 107
      Height = 13
      Caption = 'Valeur de la propri'#233't'#233':'
      Visible = False
    end
    object lblEqpValide: TLabel
      Left = 304
      Top = 442
      Width = 96
      Height = 13
      Caption = 'Valid'#233' l'#39#233'quipement?'
      Visible = False
    end
    object Intensité: TLabel
      Left = 305
      Top = 341
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 6'
    end
    object Label1: TLabel
      Left = 42
      Top = 450
      Width = 44
      Height = 13
      Caption = 'Etat DLL:'
    end
    object Label10: TLabel
      Left = 305
      Top = 220
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 4'
    end
    object Label11: TLabel
      Left = 305
      Top = 277
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 5'
    end
    object Label2: TLabel
      Left = 92
      Top = 450
      Width = 46
      Height = 13
      Caption = 'Etat USB:'
    end
    object Label7: TLabel
      Left = 303
      Top = 27
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 1'
    end
    object Label8: TLabel
      Left = 304
      Top = 94
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 2'
    end
    object Label9: TLabel
      Left = 305
      Top = 153
      Width = 53
      Height = 13
      Caption = 'Propri'#233't'#233' 3'
    end
    object Shape1: TShape
      Left = 42
      Top = 468
      Width = 44
      Height = 38
      Brush.Color = clRed
    end
    object Shape2: TShape
      Left = 92
      Top = 469
      Width = 44
      Height = 37
      Brush.Color = clRed
    end
    object lblAdr: TLabel
      Left = 24
      Top = 112
      Width = 39
      Height = 13
      Caption = 'Adresse'
    end
    object edtNameEqp: TEdit
      Left = 24
      Top = 71
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object edtNbCan: TEdit
      Left = 24
      Top = 212
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object btnValideEqp: TButton
      Left = 42
      Top = 270
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 2
      OnClick = btnValideEqpClick
    end
    object btnPropEqp: TButton
      Left = 307
      Top = 411
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 3
      Visible = False
      OnClick = btnPropEqpClick
    end
    object btnOkEqp: TButton
      Left = 298
      Top = 482
      Width = 75
      Height = 25
      Caption = 'Oui'
      TabOrder = 4
      Visible = False
      OnClick = btnOkEqpClick
    end
    object btnNokEqp: TButton
      Left = 386
      Top = 482
      Width = 75
      Height = 25
      Caption = 'Non'
      TabOrder = 5
      Visible = False
      OnClick = btnNokEqpClick
    end
    object bar1: TTrackBar
      Left = 298
      Top = 71
      Width = 150
      Height = 17
      Max = 255
      TabOrder = 6
    end
    object bar2: TTrackBar
      Left = 298
      Top = 130
      Width = 150
      Height = 23
      Max = 255
      TabOrder = 7
    end
    object bar3: TTrackBar
      Left = 298
      Top = 197
      Width = 150
      Height = 23
      Max = 255
      TabOrder = 8
    end
    object bar4: TTrackBar
      Left = 298
      Top = 254
      Width = 150
      Height = 17
      Max = 255
      TabOrder = 9
    end
    object bar5: TTrackBar
      Left = 298
      Top = 319
      Width = 150
      Height = 16
      Max = 255
      TabOrder = 10
    end
    object bar6: TTrackBar
      Left = 298
      Top = 383
      Width = 150
      Height = 22
      Max = 255
      TabOrder = 11
    end
    object edtAdr: TEdit
      Left = 24
      Top = 131
      Width = 121
      Height = 21
      TabOrder = 12
    end
  end
  object gpSeq: TGroupBox
    Left = 1010
    Top = 417
    Width = 68
    Height = 24
    Caption = 'S'#233'quence'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 3
    Visible = False
    OnClick = gpSeqClick
    object lblNomSeq: TLabel
      Left = 16
      Top = 37
      Width = 25
      Height = 13
      Caption = 'Nom:'
    end
    object Label14: TLabel
      Left = 16
      Top = 70
      Width = 236
      Height = 13
      Caption = 'Choisissez les '#233'quipements dans l'#39'ordre souhait'#233':'
    end
    object Button2: TButton
      Left = 168
      Top = 263
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 0
    end
    object edtNomSeq: TEdit
      Left = 136
      Top = 31
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object lbSeq: TListBox
      Left = 16
      Top = 101
      Width = 161
      Height = 124
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 2
    end
    object lb2Seq: TListBox
      Left = 222
      Top = 101
      Width = 169
      Height = 124
      ItemHeight = 13
      TabOrder = 3
    end
    object btnSeqAdd: TButton
      Left = 183
      Top = 136
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      OnClick = btnSeqAddClick
    end
    object btnConflict: TButton
      Left = 160
      Top = 232
      Width = 89
      Height = 25
      Caption = 'Test de conflits'
      TabOrder = 5
    end
    object btnSeqSupp: TButton
      Left = 183
      Top = 167
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 6
      OnClick = btnSeqSuppClick
    end
  end
  object gpScene: TGroupBox
    Left = 1010
    Top = 390
    Width = 63
    Height = 21
    Caption = 'Sc'#232'ne'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 4
    Visible = False
    OnClick = gpSceneClick
    object lblNomScene: TLabel
      Left = 184
      Top = 43
      Width = 25
      Height = 13
      Caption = 'Nom:'
    end
    object Label15: TLabel
      Left = 25
      Top = 90
      Width = 226
      Height = 13
      Caption = 'Choisissez les s'#233'quences dans l'#39'ordre souhait'#233':'
    end
    object edtNomScene: TEdit
      Left = 184
      Top = 62
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object btnValideScene: TButton
      Left = 200
      Top = 271
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 1
    end
    object btnScnAdd: TButton
      Left = 209
      Top = 128
      Width = 35
      Height = 25
      Caption = '>>'
      TabOrder = 2
      OnClick = btnScnAddClick
    end
    object btnScnSupp: TButton
      Left = 209
      Top = 168
      Width = 35
      Height = 25
      Caption = '<<'
      TabOrder = 3
      OnClick = btnScnSuppClick
    end
    object lbScene: TListBox
      Left = 25
      Top = 109
      Width = 153
      Height = 125
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 4
    end
    object lb2Scene: TListBox
      Left = 270
      Top = 103
      Width = 153
      Height = 125
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 5
    end
  end
  object GroupBox4: TGroupBox
    Left = 686
    Top = 323
    Width = 365
    Height = 220
    Caption = 'Adressage'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 5
    Visible = False
    OnClick = GroupBox4Click
    object lblAjoutSucc: TLabel
      Left = 237
      Top = 172
      Width = 156
      Height = 13
      Caption = 'Adressage effectu'#233' avec succ'#232's'
      Visible = False
    end
    object btnAdr: TButton
      Left = 280
      Top = 128
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 0
      OnClick = btnAdrClick
    end
    object lbAdressage: TListBox
      Left = 24
      Top = 79
      Width = 153
      Height = 125
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 1
    end
  end
  object Button6: TButton
    Left = 774
    Top = 537
    Width = 75
    Height = 25
    Caption = 'IHM ARMEL'
    TabOrder = 6
    OnClick = Button6Click
  end
  object btnLancerSimulation: TButton
    Left = 832
    Top = 296
    Width = 145
    Height = 25
    Caption = 'Lancer La Simulation'
    TabOrder = 7
    OnClick = btnLancerSimulationClick
  end
  object Edit2: TEdit
    Left = 371
    Top = 390
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 371
    Top = 326
    Width = 121
    Height = 21
    TabOrder = 9
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 371
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 10
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 369
    Top = 202
    Width = 121
    Height = 21
    TabOrder = 11
    Text = 'Edit5'
  end
  object Edit6: TEdit
    Left = 369
    Top = 143
    Width = 121
    Height = 21
    TabOrder = 12
    Text = 'Edit6'
  end
  object Edit7: TEdit
    Left = 369
    Top = 76
    Width = 121
    Height = 21
    TabOrder = 13
    Text = 'Edit7'
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 23
    OnTimer = Timer1Timer
    Left = 8
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 32
    object Nouveau1: TMenuItem
      Caption = 'Ajouter'
      object menuScn: TMenuItem
        Caption = 'Sc'#232'ne'
      end
      object menuSeq: TMenuItem
        Caption = 'S'#233'quence'
      end
      object menuEqp: TMenuItem
        Caption = 'Equipement'
        OnClick = menuEqpClick
      end
    end
  end
end
