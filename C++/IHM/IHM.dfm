object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 507
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 44
    Height = 13
    Caption = 'Etat DLL:'
  end
  object Shape1: TShape
    Left = 24
    Top = 35
    Width = 44
    Height = 38
    Brush.Color = clRed
  end
  object Label2: TLabel
    Left = 24
    Top = 79
    Width = 46
    Height = 13
    Caption = 'Etat USB:'
  end
  object Shape2: TShape
    Left = 24
    Top = 98
    Width = 44
    Height = 41
    Brush.Color = clRed
  end
  object Edit1: TEdit
    Left = 200
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 152
    Top = 264
  end
end
