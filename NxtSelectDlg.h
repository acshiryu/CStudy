#if !defined(AFX_NXTSELECTDLG_H__9696D6AF_6944_494C_8664_3CDE3EA8C1BA__INCLUDED_)
#define AFX_NXTSELECTDLG_H__9696D6AF_6944_494C_8664_3CDE3EA8C1BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NxtSelectDlg.h : header file
//
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
#include "ChoiceQue.h"
#include "HOpQue.h"
/////////////////////////////////////////////////////////////////////////////
// CNxtSelectDlg dialog

class CNxtSelectDlg : public CDialog
{
// Construction
public:
	HChoiceQue* CQue;
	HOpQue* opQue;
	MYSQL *mysql;
	LPSTR m_shuoming;
//	int nxtDlgNum;
	CNxtSelectDlg(CWnd* pParent = NULL);   // standard constructor
	int m_nkind;

// Dialog Data
	//{{AFX_DATA(CNxtSelectDlg)
	enum { IDD = IDD_EDIT_DIALOG };
	CStatic	m_static;
	CString	m_strEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNxtSelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNxtSelectDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NXTSELECTDLG_H__9696D6AF_6944_494C_8664_3CDE3EA8C1BA__INCLUDED_)
