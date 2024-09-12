// AddWA.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "AddWA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddWA dialog


CAddWA::CAddWA(CWnd* pParent /*=NULL*/)
	: CDialog(CAddWA::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddWA)
	m_strAdd = _T("");
	//}}AFX_DATA_INIT
	m_strExplain="";
}


void CAddWA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddWA)
	DDX_Control(pDX, IDC_EDIT_ADD, m_edtAdd);
	DDX_Text(pDX, IDC_EDIT_ADD, m_strAdd);
	DDV_MaxChars(pDX, m_strAdd, 500);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddWA, CDialog)
	//{{AFX_MSG_MAP(CAddWA)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddWA message handlers

void CAddWA::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(operating_id==-1)
	{
		char *sql_query=new char[1000];
		sprintf(sql_query,"SELECT * FROM choicewrong WHERE student_id=\'%d\' AND choice_id=\'%d\';",stu_id,choice_id);
		if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
		{
			MessageBox("数据库错误");
			return ;
		}
		MYSQL_RES *result=mysql_store_result(mysql);
		if(mysql_num_rows(result)!=0)
		{
			mysql_free_result(result);
			memset(sql_query,0,strlen(sql_query));
			sprintf(sql_query,"UPDATE choicewrong SET choicewrong_explain =\'%s\' WHERE student_id=\'%d\' AND choice_id=\'%d\';",m_strAdd,stu_id,choice_id);
		//	MessageBox(sql_query);
			if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
			{
				MessageBox("数据库错误");
				return ;
			}
			MessageBox("更新错题库成功");	
		}
		else
		{
			mysql_free_result(result);
			sprintf(sql_query,"INSERT INTO choicewrong(choice_id,student_id,choicewrong_explain) VALUES(\'%d\',\'%d\',\'%s\');",choice_id,stu_id,m_strAdd);
		//	MessageBox(sql_query);
			if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
			{
				MessageBox("数据库错误");
				return ;
			}
			MessageBox("加入错题库成功");
		}
	}
	else
	{
		char *sql_query=new char[1000];
		sprintf(sql_query,"SELECT * FROM opwrong WHERE student_id=\'%d\' AND op_id=\'%d\';",stu_id,operating_id);
		if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
		{
			MessageBox("数据库错误");
			return ;
		}
		MYSQL_RES *result=mysql_store_result(mysql);
		if(mysql_num_rows(result)!=0)
		{
			mysql_free_result(result);
			memset(sql_query,0,strlen(sql_query));
		//	MessageBox(m_strAdd);
			sprintf(sql_query,"UPDATE opwrong SET opwa_explain =\'%s\' WHERE student_id=\'%d\' AND op_id=\'%d\';",m_strAdd,stu_id,operating_id);
		//	MessageBox(sql_query);
			if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
			{
				MessageBox("数据库错误");
				return ;
			}
			MessageBox("更新错题库成功");	
		}
		else
		{
			mysql_free_result(result);
			sprintf(sql_query,"INSERT INTO opwrong(op_id,student_id,opwa_explain) VALUES(\'%d\',\'%d\',\'%s\');",operating_id,stu_id,m_strAdd);
		//	MessageBox(sql_query);
			if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
			{
				MessageBox("数据库错误");
				return ;
			}
			MessageBox("加入错题库成功");
		}
	}
	CDialog::OnOK();
}

BOOL CAddWA::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	MYSQL_ROW row;
	CString strTemp;
	if(operating_id==-1)
	{
		char *sql_query=new char[1000];
		sprintf(sql_query,"SELECT choicewrong_explain FROM choicewrong WHERE student_id=\'%d\' AND choice_id=\'%d\';",stu_id,choice_id);
		if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
		{
			MessageBox("数据库错误");
			return false;
		}
		MYSQL_RES *result=mysql_store_result(mysql);
		
		if(mysql_num_rows(result)!=0)
		{
			while(row=mysql_fetch_row(result))
			{
				strTemp=row[0];
				m_edtAdd.SetWindowText(strTemp);
			}
		}
	}
	else
	{
		char *sql_query=new char[1000];
		sprintf(sql_query,"SELECT opwa_explain FROM opwrong WHERE student_id=\'%d\' AND op_id=\'%d\';",stu_id,operating_id);
		if(mysql_real_query(mysql,sql_query,strlen(sql_query)))
		{
			MessageBox("数据库错误");
			return false;
		}
		MYSQL_RES *result=mysql_store_result(mysql);
		if(mysql_num_rows(result)!=0)
		{
			while(row=mysql_fetch_row(result))
			{
				strTemp=row[0];
				m_edtAdd.SetWindowText(strTemp);
			}
		}
	
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
