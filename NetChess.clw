; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetChess.h"
LastPage=0

ClassCount=20
Class1=CNetChessApp
Class2=CNetChessDoc
Class3=CNetChessView
Class4=CMainFrame

ResourceCount=7
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CServerSocket
Class7=CClientSocket
Resource2=IDR_SHELL_MENU
Class8=COptions
Resource3=IDD_DIALOG_PICK_PIECE
Class9=CServerInfoDlg
Resource4=IDD_DIALOG_LOST_PIECE
Class10=CMessageSend
Resource5=IDD_DIALOG_DEMO_FEED
Class11=CHistoryDlg
Class12=CMyColorDialog
Class13=CPickPieceDlg
Class14=CPropertiesDlg
Class15=CAcceptDlg
Class16=CLostPieceDlg
Class17=CDemo
Class18=CHelpDlg
Class19=CCardCountDlg
Resource6=IDD_ABOUTBOX
Class20=CHelpDialog
Resource7=IDD_DIALOG_HELP1

[CLS:CNetChessApp]
Type=0
HeaderFile=NetChess.h
ImplementationFile=NetChess.cpp
Filter=N
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CNetChessDoc]
Type=0
HeaderFile=NetChessDoc.h
ImplementationFile=NetChessDoc.cpp
Filter=N

[CLS:CNetChessView]
Type=0
HeaderFile=NetChessView.h
ImplementationFile=NetChessView.cpp
Filter=C
LastObject=ID_APP_EXIT
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=AFX_ID_PREVIEW_CLOSE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=NetChess.cpp
ImplementationFile=NetChess.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_VIEW_HIDE
Command4=ID_APP_ABOUT
Command5=ID_HELP_HOWTOPLAY
CommandCount=5

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_TOOLS_CLIENT
Command2=ID_TOOLS_DISCONNECT
Command3=ID_TOOLS_SERVER
Command4=ID_EDIT_MOVEFIRST
Command5=ID_FILE_FEED
Command6=ID_VIEW_HIDE
Command7=ID_VIEW_HISTORY
Command8=ID_VIEW_LOSTPIECES
Command9=ID_TOOLS_LEARN
Command10=ID_TOOLS_SENDMESSAGE
Command11=ID_FILE_NEW
Command12=ID_EDIT_OPTIONS
Command13=D_EDIT_PROPERTIES
Command14=ID_TOOLS_RESIGN
Command15=ID_FILE_SAVE
Command16=ID_TOOLS_SHOW
Command17=ID_EDIT_MOVELAST
Command18=ID_EDIT_UNDO
Command19=ID_EDIT_CUT
Command20=ID_NEXT_PANE
Command21=ID_PREV_PANE
Command22=ID_EDIT_COPY
Command23=ID_EDIT_PASTE
Command24=ID_TOOLS_WHITEONTOP
Command25=ID_EDIT_CUT
Command26=ID_EDIT_REDO
Command27=ID_EDIT_UNDO
CommandCount=27

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_VIEW_HIDE
Command3=ID_APP_ABOUT
Command4=AFX_ID_PREVIEW_CLOSE
Command5=AFX_ID_PREVIEW_CLOSE
Command6=AFX_ID_PREVIEW_CLOSE
Command7=AFX_ID_PREVIEW_CLOSE
Command8=AFX_ID_PREVIEW_CLOSE
Command9=AFX_ID_PREVIEW_CLOSE
Command10=AFX_ID_PREVIEW_CLOSE
Command11=AFX_ID_PREVIEW_CLOSE
Command12=AFX_ID_PREVIEW_CLOSE
Command13=AFX_ID_PREVIEW_CLOSE
Command14=AFX_ID_PREVIEW_CLOSE
Command15=AFX_ID_PREVIEW_CLOSE
Command16=AFX_ID_PREVIEW_CLOSE
Command17=AFX_ID_PREVIEW_CLOSE
Command18=AFX_ID_PREVIEW_CLOSE
Command19=AFX_ID_PREVIEW_CLOSE
CommandCount=19

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=q

[CLS:COptions]
Type=0
HeaderFile=Options.h
ImplementationFile=Options.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[CLS:CServerInfoDlg]
Type=0
HeaderFile=ServerInfoDlg.h
ImplementationFile=ServerInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:CMessageSend]
Type=0
HeaderFile=MessageSend.h
ImplementationFile=MessageSend.cpp
BaseClass=CDialog
Filter=D
LastObject=CMessageSend
VirtualFilter=dWC

[CLS:CHistoryDlg]
Type=0
HeaderFile=HistoryDlg.h
ImplementationFile=HistoryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHistoryDlg

[CLS:CMyColorDialog]
Type=0
HeaderFile=MyColorDialog.h
ImplementationFile=MyColorDialog.cpp
BaseClass=CColorDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyColorDialog

[DLG:IDD_DIALOG_PICK_PIECE]
Type=1
Class=CPickPieceDlg
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_ROOT_WHITE,static,1484787982
Control4=IDC_STATIC_BITMAP_KNIGHT,static,1484787982
Control5=IDC_STATIC_BISHOP_WHITE,static,1484787982
Control6=IDC_STATIC_QUEEN_WHITE,static,1484787982
Control7=IDC_STATIC_ROOT_BLACK,static,1484787982
Control8=IDC_STATIC_KNIGHT_BLACK,static,1484787982
Control9=IDC_STATIC_BISHOP_BLACK,static,1484787982
Control10=IDC_STATIC_QUEEN_BLACK,static,1484787982
Control11=IDC_STATIC_KING_WHITE,static,1484787982
Control12=IDC_STATIC_PAWN_WHITE,static,1484787982
Control13=IDC_STATIC_KING_BLACK,static,1484787982
Control14=IDC_STATIC_PAWN_BLACK,static,1484787982
Control15=IDC_STATIC_STATUS,static,1342308352
Control16=IDC_STATIC_EMPTY,static,1476399367

[CLS:CPickPieceDlg]
Type=0
HeaderFile=PickPieceDlg.h
ImplementationFile=PickPieceDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPickPieceDlg
VirtualFilter=dWC

[MNU:IDR_SHELL_MENU]
Type=1
Class=?
Command1=ID_SHELL_CLOSE
Command2=ID_SHELL_VIEW
CommandCount=2

[CLS:CPropertiesDlg]
Type=0
HeaderFile=PropertiesDlg.h
ImplementationFile=PropertiesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CAcceptDlg]
Type=0
HeaderFile=AcceptDlg.h
ImplementationFile=AcceptDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[DLG:IDD_DIALOG_LOST_PIECE]
Type=1
Class=CLostPieceDlg
ControlCount=35
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_W1,static,1342177294
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_W2,static,1342177294
Control6=IDC_STATIC_W3,static,1342177294
Control7=IDC_STATIC_W4,static,1342177294
Control8=IDC_STATIC_W5,static,1342177294
Control9=IDC_STATIC_W6,static,1342177294
Control10=IDC_STATIC_W7,static,1342177294
Control11=IDC_STATIC_W8,static,1342177294
Control12=IDC_STATIC_W9,static,1342177294
Control13=IDC_STATIC_W10,static,1342177294
Control14=IDC_STATIC_W11,static,1342177294
Control15=IDC_STATIC_W12,static,1342177294
Control16=IDC_STATIC_W13,static,1342177294
Control17=IDC_STATIC_W14,static,1342177294
Control18=IDC_STATIC_W15,static,1342177294
Control19=IDC_STATIC_W16,static,1342177294
Control20=IDC_STATIC_B1,static,1342177294
Control21=IDC_STATIC_B2,static,1342177294
Control22=IDC_STATIC_B3,static,1342177294
Control23=IDC_STATIC_B4,static,1342177294
Control24=IDC_STATIC_B5,static,1342177294
Control25=IDC_STATIC_B6,static,1342177294
Control26=IDC_STATIC_B7,static,1342177294
Control27=IDC_STATIC_B8,static,1342177294
Control28=IDC_STATIC_B9,static,1342177294
Control29=IDC_STATIC_B10,static,1342177294
Control30=IDC_STATIC_B11,static,1342177294
Control31=IDC_STATIC_B12,static,1342177294
Control32=IDC_STATIC_B13,static,1342177294
Control33=IDC_STATIC_B14,static,1342177294
Control34=IDC_STATIC_B15,static,1342177294
Control35=IDC_STATIC_B16,static,1342177294

[CLS:CLostPieceDlg]
Type=0
HeaderFile=LostPieceDlg.h
ImplementationFile=LostPieceDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[DLG:IDD_DIALOG_DEMO_FEED]
Type=1
Class=CDemo
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_COMBO_FROM_LETTER,combobox,1344340227
Control3=IDC_COMBO_FROM_NUMBER,combobox,1344340226
Control4=IDC_COMBO_TO_LETTER,combobox,1344340226
Control5=IDC_COMBO_TO_NUMBER,combobox,1344340226
Control6=IDC_STATIC,button,1342308359
Control7=IDC_STATIC,button,1342177287
Control8=IDC_BUTTON_ADD,button,1342242816

[CLS:CDemo]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[CLS:CCardCountDlg]
Type=0
HeaderFile=CardCountDlg.h
ImplementationFile=CardCountDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_COUNT

[CLS:CHelpDialog]
Type=0
HeaderFile=HelpDialog.h
ImplementationFile=HelpDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[DLG:IDD_DIALOG_HELP1]
Type=1
Class=CHelpDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1352730692

