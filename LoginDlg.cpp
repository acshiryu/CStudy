// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "LoginDlg.h"
#include "student.h"
#include "RegisterDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_examRegId = _T("");
	m_password = _T("");
	m_bRem = FALSE;
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EXAMREGID, m_examRegId);
	DDV_MaxChars(pDX, m_examRegId, 16);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 18);
	DDX_Check(pDX, IDC_REMBER, m_bRem);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(ID_REG, OnReg)
	ON_BN_CLICKED(IDC_AUTOLOGIN, OnAutologin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);

//	if(strlen(m_examRegId)!=16)
//	{
//		MessageBox("请输入16位准考证号！","等级考试练习系统");
//		return ;
//	}
	if(strlen(m_examRegId)==0)
	{
		MessageBox("准考证号不为空！","等级考试练习系统");
		return ;
	}
	if(strlen(m_password)==0)
	{
		MessageBox("请输入密码！","等级考试练习系统");
		return ;
	}
	if(m_pstu->Query(m_pmysql,m_examRegId,m_password)==FALSE)
	{
		MessageBox("准考证号或密码错误","等级考试练习系统");
		return ;
	}
//	MessageBox(m_pstu->m_cardId);
//	MessageBox(m_pstu->m_examRegId);

	HKEY hkey;
	RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Student",&hkey);
	if(((CButton*)GetDlgItem(IDC_REMBER))->GetCheck())
	{
		RegSetValueEx(hkey,"ExamNum",0,REG_SZ,(LPBYTE)(LPCSTR)m_examRegId,strlen(m_examRegId));
		RegSetValueEx(hkey,"Password",0,REG_SZ,(LPBYTE)(LPCSTR)m_password,strlen(m_password));
		RegSetValueEx(hkey,"Rember",0,REG_SZ,(LPBYTE)"true",strlen("true"));
	}
	else
	{
		RegSetValueEx(hkey,"ExamNum",0,REG_SZ,(LPBYTE)"",strlen(""));
		RegSetValueEx(hkey,"Password",0,REG_SZ,(LPBYTE)"",strlen(""));
		RegSetValueEx(hkey,"Rember",0,REG_SZ,(LPBYTE)"false",strlen("false"));
	}

	if(((CButton*)GetDlgItem(IDC_AUTOLOGIN))->GetCheck())
	{
		RegSetValueEx(hkey,"LOGIN",0,REG_SZ,(LPBYTE)"AUTO",strlen("AUTO"));
	}
	else
	{
		RegSetValueEx(hkey,"LOGIN",0,REG_SZ,(LPBYTE)"CLICK",strlen("CLICK"));
	}
	
	RegCloseKey(hkey);
	CDialog::OnOK();
}

void CLoginDlg::OnReg() 
{
	// TODO: Add your control notification handler code here
	CRegisterDlg *regDlg=new CRegisterDlg;
	regDlg->m_pmysql=m_pmysql;
	if(IDOK==regDlg->DoModal())
	{
		
	}
	else
	{

	}
}

void CLoginDlg::OnAutologin() 
{
	// TODO: Add your control notification handler code here
	if(((CButton*)GetDlgItem(IDC_AUTOLOGIN))->GetCheck())
	{
		((CButton*)GetDlgItem(IDC_REMBER))->SetCheck(true);
	}
}

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
