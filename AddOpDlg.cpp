// AddOpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "AddOpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddOpDlg dialog


CAddOpDlg::CAddOpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddOpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddOpDlg)
	m_nType = -1;
	m_strAns1 = _T("");
	m_strAns2 = _T("");
	m_strAns3 = _T("");
	m_strC = _T("");
	m_strExplain = _T("");
	m_strIn = _T("");
	m_strOut = _T("");
	m_strTitle = _T("");
	m_strPoint = _T("");
	//}}AFX_DATA_INIT
	m_id=-1;
}


void CAddOpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddOpDlg)
	DDX_Radio(pDX, IDC_RADIOTYPE1, m_nType);
	DDX_Text(pDX, IDE_ANS1, m_strAns1);
	DDV_MaxChars(pDX, m_strAns1, 500);
	DDX_Text(pDX, IDE_ANS2, m_strAns2);
	DDV_MaxChars(pDX, m_strAns2, 500);
	DDX_Text(pDX, IDE_ANS3, m_strAns3);
	DDV_MaxChars(pDX, m_strAns3, 500);
	DDX_Text(pDX, IDE_C, m_strC);
	DDV_MaxChars(pDX, m_strC, 5000);
	DDX_Text(pDX, IDE_EXPLAIN, m_strExplain);
	DDV_MaxChars(pDX, m_strExplain, 500);
	DDX_Text(pDX, IDE_IN, m_strIn);
	DDV_MaxChars(pDX, m_strIn, 5000);
	DDX_Text(pDX, IDE_OUT, m_strOut);
	DDV_MaxChars(pDX, m_strOut, 5000);
	DDX_Text(pDX, IDE_TITLE, m_strTitle);
	DDV_MaxChars(pDX, m_strTitle, 500);
	DDX_Text(pDX, IDE_POINT, m_strPoint);
	DDV_MaxChars(pDX, m_strPoint, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddOpDlg, CDialog)
	//{{AFX_MSG_MAP(CAddOpDlg)
	ON_BN_CLICKED(IDB_FILEC, OnFilec)
	ON_BN_CLICKED(IDB_FILEIN, OnFilein)
	ON_BN_CLICKED(IDB_FILEOUT, OnFileout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddOpDlg message handlers

void CAddOpDlg::OnFilec() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("还未实现，请期待。。。");
	UpdateData(true);
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="打开C文件";
	fileDlg.m_ofn.lpstrFilter="C Files(*.c)\0*.c\0All Files(*.*)\0*.*\0\0";
	
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),CFile::modeRead);
		DWORD dwFileLen;
		dwFileLen=file.GetLength();
		char *pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();
		m_strC=pBuf;
		UpdateData(false);
	}
}

void CAddOpDlg::OnFilein() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="打开in数据文件";
	fileDlg.m_ofn.lpstrFilter="IN.DAT(in.dat)\0in.dat\0IN Files(*.in)\0*.in\0All Files(*.*)\0*.*\0\0";
	
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),CFile::modeRead);
		DWORD dwFileLen;
		dwFileLen=file.GetLength();
		char *pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();
		m_strIn=pBuf;
		UpdateData(false);
	}
}

void CAddOpDlg::OnFileout() 
{
	// TODO: Add your control notification handler code here
//	MessageBox("还未实现，请期待。。。");
	UpdateData(true);
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="打开out数据文件";
	fileDlg.m_ofn.lpstrFilter="OUT.DAT(out.dat)\0out.dat\0OUT Files(*.out)\0*.out\0All Files(*.*)\0*.*\0\0";
	
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),CFile::modeRead);
		DWORD dwFileLen;
		dwFileLen=file.GetLength();
		char *pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();
		m_strOut=pBuf;
		UpdateData(false);
	}
}

void CAddOpDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(strlen(m_strTitle)==0)
	{
		MessageBox("题目标题不能为空");
		return ;
	}
	if(strlen(m_strPoint)==0)
	{
		MessageBox("考点不能为空");
		return ;
	}
	if(strlen(m_strC)==0)
	{
		MessageBox("C代码不能为空");
		return ;
	}
	if(strlen(m_strAns1)==0)
	{
		MessageBox("答案第一空不能为空");
		return ;
	}
	m_strTitle.Replace("'","''");
	m_strAns1.Replace("'","''");
	m_strAns2.Replace("'","''");
	m_strAns3.Replace("'","''");
	m_strC.Replace("'","''");
	m_strIn.Replace("'","''");
	m_strOut.Replace("'","''");
	m_strPoint.Replace("'","''");
	m_strExplain.Replace("'","''");

	int nCount=m_strC.Replace("/**********found**********/","/**********found**********/");
	if(m_nType==0)
	{//程序填空题
		if(nCount!=3)
		{
			MessageBox("C代码错误，应有三个填空区，且每个填空区的上一行为\"/**********found**********/\"");
			return ;
		}
		if(strlen(m_strAns2)==0)
		{
			MessageBox("答案第二空不能为空");
			return ;
		}
		if(strlen(m_strAns2)==0)
		{
			MessageBox("答案第三空不能为空");
			return ;
		}
		
	}
	else if(m_nType==1)
	{//程序修改题
		if(nCount!=3)
		{
			MessageBox("C代码错误，应有两个修改区，且每个修改区的上一行为\"/**********found**********/\"");
			return ;
		}
		if(strlen(m_strAns2)==0)
		{
			MessageBox("答案第二空不能为空");
			return ;
		}
	}
	else if(m_nType==2)
	{//程序设计题
		if(strstr(m_strC,"fun")==NULL)
		{
			MessageBox("C代码错误，应有一个fun函数");
			return ;
		}
		if(strlen(m_strIn)==0)
		{
			MessageBox("in文件不能为空");
			return ;
		}
		if(strlen(m_strOut)==0)
		{
			MessageBox("Out文件不能为空");
			return ;
		}
	}

	if(m_id==-1)
	{
		char *sql_query=new char[30000];
		sprintf(sql_query,"INSERT INTO operating(op_title,op_c,op_in,op_out,op_ans1,op_ans2,op_ans3,op_explain,op_type)	\
			VALUES(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%d\');",
			m_strTitle,m_strC,m_strIn,m_strOut,m_strAns1,m_strAns2,m_strAns3,m_strExplain,m_nType);

		if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
		{
			MessageBox("数据库错误");
			return;
		}

		mysql_real_query(m_pmysql,"SELECT LAST_INSERT_ID();",(UINT)strlen("SELECT LAST_INSERT_ID();")+1);
		MYSQL_RES *result=mysql_store_result(m_pmysql);
		MYSQL_ROW row;
		int opId;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&opId);
		}
		mysql_free_result(result);


		//分割考点
		int i;
		bool spit=false;
		TCHAR p[100];
		int pLength=0;
		m_strPoint+="  ";
		for(i=0;i<m_strPoint.GetLength();i++)
		{
			if(m_strPoint[i]==','||m_strPoint[i]==';'||m_strPoint[i]==' '||m_strPoint[i]=='\n'
				||(m_strPoint[i]=='\r'&&m_strPoint[i+1]=='\n'))
			{
				if(spit==false)
				{
					continue;
				}
				else
				{
					//TODO
					p[pLength]=0;
					sprintf(sql_query,"SELECT point_id FROM point WHERE point_name = \'%s\';",p);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						MessageBox("数据库错误");
						return ;
					}

					CString str;
					MYSQL_RES *res;
					int pointId;
					if(!(res=mysql_store_result(m_pmysql)))
					{MessageBox("数据库错误");
						return ;
					}
					if(mysql_num_rows(res)==0)
					{
						sprintf(sql_query,"INSERT INTO point(point_name) VALUES(\'%s\');",p);
						if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
						{
							MessageBox("数据库错误");
							return;
						}
						mysql_free_result(res);
						mysql_real_query(m_pmysql,"SELECT LAST_INSERT_ID();",(UINT)strlen("SELECT LAST_INSERT_ID();")+1);
						res=mysql_store_result(m_pmysql);
					}
					while(row = mysql_fetch_row(res))  
					{
						sscanf(row[0],"%d",&pointId);
					}
					mysql_free_result(res);
					
					sprintf(sql_query,"SELECT * FROM oppoint WHERE op_id=\'%d\' AND point_id=\'%d\';",m_id,pointId);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						MessageBox("数据库错误");
						return;
					}
					res=mysql_store_result(m_pmysql);
					if(mysql_num_rows(res)==0)
					{
						mysql_free_result(res);
						sprintf(sql_query,"INSERT INTO oppoint(op_id,point_id) VALUES(\'%d\',\'%d\');",opId,pointId);
						if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
						{
							MessageBox("数据库错误");
							return;
						}
					}
					pLength=0;
					spit=false;
				}
			}
			else
			{
				p[pLength]=m_strPoint[i];
				pLength++;
				spit=true;
			}
		}
		MessageBox("增加成功","等级考试练习系统");
	}
	else
	{
		char *sql_query=new char[30000];
		sprintf(sql_query,"UPDATE operating SET op_title=\'%s\',op_c=\'%s\',op_in=\'%s\',op_out=\'%s\',	\
			op_ans1=\'%s\',op_ans2=\'%s\',op_ans3=\'%s\',op_explain=\'%s\',op_type=\'%d\' WHERE op_id=\'%d\';",
			m_strTitle,m_strC,m_strIn,m_strOut,m_strAns1,m_strAns2,m_strAns3,m_strExplain,m_nType,m_id);
			

		if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
		{
			MessageBox("数据库错误");
			return;
		}
		MYSQL_ROW row;

		sprintf(sql_query,"DELETE FROM oppoint WHERE op_id=\'%d\';",m_id);
		if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
		{
			return;
		}

		//分割考点
		int i;
		bool spit=false;
		TCHAR p[100];
		int pLength=0;
		m_strPoint+="  ";
		for(i=0;i<m_strPoint.GetLength();i++)
		{
			if(m_strPoint[i]==','||m_strPoint[i]==';'||m_strPoint[i]==' '||m_strPoint[i]=='\n'
				||(m_strPoint[i]=='\r'&&m_strPoint[i+1]=='\n'))
			{
				if(spit==false)
				{
					continue;
				}
				else
				{
					//TODO
					p[pLength]=0;
					sprintf(sql_query,"SELECT point_id FROM point WHERE point_name = \'%s\';",p);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						MessageBox("数据库错误");
						return ;
					}

					CString str;
					MYSQL_RES *res;
					int pointId;
					if(!(res=mysql_store_result(m_pmysql)))
					{
						MessageBox("数据库错误");
						return ;
					}
					if(mysql_num_rows(res)==0)
					{
						sprintf(sql_query,"INSERT INTO point(point_name) VALUES(\'%s\');",p);
						if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
						{
							MessageBox("数据库错误");
							return;
						}
						mysql_free_result(res);
						mysql_real_query(m_pmysql,"SELECT LAST_INSERT_ID();",(UINT)strlen("SELECT LAST_INSERT_ID();")+1);
						res=mysql_store_result(m_pmysql);
					}
					while(row = mysql_fetch_row(res))  
					{
						sscanf(row[0],"%d",&pointId);
					}
					mysql_free_result(res);

					sprintf(sql_query,"SELECT * FROM oppoint WHERE op_id=\'%d\' AND point_id=\'%d\';",m_id,pointId);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						MessageBox("数据库错误");
						return;
					}
					res=mysql_store_result(m_pmysql);
					if(mysql_num_rows(res)==0)
					{
						mysql_free_result(res);
						sprintf(sql_query,"INSERT INTO oppoint(op_id,point_id) VALUES(\'%d\',\'%d\');",m_id,pointId);
						if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
						{
							MessageBox("数据库错误");
							return;
						}
					}				
					pLength=0;
					spit=false;
				}
			}
			else
			{
				p[pLength]=m_strPoint[i];
				pLength++;
				spit=true;
			}
		}
		opQue->GetOrderOp(m_pmysql,m_id-1);
		MessageBox("修改成功","等级考试练习系统");
	}
	CDialog::OnOK();
}

BOOL CAddOpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_id==-1)
	{
		((CButton *)GetDlgItem(IDC_RADIOTYPE1))->SetCheck(TRUE);
	}
	else
	{
		m_nType=opQue->m_nType;
		m_strAns1=opQue->m_strAns1;
		m_strAns2=opQue->m_strAns2;
		m_strAns3=opQue->m_strAns3;
		m_strC=opQue->m_strC;
		m_strExplain=opQue->m_strExplain;
		m_strIn=opQue->m_strIn;
		m_strOut=opQue->m_strOut;
		m_strTitle=opQue->m_strTitle;

		CString sql;
		sql.Format("SELECT point_name FROM point WHERE point_id IN(SELECT point_id FROM oppoint WHERE op_id=\'%d\');",opQue->m_id);
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
