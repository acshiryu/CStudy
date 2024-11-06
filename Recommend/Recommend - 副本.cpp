#include<afx.h>
#include<winsock.h>
#include<mysql.h>
#include<vector>

using namespace std;

int RecommendChoice(MYSQL* mysql,int choice_id,int student_id)
{
	CString strSQL;
	vector<int>mid;
	MYSQL_RES *res;
	MYSQL_ROW row;

	//查询没做过的题目并且有相同考点的题的sql--推荐题目的最基本要求
	strSQL.Format("SELECT choice_id FROM choice WHERE  choice_id NOT IN	\
		(SELECT choice_id FROM choicerecord WHERE student_id=\'%d\') AND choice_id IN \
		(SELECT cp2.choice_id FROM choicepoint cp1,choicepoint cp2 WHERE \
		cp1.choice_id=\'%d\' AND cp1.point_id=cp2.point_id );",student_id,choice_id);
//	MessageBox(NULL,strSQL,NULL,MB_OK);
	if(0!=mysql_real_query(mysql,strSQL,strSQL.GetLength()+1))
	{
		MessageBox(NULL,"数据库错误",NULL,MB_OK);
		return -1;
	}
	if(0==(res=mysql_store_result(mysql)))
	{
		MessageBox(NULL,"数据库错误",NULL,MB_OK);
		return -1;
	}
	while(row=mysql_fetch_row(res))
	{
		int mTemp;
		sscanf(row[0],"%d",&mTemp);
		mid.push_back(mTemp);
	}
	mysql_free_result(res);

	int nCount;
	int nMaxCount;
	int nMaxId;



	if(mid.size()==0)
	{
		return -1;
	}
	return mid[0];
}
int RecommendOp(MYSQL* mysql,int op_id,int student_id)
{
	return -1;
}