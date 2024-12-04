// NxtSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "NxtSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNxtSelectDlg dialog


CNxtSelectDlg::CNxtSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNxtSelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNxtSelectDlg)
	m_strEdit = _T("");
	//}}AFX_DATA_INIT
}


void CNxtSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNxtSelectDlg)
	DDX_Control(pDX, IDC_EXPLAIN, m_static);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNxtSelectDlg, CDialog)
	//{{AFX_MSG_MAP(CNxtSelectDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNxtSelectDlg message handlers

BOOL CNxtSelectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_static.SetWindowText(m_shuoming);
	
	
	m_strEdit="1";
	UpdateData(false);
	GetDlgItem(IDC_EDIT)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT))->SetSel(0,-1);
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNxtSelectDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(strlen(m_strEdit)==0)
	{
		MessageBox("输入题目编号");
		return ;
	}
	int id=0;
	sscanf(m_strEdit,"%d",&id);
	if(m_nkind==1)
	{
		if(false==CQue->GetOrderQue(mysql,id-1))
		{
			MessageBox("题目选择错误");
			return ;
		}
	}
	else if(m_nkind==2)
	{
		if(false==opQue->GetOrderOp(mysql,id-1))
		{
			MessageBox("题目选择错误");
			return ;
		}
	}
	CDialog::OnOK();
}
