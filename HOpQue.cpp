#include "stdafx.h"
#include "HOpQue.h"
#define ZERO(a) memset((a),0,sizeof(a))

_declspec(dllimport) int RecommendOp(MYSQL* mysql,int op_id,int student_id);

HOpQue::HOpQue()
{

}
HOpQue::~HOpQue()
{
}
bool HOpQue::GetPointOp(MYSQL* mysql,CString point,int id,bool isnew,bool isnxt)
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
		sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM oppoint WHERE point_id=\'%d\');",pointId);
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		MYSQL_ROW row;
		if(mysql_num_rows(result)==0)
			return false;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			m_strTitle=row[1];
			m_strC=row[2];
			m_strIn=row[3];
			m_strOut=row[4];
			m_strAns1=row[5];
			m_strAns2=row[6];
			m_strAns3=row[7];
			m_strExplain=row[8];
			sscanf(row[9],"%d",&m_nType);
		}
		mysql_free_result(result);
		return true;
		
	}
	else
	{
		if(isnxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM oppoint WHERE  op_id > \'%d\' AND point_id=\'%d\');",id,pointId);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetPointOp(mysql,point,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM oppoint WHERE  op_id < \'%d\' AND point_id=\'%d\');",id,pointId);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);

				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM oppoint WHERE  point_id=\'%d\');",pointId);
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					mysql_free_result(result);
					return GetPointOp(mysql,point,id,true);
				}
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
	}
}
bool HOpQue::GetOrderOp(MYSQL* mysql,int id,bool isnew,bool nxt)
{
	char sql_query[5000]="";

	if(isnew==true)
	{
		ZERO(sql_query);
		sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM operating);");
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		if(mysql_num_rows(result)==0)
			return false;
		MYSQL_ROW row;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			m_strTitle=row[1];
			m_strC=row[2];
			m_strIn=row[3];
			m_strOut=row[4];
			m_strAns1=row[5];
			m_strAns2=row[6];
			m_strAns3=row[7];
			m_strExplain=row[8];
			sscanf(row[9],"%d",&m_nType);
		}
		mysql_free_result(result);
		return true;
	}
	else
	{
		if(nxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM operating WHERE  op_id > \'%d\');",id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetOrderOp(mysql,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM operating WHERE  op_id < \'%d\');",id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM operating );");
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					return GetOrderOp(mysql,id,true);
				}
				while(row = mysql_fetch_row(result))  
				{
					sscanf(row[0],"%d",&m_id);
					m_strTitle=row[1];
					m_strC=row[2];
					m_strIn=row[3];
					m_strOut=row[4];
					m_strAns1=row[5];
					m_strAns2=row[6];
					m_strAns3=row[7];
					m_strExplain=row[8];
					sscanf(row[9],"%d",&m_nType);
				}
				mysql_free_result(result);
				return true;
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
	}
}

bool HOpQue::GetWrongOp(MYSQL *mysql, int id, bool isnew, bool isnxt)
{
	char sql_query[5000]="";

	if(isnew==true)
	{
		ZERO(sql_query);
		sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM opwrong WHERE student_id=\'%d\');",m_pstu->m_id);
		if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
			return false;
		MYSQL_RES *result=mysql_store_result(mysql);
		if(mysql_num_rows(result)==0)
			return false;
		MYSQL_ROW row;
		while(row = mysql_fetch_row(result))  
		{
			sscanf(row[0],"%d",&m_id);
			m_strTitle=row[1];
			m_strC=row[2];
			m_strIn=row[3];
			m_strOut=row[4];
			m_strAns1=row[5];
			m_strAns2=row[6];
			m_strAns3=row[7];
			m_strExplain=row[8];
			sscanf(row[9],"%d",&m_nType);
		}
		mysql_free_result(result);
		return true;
	}
	else
	{
		if(isnxt==true)
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MIN(op_id) FROM opwrong WHERE  op_id > \'%d\' AND student_id=\'%d\');",id,m_pstu->m_id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				return GetWrongOp(mysql,id,true);
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
		else
		{
			ZERO(sql_query);
			sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM opwrong WHERE  op_id < \'%d\' AND student_id=\'%d\');",id,m_pstu->m_id);
			if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
				return false;
			MYSQL_RES *result=mysql_store_result(mysql);
			MYSQL_ROW row;
			if(mysql_num_rows(result)==0)
			{
				mysql_free_result(result);
				ZERO(sql_query);
				sprintf(sql_query,"SELECT * FROM operating WHERE op_id=(SELECT MAX(op_id) FROM opwrong WHERE student_id=\'%d\' );",m_pstu->m_id);
				if(0!=mysql_real_query(mysql,sql_query,(UINT)strlen(sql_query)))
					return false;
				result=mysql_store_result(mysql);
				if(mysql_num_rows(result)==0)
				{
					return GetWrongOp(mysql,id,true);
				}
				while(row = mysql_fetch_row(result))  
				{
					sscanf(row[0],"%d",&m_id);
					m_strTitle=row[1];
					m_strC=row[2];
					m_strIn=row[3];
					m_strOut=row[4];
					m_strAns1=row[5];
					m_strAns2=row[6];
					m_strAns3=row[7];
					m_strExplain=row[8];
					sscanf(row[9],"%d",&m_nType);
				}
				mysql_free_result(result);
				return true;
			}
			while(row = mysql_fetch_row(result))  
			{
				sscanf(row[0],"%d",&m_id);
				m_strTitle=row[1];
				m_strC=row[2];
				m_strIn=row[3];
				m_strOut=row[4];
				m_strAns1=row[5];
				m_strAns2=row[6];
				m_strAns3=row[7];
				m_strExplain=row[8];
				sscanf(row[9],"%d",&m_nType);
			}
			mysql_free_result(result);
			return true;
		}
	}
}

bool HOpQue::GetSameOp(MYSQL *mysql, int id)
{
	int newid;
	if(-1==(newid=RecommendOp(mysql,id,m_pstu->m_id)))
	{
		return false;
	}
	GetOrderOp(mysql,newid-1);
	return true;
}
