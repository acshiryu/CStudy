#if !defined(AFX_ADDWA_H__47A4FA4C_2EEB_4470_800D_F8E7924A2423__INCLUDED_)
#define AFX_ADDWA_H__47A4FA4C_2EEB_4470_800D_F8E7924A2423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddWA.h : header file
//
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddWA dialog

class CAddWA : public CDialog
{
// Construction
public:
	CAddWA(CWnd* pParent = NULL);   // standard constructor
	MYSQL *mysql;
	int stu_id;
	int choice_id;
	int operating_id;
	CString m_strExplain;
// Dialog Data
	//{{AFX_DATA(CAddWA)
	enum { IDD = IDD_ADDWA_DIALOG };
	CEdit	m_edtAdd;
	CString	m_strAdd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddWA)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddWA)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDWA_H__47A4FA4C_2EEB_4470_800D_F8E7924A2423__INCLUDED_)
