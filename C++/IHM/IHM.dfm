﻿object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 804
  ClientWidth = 1115
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 1009
    Top = 28
    Width = 98
    Height = 16
    Caption = 'Module de test 2'
    Color = clMoneyGreen
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label3: TLabel
      Left = 78
      Top = 93
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
      Top = 93
      Width = 72
      Height = 13
      Caption = 'Message Client'
    end
    object Label6: TLabel
      Left = 128
      Top = 40
      Width = 42
      Height = 13
      Caption = 'Serveur:'
    end
    object Shape3: TShape
      Left = 96
      Top = 112
      Width = 43
      Height = 38
      Brush.Color = clRed
    end
    object Shape4: TShape
      Left = 160
      Top = 112
      Width = 43
      Height = 38
      Brush.Color = clRed
    end
    object Button1: TButton
      Left = 112
      Top = 59
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
  end
  object GroupBox1: TGroupBox
    Left = 1009
    Top = 8
    Width = 98
    Height = 14
    Caption = 'Module de test 1'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 1
    object Label7: TLabel
      Left = 8
      Top = 16
      Width = 60
      Height = 13
      Caption = 'Stroboscope'
    end
    object Label8: TLabel
      Left = 8
      Top = 64
      Width = 31
      Height = 13
      Caption = 'Rouge'
    end
    object Label9: TLabel
      Left = 10
      Top = 114
      Width = 20
      Height = 13
      Caption = 'Vert'
    end
    object Label10: TLabel
      Left = 10
      Top = 157
      Width = 20
      Height = 13
      Caption = 'Bleu'
    end
    object Label11: TLabel
      Left = 12
      Top = 202
      Width = 25
      Height = 13
      Caption = 'Blanc'
    end
    object Intensité: TLabel
      Left = 8
      Top = 240
      Width = 43
      Height = 13
      Caption = 'Intensit'#233
    end
    object Label1: TLabel
      Left = 279
      Top = 172
      Width = 44
      Height = 13
      Caption = 'Etat DLL:'
    end
    object Label2: TLabel
      Left = 329
      Top = 172
      Width = 46
      Height = 13
      Caption = 'Etat USB:'
    end
    object Shape1: TShape
      Left = 279
      Top = 190
      Width = 44
      Height = 38
      Brush.Color = clRed
    end
    object Shape2: TShape
      Left = 329
      Top = 191
      Width = 44
      Height = 37
      Brush.Color = clRed
    end
    object bar1: TTrackBar
      Left = 3
      Top = 40
      Width = 150
      Height = 17
      Max = 255
      TabOrder = 0
    end
    object bar2: TTrackBar
      Left = 3
      Top = 85
      Width = 150
      Height = 23
      Max = 255
      TabOrder = 1
    end
    object bar3: TTrackBar
      Left = 3
      Top = 133
      Width = 150
      Height = 23
      Max = 255
      TabOrder = 2
    end
    object bar5: TTrackBar
      Left = 3
      Top = 221
      Width = 150
      Height = 16
      Max = 255
      TabOrder = 3
    end
    object bar6: TTrackBar
      Left = 3
      Top = 259
      Width = 150
      Height = 22
      Max = 255
      TabOrder = 4
    end
    object bar4: TTrackBar
      Left = 3
      Top = 176
      Width = 150
      Height = 17
      Max = 255
      TabOrder = 5
    end
  end
  object gbEqp: TGroupBox
    Left = 96
    Top = 8
    Width = 489
    Height = 315
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
      Left = 24
      Top = 133
      Width = 122
      Height = 13
      Caption = 'Nombre de propri'#233't'#233'e(s):'
    end
    object lblProp: TLabel
      Left = 298
      Top = 43
      Width = 107
      Height = 13
      Caption = 'Valeur de la propri'#233't'#233':'
      Visible = False
    end
    object lblEqpValide: TLabel
      Left = 304
      Top = 224
      Width = 96
      Height = 13
      Caption = 'Valid'#233' l'#39#233'quipement?'
      Visible = False
    end
    object edtNameEqp: TEdit
      Left = 24
      Top = 71
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object edtNbCan: TEdit
      Left = 23
      Top = 152
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object btnValideEqp: TButton
      Left = 48
      Top = 219
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 2
      OnClick = btnValideEqpClick
    end
    object edtProp: TEdit
      Left = 298
      Top = 71
      Width = 121
      Height = 21
      TabOrder = 3
      Visible = False
    end
    object btnPropEqp: TButton
      Left = 298
      Top = 107
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 4
      Visible = False
      OnClick = btnPropEqpClick
    end
    object btnOkEqp: TButton
      Left = 298
      Top = 264
      Width = 75
      Height = 25
      Caption = 'Oui'
      TabOrder = 5
      Visible = False
      OnClick = btnOkEqpClick
    end
    object btnNokEqp: TButton
      Left = 386
      Top = 264
      Width = 75
      Height = 25
      Caption = 'Non'
      TabOrder = 6
      Visible = False
      OnClick = btnNokEqpClick
    end
  end
  object gpSeq: TGroupBox
    Left = 599
    Top = 329
    Width = 410
    Height = 302
    Caption = 'S'#233'quence'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 3
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
      Top = 102
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
      Top = 133
      Width = 161
      Height = 124
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 2
      OnClick = lbSeqClick
    end
    object lb2Seq: TListBox
      Left = 222
      Top = 133
      Width = 169
      Height = 124
      ItemHeight = 13
      TabOrder = 3
    end
    object Button3: TButton
      Left = 183
      Top = 136
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      OnClick = Button3Click
    end
  end
  object gpScene: TGroupBox
    Left = 96
    Top = 329
    Width = 489
    Height = 302
    Caption = 'Sc'#232'ne'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 4
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
    object lbScene: TListBox
      Left = 40
      Top = 117
      Width = 153
      Height = 132
      ItemHeight = 13
      TabOrder = 1
      OnClick = lbSceneClick
    end
    object lb2Scene: TListBox
      Left = 267
      Top = 117
      Width = 161
      Height = 132
      ItemHeight = 13
      TabOrder = 2
      OnClick = lb2SceneClick
    end
    object btnValideScene: TButton
      Left = 200
      Top = 271
      Width = 75
      Height = 25
      Caption = 'Valid'#233
      TabOrder = 3
    end
  end
  object Button4: TButton
    Left = 782
    Top = 385
    Width = 33
    Height = 25
    Caption = '<<'
    TabOrder = 5
    OnClick = Button4Click
  end
  object GroupBox4: TGroupBox
    Left = 599
    Top = 8
    Width = 407
    Height = 315
    Caption = 'Adressage'
    Color = clCream
    ParentBackground = False
    ParentColor = False
    TabOrder = 6
    object Label13: TLabel
      Left = 289
      Top = 60
      Width = 46
      Height = 13
      Caption = 'Adresse: '
    end
    object edtAdr: TEdit
      Left = 266
      Top = 87
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Button5: TButton
      Left = 280
      Top = 114
      Width = 75
      Height = 25
      Caption = 'Button5'
      TabOrder = 1
    end
    object lbAdressage: TListBox
      Left = 24
      Top = 79
      Width = 153
      Height = 125
      ItemHeight = 13
      TabOrder = 2
    end
  end
  object Timer1: TTimer
    Interval = 23
    OnTimer = Timer1Timer
    Left = 8
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 32
    object Nouveau1: TMenuItem
      Caption = 'Nouveau'
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
