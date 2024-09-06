// AddTitleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "AddTitleDlg.h"
#include "ChoiceQue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddTitleDlg dialog


CAddTitleDlg::CAddTitleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddTitleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddTitleDlg)
	m_strExplain = _T("");
	m_strPoint = _T("");
	m_strA = _T("");
	m_strB = _T("");
	m_strC = _T("");
	m_strD = _T("");
	m_strTitle = _T("");
	m_ianswer = -1;
	//}}AFX_DATA_INIT
	m_id=-1;
}


void CAddTitleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddTitleDlg)
	DDX_Text(pDX, IDC_EDIT_EXPLAIN, m_strExplain);
	DDV_MaxChars(pDX, m_strExplain, 500);
	DDX_Text(pDX, IDC_EDIT_POINT, m_strPoint);
	DDV_MaxChars(pDX, m_strPoint, 100);
	DDX_Text(pDX, IDC_A, m_strA);
	DDV_MaxChars(pDX, m_strA, 200);
	DDX_Text(pDX, IDC_B, m_strB);
	DDV_MaxChars(pDX, m_strB, 200);
	DDX_Text(pDX, IDC_C, m_strC);
	DDV_MaxChars(pDX, m_strC, 200);
	DDX_Text(pDX, IDC_D, m_strD);
	DDV_MaxChars(pDX, m_strD, 200);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDV_MaxChars(pDX, m_strTitle, 500);
	DDX_Radio(pDX, IDC_RADIOA, m_ianswer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddTitleDlg, CDialog)
	//{{AFX_MSG_MAP(CAddTitleDlg)
	ON_BN_CLICKED(IDC_AUTO_POINT, OnAutoPoint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddTitleDlg message handlers

void CAddTitleDlg::OnAutoPoint() 
{
	// TODO: Add your control notification handler code here
	MessageBox("��δ���ţ������ڴ�");
}

void CAddTitleDlg::OnAddchoice() 
{
	// TODO: Add your control notification handler code here
	
}

void CAddTitleDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(strlen(m_strTitle)==0||strlen(m_strTitle)>=500)
	{
		MessageBox("��Ŀ����Ϊ���Ҳ�����500�ַ�","�ȼ�������ϰϵͳ");
		return ;
	}
	if(strlen(m_strPoint)==0||strlen(m_strPoint)>=50)
	{
		MessageBox("���㲻��Ϊ���Ҳ�����50�ַ�","�ȼ�������ϰϵͳ");
		return ;
	}
	if(strlen(m_strExplain)>=500)
	{
		MessageBox("���Ͳ��ó���500�ַ�","�ȼ�������ϰϵͳ");
		return ;
	}
	if(strlen(m_strA)==0||strlen(m_strA)>=500||strlen(m_strB)==0||strlen(m_strB)>=500||
		strlen(m_strC)==0||strlen(m_strC)>=500||strlen(m_strD)==0||strlen(m_strD)>=500)
	{
		MessageBox("ѡ���Ϊ���Ҳ�����500�ַ�","�ȼ�������ϰϵͳ");
		return ;
	}
	HChoiceQue CQ;
	m_strTitle.Replace("'","''");
	m_strA.Replace("'","''");
	m_strB.Replace("'","''");
	m_strC.Replace("'","''");
	m_strD.Replace("'","''");
	m_strPoint.Replace("'","''");
	m_strExplain.Replace("'","''");
	if(m_id==-1)
	{
		if(CQ.ChoiceQueAdd(m_pmysql,m_strTitle,m_strA,m_strB,m_strC,m_strD,m_ianswer,m_strPoint,m_strExplain)==false)
		{
			MessageBox("���ʧ��","�ȼ�������ϰϵͳ");
			return ;
		}
		MessageBox("��ӳɹ�","�ȼ�������ϰϵͳ");
	}
	else
	{
		if(m_choiceQue->ChoiceQueUpdate(m_pmysql,m_id,m_strTitle,m_strA,m_strB,m_strC,m_strD,m_ianswer,m_strPoint,m_strExplain)==false)
		{
			MessageBox("�޸�ʧ��","�ȼ�������ϰϵͳ");
			return ;
		}
		MessageBox("�޸ĳɹ�","�ȼ�������ϰϵͳ");
	}
	CDialog::OnOK();
}

BOOL CAddTitleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_id==-1)
	{
		((CButton *)GetDlgItem(IDC_RADIOA))->SetCheck(TRUE);
	}
	else
	{
		m_ianswer=m_choiceQue->m_icorrentAnswer;
		m_strA=m_choiceQue->m_pstrA;
		m_strB=m_choiceQue->m_pstrB;
		m_strC=m_choiceQue->m_pstrC;
		m_strD=m_choiceQue->m_pstrD;
		m_strExplain=m_choiceQue->m_pstrExplain;
		m_strTitle=m_choiceQue->m_pstrTitle;
		
		CString sql;
		sql.Format("SELECT point_name FROM point WHERE point_id IN(SELECT point_id FROM choicepoint WHERE choice_id=\'%d\');",m_choiceQue->m_id);
		mysql_real_query(m_pmysql,sql,sql.GetLength());
		MYSQL_RES *res=mysql_store_result(m_pmysql);
		MYSQL_ROW row;
		m_strPoint="";
		while(row=mysql_fetch_row(res))
		{
			m_strPoint+=(CString)row[0]+" ";
		}
		UpdateData(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
