#if !defined(AFX_OP_QUE_H__2013__12__11__22__32__35__INCLUDED_)
#define AFX_OP_QUE_H__2013__12__11__22__32__35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")
#include "student.h"

class HOpQue{
public:
	bool GetSameOp(MYSQL *mysql,int id);
	bool GetWrongOp(MYSQL* mysql,int id,bool isnew=false,bool isnxt=true);
	int		m_id;
	int		m_nType;
	CString	m_strAns1;
	CString	m_strAns2;
	CString	m_strAns3;
	CString	m_strC;
	CString	m_strExplain;
	CString	m_strIn;
	CString	m_strOut;
	CString	m_strTitle;
	HStudent* m_pstu;
	HOpQue();
	~HOpQue();
	bool GetPointOp(MYSQL* mysql,CString point,int id,bool isnew=false,bool isnxt=true);
	bool GetOrderOp(MYSQL* mysql,int id,bool isnew=false,bool nxt=true);
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C807897C_AA15_4AAD_B08C_F0D404A3B5CF__INCLUDED_)
