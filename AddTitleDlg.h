#if !defined(AFX_ADDTITLEDLG_H__A3E30441_9B25_4ADA_B1F7_6FCAE088CB45__INCLUDED_)
#define AFX_ADDTITLEDLG_H__A3E30441_9B25_4ADA_B1F7_6FCAE088CB45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddTitleDlg.h : header file
//
#include <winsock.h>
#include <mysql.h>
#include "ChoiceQue.h"
#pragma comment(lib,"libmySQL.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddTitleDlg dialog

class CAddTitleDlg : public CDialog
{
// Construction
public:
	CAddTitleDlg(CWnd* pParent = NULL);   // standard constructor
	MYSQL* m_pmysql;
	int m_id;
	HChoiceQue *m_choiceQue;
// Dialog Data
	//{{AFX_DATA(CAddTitleDlg)
	enum { IDD = IDD_ADDTITLE_DIALOG };
	CString	m_strExplain;
	CString	m_strPoint;
	CString	m_strA;
	CString	m_strB;
	CString	m_strC;
	CString	m_strD;
	CString	m_strTitle;
	int		m_ianswer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddTitleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddTitleDlg)
	afx_msg void OnAutoPoint();
	afx_msg void OnAddchoice();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTITLEDLG_H__A3E30441_9B25_4ADA_B1F7_6FCAE088CB45__INCLUDED_)
