// HelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
	m_help_string = _T("");
	//}}AFX_DATA_INIT
	m_count = 0;
	m_HelpString ="NetRummy is a basic rummy game in card games. Using this software, Rummy game can be played over LAN, intranet using TCP/IP between two players.\r\n"
		"The deck consists of  52 cards with 4 suites, Diamond, Flower, Heart and Spade. Each suit consists from low to high \r\n\r\n\"Ace 2 3 4 5 6 7 8 9 10 Jack Queen King\"\r\n\r\n"
		"The first dealer is chosen by server or by toss when connected to server. Each player play with 13 cards and one card will be placed open in the screen and other cards are kept aside. "
		"Each player can take open card or in the pile of cards and will discard one card in the screen. To discard, right click on the desired card or drag the card to discard place.  The other player follows the same.\r\n"
		"The objective of the game is to dispose of all the cards in your hand with proper sequence or group. There are three ways to get rid of cards: melding, and discarding. "
		"Melding is taking a combination of cards from your side, There are two kinds of combination which can be melded: sequences (also known as runs) and groups (also known as sets or books). " 
		"A sequence  run consists of three or more cards of the same suit in consecutive order, such as 4, 5, 6 or 8, 9, 10, J. "
		"A group, set or book is three or four cards of the same rank, such as 7(Diamond), 7(Flower), 7(Spade). " 		 
		 "Discarding is playing a card from your side on screen. When it is your turn to move, if you touch the discard, then you should play with that card only. If you double click on on the pile of cards, then you should play with that card one. You get rid of one card this way at the end of each turn by adding a card either from pile or from the card on the screen. At any point of time 13 cards should be in your side. "
		"To show the game, you should have atleast two sequences with minimum of three cards in each sequence like 2(diamond),3(diamond),4(flower) and 10(flower),J(flower),Q(flower).\r\n"
		"Ace can be plaed either before 2 or after K(king)\r\nExample sequence is\r\n\r\n"
		"A(D), 2(D), 3(D), 7(F), 8(F), 9(F), 10(D),10(F), 10(H), 10(S), 4(D),4(F), 4(S).\r\n\r\nWhen all the sequences are set, keep the discard a right side and then send show message. The discard card will not be shown to other player\r\n"
		"The game board is divided into found parts. The upper part will be used for keeping player's 13 cards. "
		"In the middle part, first closed card will consists of pile of cards and second closed card consists of discarded card. "
		"The last part will be used to display the opponent's cards when show message is sent. This software can be used for playing Rummy as server or client.\r\n"
		"To play as server, enter the Server port number by clicking Tools->Server menu option.\r\n"
		"To connect to the server, enter server ip and port number by clicking Tools->Client menu option.\r\n"
		"Once the connection is established, mouse can be used to shuffle the cards .\r\n"
		"The current game can be saved with history. "
		"To discard a card, right click on the card, it will be placed in discard place and it will be reflected on "
		"client/server side also. To open a card in the pile of cards, double click on it, it will be kept in discarded place\r\n"

		"Other features are:-----\r\n\r\n"
		"\"Edit->Option\" can be used to to change the background color.\r\n"
		"\"Edit->Propertis\" will display the current status of the game.\r\n"		 
		"\"Tools->SendMessage\" can be used to send instant message to the other player.\r\n"
		"\"Tools->Disconnect\" disconnects from the network.\r\n"	
		"\"Tools->Drop\" sends a drop message, count 80 will be added to total\r\n"
		"\"Tools->Show\" sends a show message to the other player\r\n"
		"\"View->History\" will display the history of each player score.\r\n"
		"\"View->Hide\" will hide the current board and an icon will be placed in the system tray.\r\n"
		"\"File->New\" will be used to start new game\r\n\r\n"
		

		"On clicking on toggling icon in system tray, the hidden board will be displayed\r\n\r\n"		 
		"Whenever there is a move, a message or any other action, an icon will be toggled in the system tray. "
		"On clicking on icon in system tray, the hidden game will be displayed.\r\n\r\n"
		"This software is aimed at for playing Rummy game between two players over network.\r\n"
		"No intelligence is implemented with this software.\r\n"
		"Any queries or comments send mail to raoavm@yahoo.com\r\n"
		"No warranty or guarantee is available with this software\r\n"
		"This software is free to use or distribute. \r\nPlease visit  http://www.geocities.com/raoavm/index.html\r\n\r\nEnjoy the game!!!";  
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
	DDX_Text(pDX, IDC_EDIT_STRING, m_help_string);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg message handlers

/*void CHelpDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	if(m_count <4)
	{
		m_count++;
		m_helpString = m_HelpString[m_count];	
		UpdateData(FALSE);
	}
}

void CHelpDlg::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	if(m_count > 0)
	{
		m_count--;
		m_helpString = m_HelpString[m_count];	
		UpdateData(FALSE);
	}	
}*/

BOOL CHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_help_string = m_HelpString;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
