// NetChessView.h : interface of the CNetChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
#define AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChessBoard.h"


 
class CNetChessView : public CView
{
	enum {MAXX=7};
	enum {MAXY=10};
	long m_blackTime, m_whiteTime,m_startTime;	
	bool m_mouseMoveFlag;	
	CPoint m_point,m_backuppoint;		
	bool m_player_turn;	
	int m_squareWidth;
	int m_squareHeight;
	int m_pairFailCount;
	int i;//for VC 2005 compliant
protected: // create from serialization only
	CNetChessView();
	DECLARE_DYNCREATE(CNetChessView)
	 

// Attributes
public:
	
	bool m_timerFlag;	 	
	void DrawBoard();
	CNetChessDoc* GetDocument();	
	void KillTimerEvent(); 
	
	void Initialize();		
	
	CChessBoard cb[MAXX+1][MAXY+1];	
	
	bool CheckPairs(CPoint point1,CPoint point2);
	int m_pairCount;	 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnFileNew();
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	void OnMessageColorData(WPARAM wParam,LPARAM lParam);
	void OnLButtonDownAction(UINT nFlags, CPoint point);
	void OnLButtonUpAction(UINT nFlags, CPoint point);	
	void OnFileNewAction();	
	void SetShellIconData(char* data, int id);	
	void WriteStatus(int,CString str);

};

#ifndef _DEBUG  // debug version in NetChessView.cpp
inline CNetChessDoc* CNetChessView::GetDocument()
   { return (CNetChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
