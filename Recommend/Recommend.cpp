#include<afx.h>
#include<winsock.h>
#include<mysql.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#pragma comment(lib,"libmySQL.lib")
using namespace std;

int RecommendChoice(MYSQL* mysql,int choice_id,int student_id)
{
	CString strSQL;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int mTemp;
	srand(time(NULL));
	strSQL.Format("SELECT COUNT(*) FROM choice");
	if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	if(0==(res=mysql_store_result(mysql)))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	while(row=mysql_fetch_row(res))
	{
		
		sscanf(row[0],"%d",&mTemp);
	}
	mysql_free_result(res);
	return rand()%mTemp+1;
/*
	CString strSQL;
	vector<int>mid;
	MYSQL_RES *res;
	MYSQL_ROW row;

	//��ѯû��������Ŀ��������ͬ��������sql--�Ƽ���Ŀ�������Ҫ��
	strSQL.Format("SELECT choice_id FROM choice WHERE  choice_id<> \'%d\' AND choice_id NOT IN	\
		(SELECT choice_id FROM choicerecord WHERE student_id=\'%d\') AND choice_id IN \
		(SELECT cp2.choice_id FROM choicepoint cp1,choicepoint cp2 WHERE \
		cp1.choice_id=\'%d\' AND cp1.point_id=cp2.point_id );",choice_id,student_id,choice_id);
//	MessageBox(NULL,strSQL,NULL,MB_OK);
	if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	if(0==(res=mysql_store_result(mysql)))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	while(row=mysql_fetch_row(res))
	{
		int mTemp;
		sscanf(row[0],"%d",&mTemp);
		mid.push_back(mTemp);
	}
	mysql_free_result(res);

	
	if(mid.size()==0)
	{
		return -1;
	}
	int nCount;
	int nMaxCount;
	int nMaxId;
	int i;
	for(i=0;i<mid.size();i++)
	{
		nCount=0;
		//�õ���ͬ��������  ��ͬ����������Ӧ��ͬ����
		//1->1 2->5 3->15  4->45 5+->100 
		strSQL.Format("SELECT COUNT(*) FROM choicepoint cp1,choicepoint cp2 WHERE cp2.choice_id=\'%d\' AND cp1.choice_id=\'%d\' AND cp1.point_id=cp2.point_id;",mid[i],choice_id);
		if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		if(0==(res=mysql_store_result(mysql)))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		while(row=mysql_fetch_row(res))
		{
			int mTemp;
			sscanf(row[0],"%d",&mTemp);
			switch(mTemp)
			{
			case 0:
				nCount+=0;
				break;
			case 1:
				nCount+=1;
				break;
			case 2:
				nCount+=5;
				break;
			case 3:
				nCount+=15;
				break;
			case 4:
				nCount+=45;
				break;
			default:
				nCount+=100;
				break;
			}
		}
		mysql_free_result(res);

		//��ѯ��Ŀ���Ϊmid[i]���ύ������ȷ����  ��ȷ��С��0.3��3��,С��0.2��7�֣�С��0.1��12�֣��ύ��ǧ1�֣������3�� ��ʮ�����ϼ�6�� 
		strSQL.Format("SELECT choice_right_num,choice_submit_num FROM choice WHERE choice_id=\'%d\';",mid[i]);
		if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		if(0==(res=mysql_store_result(mysql)))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		while(row=mysql_fetch_row(res))
		{
			int rightNum,submitNum;
			sscanf(row[0],"%d",&rightNum);
			sscanf(row[1],"%d",&submitNum);
			rightNum=submitNum-rightNum;
			if(submitNum>1000)
			{
				nCount+=1;
				if(submitNum>10000)
				{
					nCount+=2;
					if(submitNum>100000)
					{
						nCount+=3;
					}
				}
			}
			if(rightNum<0.3*submitNum)
			{
				nCount+=3;
				if(rightNum<0.2*submitNum)
				{
					nCount+=4;
					if(rightNum<0.1*submitNum)
					{
						nCount+=5;
					}
				}
			}
		}
		mysql_free_result(res);

		//��ѯmid[i]������������
		strSQL.Format("SELECT COUNT(*) FROM choicewrong WHERE choice_id=\'%d\';",mid[i]);
		if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		if(0==(res=mysql_store_result(mysql)))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		while(row=mysql_fetch_row(res))
		{
			int mTemp;
			sscanf(row[0],"%d",&mTemp);
			int t=0;
			while(mTemp)
			{
				if(t>5)
					break;
				nCount+=(1<<t);
				mTemp/=10;
				t++;
			}
		}


		if(nCount>nMaxCount)
		{
			nMaxCount=nCount;
			nMaxId=mid[i];
		}
	}
	return nMaxId;
	*/
}
int RecommendOp(MYSQL* mysql,int op_id,int student_id)
{
	CString strSQL;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int mTemp;
	srand(time(NULL));
	strSQL.Format("SELECT COUNT(*) FROM operating");
	if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	if(0==(res=mysql_store_result(mysql)))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	while(row=mysql_fetch_row(res))
	{
		
		sscanf(row[0],"%d",&mTemp);
	}
	mysql_free_result(res);
	return rand()%mTemp+1;
/*
	CString strSQL;
	vector<int>mid;
	MYSQL_RES *res;
	MYSQL_ROW row;

	//��ѯû��������Ŀ��������ͬ��������sql--�Ƽ���Ŀ�������Ҫ��
	strSQL.Format("SELECT op_id FROM operating WHERE op_id<>\'%d\' AND op_id NOT IN	\
		(SELECT op_id FROM oprecord WHERE student_id=\'%d\') AND op_id IN \
		(SELECT cp2.op_id FROM oppoint cp1,oppoint cp2 WHERE \
		cp1.op_id=\'%d\' AND cp1.point_id=cp2.point_id );",op_id,student_id,op_id);
//	MessageBox(NULL,strSQL,NULL,MB_OK);
	if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	if(0==(res=mysql_store_result(mysql)))
	{
		MessageBox(NULL,"���ݿ����",NULL,MB_OK);
		return -1;
	}
	while(row=mysql_fetch_row(res))
	{
		int mTemp;
		sscanf(row[0],"%d",&mTemp);
		mid.push_back(mTemp);
	}
	mysql_free_result(res);

	
	if(mid.size()==0)
	{
		return -1;
	}
	int nCount;
	int nMaxCount;
	int nMaxId;
	int i;
	for(i=0;i<mid.size();i++)
	{
		nCount=0;
		//�õ���ͬ��������  ��ͬ����������Ӧ��ͬ����
		//1->1 2->5 3->15  4->45 5+->100 
		strSQL.Format("SELECT COUNT(*) FROM oppoint cp1,oppoint cp2 WHERE cp2.op_id=\'%d\' AND cp1.op_id=\'%d\' AND cp1.point_id=cp2.point_id;",mid[i],op_id);
		if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		if(0==(res=mysql_store_result(mysql)))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		while(row=mysql_fetch_row(res))
		{
			int mTemp;
			sscanf(row[0],"%d",&mTemp);
			switch(mTemp)
			{
			case 0:
				nCount+=0;
				break;
			case 1:
				nCount+=1;
				break;
			case 2:
				nCount+=5;
				break;
			case 3:
				nCount+=15;
				break;
			case 4:
				nCount+=45;
				break;
			default:
				nCount+=100;
				break;
			}
		}
		mysql_free_result(res);

		//��ѯmid[i]������������
		strSQL.Format("SELECT COUNT(*) FROM opwrong WHERE op_id=\'%d\';",mid[i]);
		if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		if(0==(res=mysql_store_result(mysql)))
		{
			MessageBox(NULL,"���ݿ����",NULL,MB_OK);
			return -1;
		}
		while(row=mysql_fetch_row(res))
		{
			int mTemp;
			sscanf(row[0],"%d",&mTemp);
			int t=0;
			while(mTemp)
			{
				if(t>5)
					break;
				nCount+=(1<<t);
				mTemp/=10;
				t++;
			}
		}


		if(nCount>nMaxCount)
		{
			nMaxCount=nCount;
			nMaxId=mid[i];
		}
	}
	return nMaxId;
	*/
}