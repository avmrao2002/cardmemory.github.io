// NetChessDoc.cpp : implementation of the CNetChessDoc class
//

#include "stdafx.h"
#include "NetChess.h"

#include "NetChessDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetChessDoc

IMPLEMENT_DYNCREATE(CNetChessDoc, CDocument)

BEGIN_MESSAGE_MAP(CNetChessDoc, CDocument)
	//{{AFX_MSG_MAP(CNetChessDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessDoc construction/destruction

CNetChessDoc::CNetChessDoc()
{
	// TODO: add one-time construction code here

}

CNetChessDoc::~CNetChessDoc()
{
}

BOOL CNetChessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNetChessDoc serialization

void CNetChessDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	 
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessDoc diagnostics

#ifdef _DEBUG
void CNetChessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNetChessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessDoc commands
