#if !defined(AFX_HELPDLG_H__266CD136_1F9B_4CBC_84A7_CA1D7E7A6795__INCLUDED_)
#define AFX_HELPDLG_H__266CD136_1F9B_4CBC_84A7_CA1D7E7A6795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HelpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog

class CHelpDlg : public CDialog
{
// Construction
public:
	CHelpDlg(CWnd* pParent = NULL);   // standard constructor
	CString m_HelpString;
	int m_count;
// Dialog Data
	//{{AFX_DATA(CHelpDlg)
	enum { IDD = IDD_DIALOG_HELP };
	CString	m_help_string;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHelpDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDLG_H__266CD136_1F9B_4CBC_84A7_CA1D7E7A6795__INCLUDED_)
