#if !defined(AFX_IPDLG_H__64C9E462_87FB_44B1_B76B_FA81E6CF3CFD__INCLUDED_)
#define AFX_IPDLG_H__64C9E462_87FB_44B1_B76B_FA81E6CF3CFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IpDlg.h : header file
//
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
/////////////////////////////////////////////////////////////////////////////
// CIpDlg dialog

class CIpDlg : public CDialog
{
// Construction
public:
	CIpDlg(CWnd* pParent = NULL);   // standard constructor
	MYSQL* m_pmysql;
// Dialog Data
	//{{AFX_DATA(CIpDlg)
	enum { IDD = IDD_SETIP_DIALOG };
	CIPAddressCtrl	m_ipAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIpDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPDLG_H__64C9E462_87FB_44B1_B76B_FA81E6CF3CFD__INCLUDED_)
