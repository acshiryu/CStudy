#if !defined(AFX_CHOICE_QUE_H__2013__12__11__08__44__35__INCLUDED_)
#define AFX_CHOICE_QUE_H__2013__12__11__08__44__35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
#include "student.h"
class HChoiceQue{
public:
	bool GetSameChoice(MYSQL *mysql,int id);
	bool GetWrongQue(MYSQL* mysql,int id,bool isnew=false,bool isnxt=true);
	LPSTR m_pstrTitle;
	LPSTR m_pstrA;
	LPSTR m_pstrB;
	LPSTR m_pstrC;
	LPSTR m_pstrD;
	LPSTR m_pstrExplain;
	int m_icorrentAnswer;
	int m_ianswer;
	int m_id;
	HStudent* m_pstu;
	HChoiceQue();
	~HChoiceQue();
	bool ChoiceQueAdd(MYSQL* m_pmysql,LPCSTR m_strTitle,LPCSTR m_strA,LPCSTR m_strB,
					LPCSTR m_strC,LPCSTR m_strD,int m_ianswer,CString m_strPoint,LPCSTR m_strExplain);
	bool ChoiceQueUpdate(MYSQL* m_pmysql,int m_id,LPCSTR m_strTitle,LPCSTR m_strA,LPCSTR m_strB,
					LPCSTR m_strC,LPCSTR m_strD,int m_ianswer,CString m_strPoint,LPCSTR m_strExplain);
	bool GetPointQue(MYSQL* mysql,CString point,int id,bool isnew=false,bool isnxt=true);
	bool GetOrderQue(MYSQL* mysql,int id,bool isnew=false,bool nxt=true);
	int LastAnswer(MYSQL *mysql,int choiceId);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C807897C_AA15_4AAD_B08C_F0D404A3B5CF__INCLUDED_)
