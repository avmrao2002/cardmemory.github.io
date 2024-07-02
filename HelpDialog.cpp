// HelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog dialog


CHelpDialog::CHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDialog)
	m_edit_string = _T("This is a solitaire game in cards and it is one type of memory test  game. Player has to remember the clicked cards. When clicked on a card and if any of the clicked card matches then click on the card to pair. Player has to make as many pair of cards with less fails and within short time. A pair can be made with any card of same symbol. For example Flower A can be paired to Flower A, Heart A, Diamond A or Spade A. ");
	//}}AFX_DATA_INIT
}


void CHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDialog)
	DDX_Text(pDX, IDC_EDIT1, m_edit_string);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDialog, CDialog)
	//{{AFX_MSG_MAP(CHelpDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog message handlers

BOOL CHelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
