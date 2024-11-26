#if !defined(AFX_OPANSDLG_H__DD1BC291_1232_49AB_A83A_6C1F311383F3__INCLUDED_)
#define AFX_OPANSDLG_H__DD1BC291_1232_49AB_A83A_6C1F311383F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpAnsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpAnsDlg dialog

class COpAnsDlg : public CDialog
{
// Construction
public:
	COpAnsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpAnsDlg)
	enum { IDD = IDD_OPANS_DIALOG };
	CString	m_strOpAns;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpAnsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpAnsDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPANSDLG_H__DD1BC291_1232_49AB_A83A_6C1F311383F3__INCLUDED_)
