// IpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "IpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIpDlg dialog


CIpDlg::CIpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIpDlg)
	DDX_Control(pDX, IDC_IPADDRESS, m_ipAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIpDlg, CDialog)
	//{{AFX_MSG_MAP(CIpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIpDlg message handlers

BOOL CIpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	HKEY hkey;
	LPSTR strIP;
	if(RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Server",&hkey)==ERROR_SUCCESS)
	{
		DWORD dwType(0);
		DWORD dwLength(255);
		unsigned char ip[255];
		RegQueryValueEx(hkey,"IP",0,&dwType,ip,&dwLength);
		strIP=(LPSTR)ip;
		RegCloseKey(hkey);
		BYTE ipByte[4];
		sscanf(strIP,"%u.%u.%u.%u",&ipByte[0],&ipByte[1],&ipByte[2],&ipByte[3]);
	//	sprintf(strIP,"%u.%u.%u.%u",ipByte[0],ipByte[1],ipByte[2],ipByte[3]);
	//	AfxMessageBox(strIP);
		m_ipAddress.SetAddress(ipByte[0],ipByte[1],ipByte[2],ipByte[3]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CIpDlg::OnOK() 
{
	// TODO: Add extra validation here
	TCHAR strIP[255]="";
	BYTE ipByte[4];
	m_ipAddress.GetAddress(ipByte[0],ipByte[1],ipByte[2],ipByte[3]);
	sprintf(strIP,"%u.%u.%u.%u",ipByte[0],ipByte[1],ipByte[2],ipByte[3]);
	mysql_options(mysql_init (m_pmysql), MYSQL_SET_CHARSET_NAME, "gb2312");
	if(!mysql_real_connect(m_pmysql,strIP,"root","acshiryu","ac_test_system",3306,NULL,0))
	{
		MessageBox("数据库服务器连接失败","等级考试练习系统");
		return ;
	}
	MessageBox("修改成功","等级考试练习系统");
	HKEY hkey;
	if(RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Server",&hkey)==ERROR_SUCCESS)
	{
		RegSetValueEx(hkey,"IP",0,REG_SZ,(LPBYTE)strIP,strlen(strIP));
		RegCloseKey(hkey);
	}
	CDialog::OnOK();
}
