#if !defined(AFX_ADDOPDLG_H__EBA5CA76_0EFC_43EE_B2CD_312F2631E29E__INCLUDED_)
#define AFX_ADDOPDLG_H__EBA5CA76_0EFC_43EE_B2CD_312F2631E29E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOpDlg.h : header file
//
#include <winsock.h>
#include <mysql.h>
#include "HOpQue.h"
#include "Resource.h"
#pragma comment(lib,"libmySQL.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddOpDlg dialog

class CAddOpDlg : public CDialog
{
// Construction
public:
	HOpQue* opQue;
	MYSQL* m_pmysql;
	CAddOpDlg(CWnd* pParent = NULL);   // standard constructor
	int m_id;
// Dialog Data
	//{{AFX_DATA(CAddOpDlg)
	enum { IDD = IDD_ADDOP_DIALOG };
	int		m_nType;
	CString	m_strAns1;
	CString	m_strAns2;
	CString	m_strAns3;
	CString	m_strC;
	CString	m_strExplain;
	CString	m_strIn;
	CString	m_strOut;
	CString	m_strTitle;
	CString	m_strPoint;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddOpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddOpDlg)
	afx_msg void OnFilec();
	afx_msg void OnFilein();
	afx_msg void OnFileout();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDOPDLG_H__EBA5CA76_0EFC_43EE_B2CD_312F2631E29E__INCLUDED_)
