// NetChessView.cpp : implementation of the CNetChessView class
//

#include "stdafx.h"
#include "NetChess.h"
#include "ChessBoard.h"
#include "MainFrm.h"

#include "NetChessDoc.h"
#include "NetChessView.h"
#include "HelpDialog.h"
 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int card_pairs[13][4] = {
	{IDB_BITMAP_DIAMOND_A,IDB_BITMAP_FLOWER_A,IDB_BITMAP_HEART_A,IDB_BITMAP_SPADE_A},
	{IDB_BITMAP_DIAMOND_2,IDB_BITMAP_FLOWER_2,IDB_BITMAP_HEART_2,IDB_BITMAP_SPADE_2},
	{IDB_BITMAP_DIAMOND_3,IDB_BITMAP_FLOWER_3,IDB_BITMAP_HEART_3,IDB_BITMAP_SPADE_3},
	{IDB_BITMAP_DIAMOND_4,IDB_BITMAP_FLOWER_4,IDB_BITMAP_HEART_4,IDB_BITMAP_SPADE_4},
	{IDB_BITMAP_DIAMOND_5,IDB_BITMAP_FLOWER_5,IDB_BITMAP_HEART_5,IDB_BITMAP_SPADE_5},
	{IDB_BITMAP_DIAMOND_6,IDB_BITMAP_FLOWER_6,IDB_BITMAP_HEART_6,IDB_BITMAP_SPADE_6},
	{IDB_BITMAP_DIAMOND_7,IDB_BITMAP_FLOWER_7,IDB_BITMAP_HEART_7,IDB_BITMAP_SPADE_7},
	{IDB_BITMAP_DIAMOND_8,IDB_BITMAP_FLOWER_8,IDB_BITMAP_HEART_8,IDB_BITMAP_SPADE_8},
	{IDB_BITMAP_DIAMOND_9,IDB_BITMAP_FLOWER_9,IDB_BITMAP_HEART_9,IDB_BITMAP_SPADE_9},
	{IDB_BITMAP_DIAMOND_10,IDB_BITMAP_FLOWER_10,IDB_BITMAP_HEART_10,IDB_BITMAP_SPADE_10},	
	{IDB_BITMAP_DIAMOND_J,IDB_BITMAP_FLOWER_J,IDB_BITMAP_HEART_J,IDB_BITMAP_SPADE_J},
	{IDB_BITMAP_DIAMOND_Q,IDB_BITMAP_FLOWER_Q,IDB_BITMAP_HEART_Q,IDB_BITMAP_SPADE_Q},
	{IDB_BITMAP_DIAMOND_K,IDB_BITMAP_FLOWER_K,IDB_BITMAP_HEART_K,IDB_BITMAP_SPADE_K}
};
 
/////////////////////////////////////////////////////////////////////////////
// CNetChessView
void writeMessage(char *str,...);
IMPLEMENT_DYNCREATE(CNetChessView, CView)

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	//{{AFX_MSG_MAP(CNetChessView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()	 
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
//	ON_MESSAGE(ID_MY_MESSAGE_COLORDATA,OnMessageColorData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessView construction/destruction

CNetChessView::CNetChessView()
{
	// TODO: add construction code here
	m_mouseMoveFlag = false;
	m_player_turn = false;
	m_timerFlag = false;
	m_squareWidth = 50;
	m_squareHeight = 60;
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);
	m_point.x = m_point.y = m_backuppoint.x = m_backuppoint.y = -1;
	m_pairCount = 0;
	m_pairFailCount = 0;
	writeMessage("constructor");
}

CNetChessView::~CNetChessView()
{
}

int checkExisting(int n, int *arr, int rand)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == rand)
			return 1;
	}
	return 0;
}

int getExisting(int n,int* arr, int* data)
{	 
	int foundFlag = 0; 	 	 
	for(int i=0;i<n;i++)
	{		 
		if(data[i] == 0) continue;
 		for(int j =0;j<n;j++)
		{
 			if(arr[j]==0)
			{
			 			 
				return data[i];
			}
				
			if(arr[j] == data[i])
			{				 
				foundFlag = 1;
				break;
			}
		}
		if(foundFlag == 0)
		{	 			 
			return data[i];
		}
	}
 	return -1;
}
void getRandom(int num,int arr[100])
{
	int i=0;
	srand( (unsigned)time( NULL ) );
	int data[100];
	for(int i=0;i<100;i++)
	{
		data[i] = i+1;
	}

	for(i=0;i<100;i++)
	{
		arr[i]=0;
	}
	int trycount = 0;
	for(i=0;i<num;i++)
	{
			 
			int rnd = (rand() % ((num)+1));
 			if( rnd == 0 || checkExisting(num,arr,rnd) == 1)
			{//try once again
				if(trycount==1000)
				{
					int retdata = getExisting(num,arr,data);
					if(retdata < 0)
					{
						return;
					}
					else
					{
						trycount = 0;
						arr[i] = retdata;
					}
				}
				else
				{
					trycount++;
					i--;
				}
				 
			}
			else
			{
				trycount=0;
				arr[i] = rnd;
			}
	} 
}


BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView drawing

void CNetChessView::OnDraw(CDC* pDC)
{
	CNetChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawBoard(); 
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView printing

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView diagnostics

#ifdef _DEBUG
void CNetChessView::AssertValid() const
{
	CView::AssertValid();
}

void CNetChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNetChessDoc* CNetChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetChessDoc)));
	return (CNetChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessView message handlers


void CNetChessView::DrawBoard()
{
	CClientDC dc(this);
	CBitmap localbmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	//BITMAP bp={0,1000,510,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);

	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	ldc.SelectObject(&localbmp); 
	COLORREF cr(RGB(20,140,17));	 	 
	CBrush brush(cr);
	ldc.SelectObject(brush);
	CRect crect;
	GetClientRect(&crect);
	writeMessage("in drwaboard");	 
 
	ldc.FillRect(&crect,&brush);
	COLORREF redcr(RGB(255,0,0));

	CBrush redbrush;
	redbrush.CreateSolidBrush(redcr);
	
	COLORREF redbluecr(RGB(255,0,255));
	CBrush redbluebrush;
	redbluebrush.CreateSolidBrush(redbluecr);

	CBrush* pbrush = ldc.SelectObject(&redbluebrush);

	ldc.Rectangle(crect.left + 4, crect.top + 4,
		crect.right - 4, crect.bottom - 4);

	 
	COLORREF bluecr(RGB(0,255,255));//ball color
	CBrush bluebrush;
	bluebrush.CreateSolidBrush(bluecr);

	COLORREF greencr(RGB(0,255,0));
	CBrush greenbrush;
	greenbrush.CreateSolidBrush(greencr);

	ldc.SelectObject(brush);

	ldc.Rectangle(crect.left +13, crect.top +13,
		crect.right - 13, crect.bottom -13);

	pbrush =  ldc.SelectObject(&redbluebrush);
	
	writeMessage("in drwaboard1");
	for(int i = 0; i < MAXX; i++)
	{
		for( int j = 0; j < MAXY; j++)
		{
			writeMessage("in for loop");
			CRect rect = cb[i][j].GetRect();		 
			if(cb[i][j].GetPieceType() == BLANK)
			{
				CBitmap bitmap;				
				bitmap.LoadBitmap(IDB_BITMAP_CARD_BLANK);			 
				CDC bmpdc;
				bmpdc.CreateCompatibleDC(&ldc);
				bmpdc.SelectObject(&bitmap); 

				BITMAP bmp;
				bitmap.GetBitmap(&bmp);
				//ldc.SetStretchBltMode(HALFTONE);
				//POINT pt;
				//SetBrushOrgEx(ldc.GetSafeHdc(),0,0,&pt);
				ldc.BitBlt(rect.left,rect.top,m_squareWidth,m_squareHeight,&bmpdc,0,0, SRCCOPY);
			}			 
			else if(cb[i][j].GetPieceState() != PIECE_NOT_MOVING)
			{
				int piece_id;
				COLOR_TYPE  piece_color;
				PIECE_TYPE  piece_type;
				STATE piece_state;
				cb[i][j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
				if(piece_id <= 0)
				{
					break;
				}
				CBitmap bitmap;
				//bitmap.LoadBitmap(piece_id);			 
				bitmap.LoadBitmap(piece_id);			 
				CDC bmpdc;
				bmpdc.CreateCompatibleDC(&ldc);
				bmpdc.SelectObject(&bitmap); 

				BITMAP bmp;
				bitmap.GetBitmap(&bmp);
				//ldc.SetStretchBltMode(HALFTONE);
				//POINT pt;
				//SetBrushOrgEx(ldc.GetSafeHdc(),0,0,&pt);
				ldc.BitBlt(rect.left,rect.top,m_squareWidth,m_squareHeight,&bmpdc,0,0, SRCCOPY);
				//ldc.StretchBlt(rect.left,rect.top,m_squareWidth,m_squareHeight,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
			}
			else
			{
				CBitmap bitmap;				
				bitmap.LoadBitmap(IDB_BITMAP1_CARD_FACE_1);			 
				CDC bmpdc;
				bmpdc.CreateCompatibleDC(&ldc);
				bmpdc.SelectObject(&bitmap); 

				BITMAP bmp;
				bitmap.GetBitmap(&bmp);
				//ldc.SetStretchBltMode(HALFTONE);
				//POINT pt;
				//SetBrushOrgEx(ldc.GetSafeHdc(),0,0,&pt);
				ldc.BitBlt(rect.left,rect.top,m_squareWidth,m_squareHeight,&bmpdc,0,0, SRCCOPY);
				//ldc.StretchBlt(rect.left,rect.top,m_squareWidth,m_squareHeight,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 

			}
			///ldc.SelectObject(&redbluebrush);
		}			
	}	 
	writeMessage("in goint out");
	dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);  
}

void CNetChessView::Initialize()
{
	m_mouseMoveFlag = false;
	m_player_turn = false;
	m_timerFlag = false;
	m_squareWidth = 50;
	m_squareHeight = 60;
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);
	m_point.x = m_point.y = m_backuppoint.x = m_backuppoint.y = -1;
	m_pairCount = 0;
	m_pairFailCount = 0;
	writeMessage("Initializ");
	/*CString str;
	str.Format("%d",m_pairCount);
	WriteStatus(2,str);
	str.Format("%d",m_pairFailCount);
	WriteStatus(4,str);*/

}

void CNetChessView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	writeMessage("Oninitialupdate");
	int arr[100];
	int count=0;
	getRandom(52,arr);
	writeMessage("got the random message");
	int xstart = 20;
	int ystart = 20;
	int x,y=ystart;
	writeMessage("MAXX %d MAXY %d",MAXX,MAXY);
	for ( int i = 0; i < MAXX; i++)
	{
		x = xstart;
		for( int j = 0; j < MAXY; j++)
		{
			CRect rect(x,y, x+ m_squareWidth, y+m_squareHeight);
			writeMessage("set the required data %d %d",i,j);
			cb[i][j].SetRect(rect);
			cb[i][j].SetPieceType(BLANK);			 
			cb[i][j].SetPieceData(arr[count++]+200,WHITE,ROOK,PIECE_NOT_MOVING);

			if(count == 52)
			{
				writeMessage("count = 52");
				getRandom(52,arr);
				writeMessage("count = 52");
				count=0;
			}
			 
			x += 56;
		}
		y += 68;
	} 
	writeMessage("Oninitialupdate is over");
	
	SetTimer(PIECE_SIDE_TIMER_EVENT_ID,1000,NULL);	 
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	OnLButtonDownAction(nFlags,point);	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnLButtonUpAction(nFlags,point);	 
	CView::OnLButtonUp(nFlags, point);
}


void CNetChessView::SetShellIconData(char* data, int id)
{
	NOTIFYICONDATA nicondata;					
	nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(id,&nicondata);
}
 
void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetShellIconData("NetChess by AVM RAO",NIM_DELETE);				 	 
	m_timerFlag = false;
	int x=0,y=0;	 
	 
	for(int i = 0; i < MAXX; i++)
	{
		for( int j = 0; j < MAXY; j++)
		{
			if(cb[i][j].GetPieceId() == -1)
				continue;
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point))
			{			
			   if(cb[i][j].GetPieceType() != BLANK)
				{		 				 					 
					x = i; y = j;
					m_mouseMoveFlag = true;					 					 
				}
			}
		}
	}
	if(m_mouseMoveFlag == true)
	{
		if(m_point.x == -1) //first time
		{
			m_point.x = x; m_point.y = y;
			WriteStatus(0,"Click on another to pair");
			cb[x][y].SetPieceState(PIECE_MOVING);
		}
		else
		{
			if(m_point.x != x ||  m_point.y != y)
			{
				m_backuppoint.x = x; m_backuppoint.y = y;
				cb[x][y].SetPieceState(PIECE_MOVING);
			}
			else
			{
				WriteStatus(0,"Click on different card");
				m_mouseMoveFlag = false;
			}
		}		 
	}	
	DrawBoard();
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_mouseMoveFlag == false)
	{	 
		return;
	}	
	 
	m_mouseMoveFlag = false;	
	//writeMessage("x =%d y = %d bx=%d by=%d",m_point.x,m_point.y,m_backuppoint.x,m_backuppoint.y);
	if(m_backuppoint.x == -1)//first time
	{
		cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);
	}
	else
	{
		cb[m_backuppoint.x][m_backuppoint.y].SetPieceState(PIECE_NOT_MOVING);
//		writeMessage("x =%d y = %d bx=%d by=%d",m_point.x,m_point.y,m_backuppoint.x,m_backuppoint.y);
		if(m_point.x != m_backuppoint.x ||  m_point.y != m_backuppoint.y)
		{
			if(CheckPairs(m_point,m_backuppoint) == true)
			{
				cb[m_point.x][m_point.y].SetPieceType(BLANK);
				cb[m_backuppoint.x][m_backuppoint.y].SetPieceType(BLANK);
				WriteStatus(0,"Pair matchs, congratulations!!");
				m_pairCount++;
				CString str;
				str.Format("%d",m_pairCount);
				WriteStatus(2,str);
			}
			else
			{
				m_pairFailCount++;				
				CString str;
				str.Format("%d",m_pairFailCount);				 
				WriteStatus(4,str);
				WriteStatus(0,"Pair does not match, try next pair");
			}
		}
		m_point.x = m_point.y = m_backuppoint.x = m_backuppoint.y = -1;
	}     

	DrawBoard();	 
}
bool CNetChessView::CheckPairs(CPoint point1,CPoint point2)
{

	for(int i=0;i<13;i++)
	{
		bool foundFlag1 = false, foundFlag2 = false;
		for(int j=0;j<4;j++)
		{
			if(cb[point1.x][point1.y].GetPieceId() == card_pairs[i][j])
			{
				foundFlag1 = true;				 
			}
			if(cb[point2.x][point2.y].GetPieceId() == card_pairs[i][j])
			{
				foundFlag2 = true;				 
			}
			if(foundFlag1 == true && foundFlag2 == true)
			{
				return true;
			}
		}
	}
	return false;

}


void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	DrawBoard();
	CView::OnPrint(pDC, pInfo);
}

void CNetChessView::OnTimer(UINT nIDEvent) 
{
	static int state=1;	
	/*if(m_player_turn == true)
		WriteStatus("Your turn to move");
	else
	{
		WriteStatus("Wait for yor turn");
	}*/
	switch(nIDEvent)
	{
		/*case SHELL_ICON_TIMER_EVENT_ID:
			{				
				NOTIFYICONDATA nicondata;
				char data[64] = "NetChess by A.V.Maheswara Rao";
				 
				nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
				nicondata.uID = 10;
				nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
				nicondata.cbSize = sizeof(nicondata);
				nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
				nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
				strcpy(nicondata.szTip,data);				
				if(state == 1)
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
					state = 0;
				}
				else
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_MAINFRAME_OPPOSITE);
					state = 1;
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
				}
			}
			break;*/
		case PIECE_SIDE_TIMER_EVENT_ID:
			{
					CTime tb(time(0)  -  m_whiteTime );
					CTime st(m_startTime);
					CTimeSpan ts = tb - st; 
					m_blackTime++;
					CString str;
					str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
						//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);
					WriteStatus(5,str);
			}
		default:
			break;
		 
	}
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{
	 
//	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
}

void CNetChessView::OnFileNew() 
{
	OnFileNewAction();	
}

void CNetChessView::OnFileNewAction()
{
	{			
		Initialize();
		OnInitialUpdate();		
		DrawBoard();
	}		
}
 
void CNetChessView::OnHelpHowtoplay() 
{
	CHelpDialog dlg;
	dlg.DoModal(); 
} 
 
void writeMessage(char *str,...)
{
#ifdef _DEBUG
	char arr[9999];
	va_list va;     
     va_start(va,str);
     vsprintf(arr,str,va);       

	 FILE* fp=fopen(".\\data.dat","a+");
	 fprintf(fp,"%s\n",arr);
	 fclose(fp);
#endif
}

void CNetChessView::WriteStatus(int paneno,CString str)
{
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->WriteStatus(paneno,str);
}


void CNetChessView::OnAppExit() 
{
 exit(0);	
}
