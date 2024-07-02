// NetChessDoc.h : interface of the CNetChessDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSDOC_H__377E2D91_7EBE_416D_80D7_7D47838524A0__INCLUDED_)
#define AFX_NETCHESSDOC_H__377E2D91_7EBE_416D_80D7_7D47838524A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNetChessDoc : public CDocument
{
protected: // create from serialization only
	CNetChessDoc();
	DECLARE_DYNCREATE(CNetChessDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSDOC_H__377E2D91_7EBE_416D_80D7_7D47838524A0__INCLUDED_)
