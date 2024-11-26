#if !defined(AFX_POINTDLG_H__E5BDC31F_205D_4F56_9D8B_EF40CC7CDCFE__INCLUDED_)
#define AFX_POINTDLG_H__E5BDC31F_205D_4F56_9D8B_EF40CC7CDCFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PointDlg.h : header file
//
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
#include "ChoiceQue.h"
#include "HOpQue.h"
/////////////////////////////////////////////////////////////////////////////
// CPointDlg dialog

class CPointDlg : public CDialog
{
// Construction
public:
	HChoiceQue* CQue;
	HOpQue* opQue;
	MYSQL *mysql;
	LPSTR m_shuoming;
	int nxtDlgNum;
	CString strTemp;
	CPointDlg(CWnd* pParent = NULL);   // standard constructor
	int m_nkind;
// Dialog Data
	//{{AFX_DATA(CPointDlg)
	enum { IDD = IDD_POINT_DIALOG };
	CComboBox	m_cPoint;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPointDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnDropdownCpoint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTDLG_H__E5BDC31F_205D_4F56_9D8B_EF40CC7CDCFE__INCLUDED_)
