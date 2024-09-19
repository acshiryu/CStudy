#include "stdafx.h"
#include "ChoiceQue.h"
#include <vector>
using namespace std;
#define ZERO(a) memset((a),0,sizeof(a))
_declspec(dllimport) int RecommendChoice(MYSQL* mysql,int choice_id,int student_id);
HChoiceQue::HChoiceQue()
{
	m_ianswer=-1;
	m_pstrA=new char[500];
	m_pstrB=new char[500];
	m_pstrC=new char[500];
	m_pstrD=new char[500];
	m_pstrExplain=new char[500];
	m_pstrTitle=new char[500];
}
HChoiceQue::~HChoiceQue()
{
}
int HChoiceQue::LastAnswer(MYSQL *mysql,int choiceId)
{
	char sql_query[255]="";
	ZERO(sql_query);
	sprintf(sql_query,"SELECT choicerecord_answer FROM choicerecord WHERE choicerecord_id=  \
		(SELECT MAX(choicerecord_id) FROM choicerecord WHERE student_id = \'%d\' AND choice_id=\'%d\' );",m_pstu->m_id,choiceId);
	mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query));
	MYSQL_RES *result=mysql_store_result(mysql);
	MYSQL_ROW row;
	if(mysql_num_rows(result)==0)
	{
		mysql_free_result(result);
		return -1;
	}
	int t;
	while(row = mysql_fetch_row(result))  
	{
		sscanf(row[0],"%d",&t);
	}
	mysql_free_result(result);
	return t;
}
bool HChoiceQue::GetPointQue(MYSQL* mysql,CString point,int id,bool isnew,bool nxt)
{
	char sql_query[255]="";
	int pointId;
	ZERO(sql_query);
	sprintf(sql_query,"SELECT point_id from point WHERE point_name =\'%s\';",point);
	mysql_real_query(mysql,sql_query,sizeof(sql_query));
	MYSQL_RES *res=mysql_store_result(mysql);
	MYSQL_ROW mysqlrow;
	if(mysql_num_rows(res)==0)
	{
		mysql_free_result(res);
		return false;
	}
	while(mysqlrow = mysql_fetch_row(res))  
	{
		sscanf(mysqlrow[0],"%d",&pointId);
	}
	mysql_free_result(res);


	if(isnew==true)
	{
		ZERO(sql_query);
		sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choicepoint WHERE point_id=\'%d\');",pointId);
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		MYSQL_ROW row;
		if(mysql_num_rows(result)==0)
			return false;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			strcpy(m_pstrTitle,row[1]);
			strcpy(m_pstrA,row[2]);
			strcpy(m_pstrB,row[3]);
			strcpy(m_pstrC,row[4]);
			strcpy(m_pstrD,row[5]);
			strcpy(m_pstrExplain,row[6]);
			sscanf(row[7],"%d",&m_icorrentAnswer);
	//		AfxMessageBox(m_pstrTitle);
		}
		mysql_free_result(result);
		//查询是否做过这题
		m_ianswer=LastAnswer(mysql,m_id);	
		return true;
		
	}
	else
	{
		if(nxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choicepoint WHERE  choice_id > \'%d\' AND point_id=\'%d\');",id,pointId);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetPointQue(mysql,point,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choicepoint WHERE  choice_id < \'%d\' AND point_id=\'%d\');",id,pointId);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);

				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choicepoint WHERE  point_id=\'%d\');",pointId);
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					mysql_free_result(result);
					return GetPointQue(mysql,point,id,true);
				}
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
	}
}
bool HChoiceQue::GetWrongQue(MYSQL* mysql,int id,bool isnew,bool isnxt)
{
	char sql_query[2550]="";

	if(isnew==true)
	{
		ZERO(sql_query);
		sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choicewrong WHERE student_id=\'%d\');",m_pstu->m_id);
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		MYSQL_ROW row;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			strcpy(m_pstrTitle,row[1]);
			strcpy(m_pstrA,row[2]);
			strcpy(m_pstrB,row[3]);
			strcpy(m_pstrC,row[4]);
			strcpy(m_pstrD,row[5]);
			strcpy(m_pstrExplain,row[6]);
			sscanf(row[7],"%d",&m_icorrentAnswer);
		}
		mysql_free_result(result);
		//查询是否做过这题
		m_ianswer=LastAnswer(mysql,m_id);	
		return true;
	}
	else
	{
		if(isnxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choicewrong WHERE  choice_id > \'%d\' AND student_id=\'%d\');",id,m_pstu->m_id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetOrderQue(mysql,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choicewrong WHERE  choice_id < \'%d\' AND student_id=\'%d\');",id,m_pstu->m_id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choicewrong WHERE student_id=\'%d\');",m_pstu->m_id);
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					mysql_free_result(result);
					return GetOrderQue(mysql,id,true);
				}
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
	}
}
bool HChoiceQue::GetOrderQue(MYSQL* mysql,int id,bool isnew,bool isnxt)
{
	char sql_query[2550]="";

	if(isnew==true)
	{
		ZERO(sql_query);
		sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choice);");
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		MYSQL_ROW row;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			strcpy(m_pstrTitle,row[1]);
			strcpy(m_pstrA,row[2]);
			strcpy(m_pstrB,row[3]);
			strcpy(m_pstrC,row[4]);
			strcpy(m_pstrD,row[5]);
			strcpy(m_pstrExplain,row[6]);
			sscanf(row[7],"%d",&m_icorrentAnswer);
		}
		mysql_free_result(result);
		//查询是否做过这题
		m_ianswer=LastAnswer(mysql,m_id);	
		return true;
	}
	else
	{
		if(isnxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MIN(choice_id) FROM choice WHERE  choice_id > \'%d\');",id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetOrderQue(mysql,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choice WHERE  choice_id < \'%d\');",id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM choice WHERE choice_id=(SELECT MAX(choice_id) FROM choice);");
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					mysql_free_result(result);
					return GetOrderQue(mysql,id,true);
				}
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				strcpy(m_pstrTitle,row[1]);
				strcpy(m_pstrA,row[2]);
				strcpy(m_pstrB,row[3]);
				strcpy(m_pstrC,row[4]);
				strcpy(m_pstrD,row[5]);
				strcpy(m_pstrExplain,row[6]);
				sscanf(row[7],"%d",&m_icorrentAnswer);
			}
			mysql_free_result(result);
			m_ianswer=LastAnswer(mysql,m_id);	;
			return true;
		}
	}
}

bool HChoiceQue::ChoiceQueAdd(MYSQL* m_pmysql,LPCSTR m_strTitle,LPCSTR m_strA,LPCSTR m_strB,
							  LPCSTR m_strC,LPCSTR m_strD,int m_ianswer,CString m_strPoint,LPCSTR m_strExplain)
{
	char *sql_query=new char[5000];
	if(m_strExplain!=NULL)
	{
		sprintf(sql_query,"INSERT INTO choice (choice_title,choice_A,choice_B,choice_C,choice_D,choice_answer,choice_explain)   \
			values(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%d\',\'%s\')",m_strTitle,m_strA,m_strB,m_strC,m_strD,m_ianswer,m_strExplain);

	}
	else
	{
		sprintf(sql_query,"INSERT INTO choice (choice_title,choice_A,choice_B,choice_C,choice_D,choice_answer)  \
			values(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%d\');",m_strTitle,m_strA,m_strB,m_strC,m_strD,m_ianswer);
	}


	if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
	{
		return FALSE;
	}

	mysql_real_query(m_pmysql,"SELECT LAST_INSERT_ID();",(UINT)strlen("SELECT LAST_INSERT_ID();")+1);
	MYSQL_RES *result=mysql_store_result(m_pmysql);
	MYSQL_ROW row;
	int choiceId;
	while(row = mysql_fetch_row(result))  
	{
		sscanf(row[0],"%d",&choiceId);
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
					return false;
				}

				CString str;
				MYSQL_RES *res;
				int pointId;
				if(!(res=mysql_store_result(m_pmysql)))
				{
					return false;
				}
				if(mysql_num_rows(res)==0)
				{
					sprintf(sql_query,"INSERT INTO point(point_name) VALUES(\'%s\');",p);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						return false;
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
				
				sprintf(sql_query,"SELECT * FROM choicepoint WHERE choice_id=\'%d\' AND point_id=\'%d\';",choiceId,pointId);
				if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
				{
					return false;
				}
				res=mysql_store_result(m_pmysql);
				if(mysql_num_rows(res)==0)
				{
					mysql_free_result(res);
					sprintf(sql_query,"INSERT INTO choicepoint(choice_id,point_id) VALUES(\'%d\',\'%d\');",choiceId,pointId);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						return false;
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
	return true;
}


bool HChoiceQue::ChoiceQueUpdate(MYSQL* m_pmysql,int m_id,LPCSTR m_strTitle,LPCSTR m_strA,LPCSTR m_strB,
							  LPCSTR m_strC,LPCSTR m_strD,int m_ianswer,CString m_strPoint,LPCSTR m_strExplain)
{
	char *sql_query=new char[5000];
	sprintf(sql_query,"UPDATE choice SET choice_title=\'%s\',choice_A=\'%s\',choice_B=\'%s\',choice_C=\'%s\',	\
		choice_D=\'%s\',choice_answer=\'%d\',choice_explain=\'%s\'WHERE choice_id=\'%d\';",
		m_strTitle,m_strA,m_strB,m_strC,m_strD,m_ianswer,m_strExplain,m_id);

	if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
	{
		return FALSE;
	}
	
	sprintf(sql_query,"DELETE FROM choicepoint WHERE choice_id=\'%d\';",m_id);
	if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
	{
		return FALSE;
	}

	//分割考点
	MYSQL_ROW row;
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
					return false;
				}

				CString str;
				MYSQL_RES *res;
				int pointId;
				if(!(res=mysql_store_result(m_pmysql)))
				{
					return false;
				}
				if(mysql_num_rows(res)==0)
				{
					sprintf(sql_query,"INSERT INTO point(point_name) VALUES(\'%s\');",p);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						return false;
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
				
				sprintf(sql_query,"SELECT * FROM choicepoint WHERE choice_id=\'%d\' AND point_id=\'%d\';",m_id,pointId);
				if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
				{
				
					return false;
				}
				res=mysql_store_result(m_pmysql);
				if(mysql_num_rows(res)==0)
				{
					mysql_free_result(res);
					sprintf(sql_query,"INSERT INTO choicepoint(choice_id,point_id) VALUES(\'%d\',\'%d\');",m_id,pointId);
					if(mysql_real_query(m_pmysql,sql_query,(UINT)strlen(sql_query))!=0)
					{
						return false;
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
	m_pstrTitle=(LPSTR)m_strTitle;
	m_pstrA=(LPSTR)m_strA;
	m_pstrB=(LPSTR)m_strB;
	m_pstrC=(LPSTR)m_strC;
	m_pstrD=(LPSTR)m_strD;
	m_pstrExplain=(LPSTR)m_strExplain;
	m_icorrentAnswer=m_ianswer;
	m_id=m_id;
	return true;
}

bool HChoiceQue::GetSameChoice(MYSQL *mysql, int id)
{
	int newid;
	if(-1==(newid=RecommendChoice(mysql,id,m_pstu->m_id)))
	{
		return false;
	}
	GetOrderQue(mysql,newid-1);
	return true;
}
