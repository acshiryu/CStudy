// PointDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "PointDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointDlg dialog


CPointDlg::CPointDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPointDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPointDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPointDlg)
	DDX_Control(pDX, IDC_CPOINT, m_cPoint);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPointDlg, CDialog)
	//{{AFX_MSG_MAP(CPointDlg)
	ON_CBN_DROPDOWN(IDC_CPOINT, OnDropdownCpoint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointDlg message handlers

void CPointDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	m_cPoint.GetWindowText(strTemp);
	if(m_nkind==1)
	{
		if(false==CQue->GetPointQue(mysql,strTemp,0,true))
		{
			MessageBox("找不到对应试题");
			return ;
		}
	}
	else if(m_nkind==2)
	{
		if(false==opQue->GetPointOp(mysql,strTemp,0,true))
		{
			MessageBox("找不到对应试题");
			return ;
		}
	}
	CDialog::OnOK();
}

BOOL CPointDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cPoint.ResetContent();
	mysql_real_query(mysql,"SELECT point_name FROM point",strlen("SELECT point_name FROM point")+1);
	MYSQL_RES *res=mysql_store_result(mysql);
	MYSQL_ROW row;
	while(row=mysql_fetch_row(res))
	{
		TCHAR s[100];
		strcpy(s,row[0]);
		m_cPoint.AddString(s);
	}
	m_cPoint.SetCurSel(0);
	UpdateData(true);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPointDlg::OnDropdownCpoint() 
{
	// TODO: Add your control notification handler code here
	
}
