// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Main.h"
#include "MainDlg.h"
#include "student.h"
#include <windows.h>
#include <winreg.h>
#include "winsock.h"
#include "mysql.h"
#include "LoginDlg.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "IpDlg.h"
#include "AddTitleDlg.h"
#include "ChoiceQue.h"
#include "NxtSelectDlg.h"
#include "AddWA.h"
#include "PointDlg.h"
#include "AddOpDlg.h"
#include <direct.h>
#include "SubmitDlg.h"
#include "OpAnsDlg.h"
#pragma comment(lib,"libmySQL.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog
MYSQL mysql;
HStudent stu;
HChoiceQue choiceQue;
HOpQue opQue;
TCHAR kaodian[100];
CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDBTN_MIN, OnMinimize)
	ON_BN_CLICKED(IDBTN_MAINMENU1, OnMainMenu1)
	ON_BN_CLICKED(IDBTN_MAINMENU2, OnMainMenu2)
	ON_BN_CLICKED(IDBTN_MAINMENU3, OnMainMenu3)
	ON_BN_CLICKED(IDBTN_MAINMENU4, OnMainMenu4)
	ON_BN_CLICKED(IDBTN_SONMENU1,OnSonMenu1)
	ON_BN_CLICKED(IDBTN_SONMENU2,OnSonMenu2)
	ON_BN_CLICKED(IDBTN_SONMENU3,OnSonMenu3)
	ON_BN_CLICKED(IDBTN_NEXTDLG1,OnNextDlg1)
	ON_BN_CLICKED(IDBTN_NEXTDLG2,OnNextDlg2)
	ON_BN_CLICKED(IDBTN_CHOICEA, OnChoiceA)
	ON_BN_CLICKED(IDBTN_CHOICEB, OnChoiceB)
	ON_BN_CLICKED(IDBTN_CHOICEC, OnChoiceC)
	ON_BN_CLICKED(IDBTN_CHOICED, OnChoiceD)
	ON_BN_CLICKED(IDBTN_NEWBUTTON1, OnPreChoice)
	ON_BN_CLICKED(IDBTN_NEWBUTTON2, OnNxtChoice)
	ON_BN_CLICKED(IDBTN_NEWBUTTON3, OnSameChoice)
	ON_BN_CLICKED(IDBTN_NEWBUTTON4, OnAddWrong)
	ON_BN_CLICKED(IDBTN_NEWBUTTON5, OnExitChoice)
	ON_BN_CLICKED(IDBTN_OPBUTTON1, OnOpenC)
	ON_BN_CLICKED(IDBTN_OPBUTTON2, OnRecoverC)
	ON_BN_CLICKED(IDBTN_OPBUTTON3, OnPreOp)
	ON_BN_CLICKED(IDBTN_OPBUTTON4, OnNxtOp)
	ON_BN_CLICKED(IDBTN_OPBUTTON5, OnSameOp)
	ON_BN_CLICKED(IDBTN_OPBUTTON6, OnOpAnswer)
	ON_BN_CLICKED(IDBTN_OPBUTTON7, OnAddOpWrong)
	ON_BN_CLICKED(IDBTN_OPBUTTON8, OnExitOp)
	ON_WM_SHOWWINDOW()
	ON_MESSAGE(MSG_DLGINITOK,OnMyMessage)
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	//ȥ��������
//	ModifyStyle(DS_MODALFRAME | WS_CAPTION, 0, 0);
//	ModifyStyle(0, WS_SYSMENU | WS_MINIMIZEBOX);//��Ӧ��С����

	//����ȥ�����������߿�
	//http://blog.csdn.net/hurryboylqs/article/details/5525597
	DWORD dwStyle = GetStyle();//��ȡ����ʽ  
    DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE| WS_SYSMENU |WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_CLIPCHILDREN|WS_CLIPSIBLINGS;  
    dwNewStyle&=dwStyle;//��λ�뽫����ʽȥ��  
    SetWindowLong(m_hWnd,GWL_STYLE,dwNewStyle);//���ó��µ���ʽ  
    DWORD dwExStyle = GetExStyle();//��ȡ����չ��ʽ  
    DWORD dwNewExStyle = WS_EX_LEFT |WS_EX_LTRREADING |WS_EX_RIGHTSCROLLBAR;  
    dwNewExStyle&=dwExStyle;//��λ�뽫����չ��ʽȥ��  
    SetWindowLong(m_hWnd,GWL_EXSTYLE,dwNewExStyle);//�����µ���չ��ʽ  
    SetWindowPos(NULL,0,0,0,0,SWP_NOZORDER|SWP_NOMOVE|SWP_NOSIZE|SWP_FRAMECHANGED);//����windows���ҵ���ʽ�ı��ˣ�����λ�úʹ�С����ԭ�����䣡  
	ModifyStyle(0, WS_SYSMENU | WS_MINIMIZEBOX);

	//���ñ���͸��
//	const WS_EX_LAYERED = 0x80000;
//	::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE, GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
	
	
	//���ó�ʼ��С
	::SetWindowPos(this->m_hWnd,HWND_BOTTOM,0,0,800,600,SWP_NOZORDER);
	CenterWindow();

	//��С��
	m_pbtnMinimize=new CButtonST;
	m_pbtnMinimize->Create("IDBTN_MIN",WS_CHILD | WS_VISIBLE ,
		CRect(697,14,734,38),this,IDBTN_MIN);
	m_pbtnMinimize->SetBitmaps(IDB_MINDOWN,RGB(0,0,0),IDB_MIN,RGB(0,0,0));
	m_pbtnMinimize->OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_pbtnMinimize->DrawBorder(FALSE);
	m_pbtnMinimize->DrawTransparent(TRUE);
	m_pbtnMinimize->SetBtnCursor(IDC_HAND);
	
	//�ر�
	m_pbtnMinimize=new CButtonST;
	m_pbtnMinimize->Create("IDBTN_CLOSE",WS_CHILD | WS_VISIBLE ,
		CRect(736,14,773,38),this,IDBTN_CLOSE);
	m_pbtnMinimize->SetBitmaps(IDB_CLOSEDOWN,RGB(0,0,0),IDB_CLOSE,RGB(0,0,0));
	m_pbtnMinimize->OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_pbtnMinimize->DrawBorder(FALSE);
	m_pbtnMinimize->DrawTransparent(TRUE);
	m_pbtnMinimize->SetBtnCursor(IDC_HAND);

	__InitVariable();
	__ShowMainMenu();
	__HideDownALL();
	m_nCurrentSonNum=-1;
	m_nNextSonNum=0;
	__ShowSonMenu();
	__ShowMenuExplain();
//	Invalidate();
//	UpdateData();

//	PostMessage(MSG_DLGINITOK);
				//���ע��� ������IP��ַ
	HKEY hkey;
	LPSTR strIP;
	if(RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Server",&hkey)!=ERROR_SUCCESS)
	{
		RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Server",&hkey);
		strIP="10.144.98.239";
		RegSetValueEx(hkey,"IP",0,REG_SZ,(LPBYTE)strIP,strlen(strIP));
		RegCloseKey(hkey);
	}
	else
	{
		DWORD dwType(0);
		DWORD dwLength(255);
		unsigned char ip[255];
		RegQueryValueEx(hkey,"IP",0,&dwType,ip,&dwLength);
		strIP=(LPSTR)ip;
		RegCloseKey(hkey);
	}

//	MessageBox(strIP);
	//�������ݿ�
	//mysql_query(&mysql,"SET NAMES 'utf8'");
	mysql_options(mysql_init (&mysql), MYSQL_SET_CHARSET_NAME, "gb2312");//�����ַ����������������� http://www.cnitblog.com/guopingleee/archive/2009/02/13/54526.html
	if(!mysql_real_connect(&mysql,strIP,"root","acshiryu","ac_test_system",3306,NULL,0))
	{
		MessageBox("���ݿ�����ʧ��");
		CIpDlg *pIpDlg=new CIpDlg;
		pIpDlg->m_pmysql=&mysql;
		if(IDOK!=pIpDlg->DoModal())
		{
			EndDialog(IDCANCEL);
			return 1;
		}		
	}

	//��¼

	RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Student",&hkey);
	DWORD dwType(0);
	DWORD dwLength(255);
	unsigned char strLogin[255]="";
	unsigned char strExam[255]="";
	unsigned char strPass[255]="";
	unsigned char strRem[255]="";
	RegQueryValueEx(hkey,"LOGIN",0,&dwType,strLogin,&dwLength);
	dwType=0;
	dwLength=255;
	RegQueryValueEx(hkey,"ExamNum",0,&dwType,strExam,&dwLength);
	dwType=0;
	dwLength=255;
	RegQueryValueEx(hkey,"Password",0,&dwType,strPass,&dwLength);
	dwType=0;
	dwLength=255;
	RegQueryValueEx(hkey,"Rember",0,&dwType,strRem,&dwLength);
	CLoginDlg *plogDlg=new CLoginDlg;
	plogDlg->m_pstu=&stu;
	plogDlg->m_pmysql=&mysql;
	plogDlg->m_examRegId=(LPSTR)strExam;
	plogDlg->m_password=(LPSTR)strPass;
//	plogDlg->m_bRem=false;
//	MessageBox(LPSTR(strRem));
	if(strcmp(LPSTR(strRem),"true")==0)
	{
		plogDlg->m_bRem=true;
	}
	else
	{
		plogDlg->m_bRem=false;
	}
	if(strcmp(LPSTR(strLogin),"AUTO")==0)
	{
		if(stu.Query(&mysql,(LPCSTR)strExam,(LPCSTR)strPass)==FALSE)
		{
			MessageBox("׼��֤�Ż��������","�ȼ�������ϰϵͳ");
			if(IDOK==plogDlg->DoModal())
			{
			//	MessageBox("��½�ɹ�");
			}
			else
			{
			//	MessageBox("������½");
				EndDialog(IDCANCEL);
				return 1;
			}
		}
	}
	else
	{
		if(IDOK==plogDlg->DoModal())
		{
		//	MessageBox("��½�ɹ�");
		}
		else
		{
		//	MessageBox("������½");
			EndDialog(IDCANCEL);
			return 1;
		}
	}
	RegCloseKey(hkey);
	choiceQue.m_pstu=&stu;
	opQue.m_pstu=&stu;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
/*
BOOL CMainDlg::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
*/
void CMainDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	//	CDialog::OnPaint();

		UINT BKGround;
		
		
		switch(m_nNextDlgStatus)
		{
		case DlgSMain:
			
			BKGround=IDB_MAINFRM;
			break;
	//	case DlgSChoice:
	//	case DlgSOperating:
	//	case DlgSWrongQue:
	//	case DlgSCheck:
		default:
			BKGround=IDB_MAINFRM2;
			break;
		}

		//���öԻ��򱳾�ͼ
		CPaintDC  dc(this);  
		CRect  rect;  
		GetClientRect(&rect);  
		CDC  dcMem;  
		dcMem.CreateCompatibleDC(&dc);  
		CBitmap  bmpBackground;  
		bmpBackground.LoadBitmap(BKGround);  //IDB_MAINFRM��������ͼ
		BITMAP  bitmap;  
		bmpBackground.GetBitmap(&bitmap);  
		CBitmap  *pbmpOld=dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  
		m_nCurrentDlgStatus=m_nNextDlgStatus;
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	//���������ʱ�����ƶ��Ի���
	if(point.y<=38)
		SendMessage(WM_SYSCOMMAND,SC_MOVE+HTCAPTION,0);


	CDialog::OnLButtonDown(nFlags, point);
}

void CMainDlg::OnMinimize() 
{
	// TODO: Add your control notification handler code here
	CWnd::ShowWindow(SW_SHOWMINIMIZED);
//	SendMessage()
//	::SendMessage(this->m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

void CMainDlg::__ShowMainMenu()
{
/*4
	UINT MainMenu[4]={IDB_MAINMENU1,IDB_MAINMENU2,IDB_MAINMENU3,IDB_MAINMENU4};
	UINT MainMenuDown[4]={IDB_MAINMENU1DOWN,IDB_MAINMENU2DOWN,IDB_MAINMENU3DOWN,IDB_MAINMENU4DOWN};
	UINT MainMenuButton[4]={IDBTN_MAINMENU1,IDBTN_MAINMENU2,IDBTN_MAINMENU3,IDBTN_MAINMENU4};
	if(m_nCurrentMainNum!=-1)
		m_pbtnMainMenu[m_nCurrentMainNum].SetBitmaps(MainMenu[m_nCurrentMainNum],RGB(0,0,0));
	m_pbtnMainMenu[m_nNextMainNum].SetBitmaps(MainMenuDown[m_nNextMainNum],RGB(0,0,0));

	TCHAR buf[255];
	memset(buf,0,sizeof(buf));
	LoadString(AfxGetInstanceHandle(),MainMenuButton[m_nNextMainNum],buf,254);
	m_pStTitle->SetWindowText(_T(buf));
	m_pStTitle->SetTextColor(RGB(255,255,255));	

	m_nCurrentMainNum=m_nNextMainNum;
*/
	UINT MainMenu[3]={IDB_MAINMENU1,IDB_MAINMENU3,IDB_MAINMENU4};
	UINT MainMenuDown[3]={IDB_MAINMENU1DOWN,IDB_MAINMENU3DOWN,IDB_MAINMENU4DOWN};
	UINT MainMenuButton[3]={IDBTN_MAINMENU1,IDBTN_MAINMENU2,IDBTN_MAINMENU3};
	if(m_nCurrentMainNum!=-1)
		m_pbtnMainMenu[m_nCurrentMainNum].SetBitmaps(MainMenu[m_nCurrentMainNum],RGB(0,0,0));
	m_pbtnMainMenu[m_nNextMainNum].SetBitmaps(MainMenuDown[m_nNextMainNum],RGB(0,0,0));

//	TCHAR buf[255];
//	memset(buf,0,sizeof(buf));
//	LoadString(AfxGetInstanceHandle(),MainMenuButton[m_nNextMainNum],buf,254);
	CString buf[3]={"��ϰ���","����","����"};
	m_pStTitle->SetWindowText(_T(buf[m_nNextMainNum]));
	m_pStTitle->SetTextColor(RGB(255,255,255));	

	m_nCurrentMainNum=m_nNextMainNum;
}

void CMainDlg::__ShowSonMenu()
{
	int nSonTotalNum;
	UINT IDSonMenuStr[4];
	UINT IDB_SonMenu[4];
	UINT IDB_SonMenuDown[4];
	switch(m_nCurrentMainNum)
	{
	case 0:
		nSonTotalNum=3;
		IDSonMenuStr[0]=IDSTR_CHOICE;
		IDSonMenuStr[1]=IDSTR_OPERATING;
		IDSonMenuStr[2]=IDSTR_WRONGQUE;

		IDB_SonMenu[0]=IDB_SONCHOICE;
		IDB_SonMenuDown[0]=IDB_SONCHOICEDOWN;

		IDB_SonMenu[1]=IDB_SONOPERATING;
		IDB_SonMenuDown[1]=IDB_SONOPERATINGDOWN;

		IDB_SonMenu[2]=IDB_SONWRONGQUE;
		IDB_SonMenuDown[2]=IDB_SONWRONGQUEDOWN;

		break;
		//ԭcase 1:
	case 3:	//ԭcase 1:
		nSonTotalNum=2;
		IDSonMenuStr[0]=IDSTR_EXAM;
		IDSonMenuStr[1]=IDSTR_CONTINUE;

		IDB_SonMenu[0]=IDB_SONEXAM;
		IDB_SonMenuDown[0]=IDB_SONEXAMDOWN;
		
		IDB_SonMenu[1]=IDB_SONCONTINUE;
		IDB_SonMenuDown[1]=IDB_SONCONTINUEDOWN;
		break;
		//ԭ case2:
	case 1:
		if(stu.m_admin==true)
		{
			nSonTotalNum=3;
		}
		else
		{
			nSonTotalNum=1;
		}
		IDSonMenuStr[0]=IDSTR_SETTING;
		IDSonMenuStr[1]=IDSTR_CHECK;
		IDSonMenuStr[2]=IDSTR_ADD;

		IDB_SonMenu[0]=IDB_SONSETTING;
		IDB_SonMenuDown[0]=IDB_SONSETTINGDOWN;

		IDB_SonMenu[1]=IDB_SONCHECK;
		IDB_SonMenuDown[1]=IDB_SONCHECKDOWN;
		
		IDB_SonMenu[2]=IDB_SONADD;
		IDB_SonMenuDown[2]=IDB_SONADDDOWN;
		break;
		//ԭcase 3:
	case 2:
		nSonTotalNum=3;
		IDSonMenuStr[0]=IDSTR_ABOUT;
		IDSonMenuStr[1]=IDSTR_CONTACT;
		IDSonMenuStr[1]=IDSTR_THANKS;
		
		IDB_SonMenu[0]=IDB_SONABOUT;
		IDB_SonMenuDown[0]=IDB_SONABOUTDOWN;

		IDB_SonMenu[1]=IDB_SONCONTACT;
		IDB_SonMenuDown[1]=IDB_SONCONTACTDOWN;
		
		IDB_SonMenu[2]=IDB_SONTHANKS;
		IDB_SonMenuDown[2]=IDB_SONTHANKSDOWN;
		break;
	case -1:
		break;
	default:
		break;
	}
	
	int i;
	for(i=0;i<m_nSonMenuTotalNum;i++)
	{
		i<nSonTotalNum?m_pbtnSonMenu[i].ShowWindow(SW_SHOW):m_pbtnSonMenu[i].ShowWindow(SW_HIDE);
	}
	if(m_nCurrentSonNum==-1)
	{
		for(i=0;i<nSonTotalNum;i++)
			m_pbtnSonMenu[i].SetBitmaps(IDB_SonMenu[i],RGB(228,228,228));
		m_pbtnSonMenu[m_nNextSonNum].SetBitmaps(IDB_SonMenuDown[m_nNextSonNum],RGB(228,228,228));
	}
	else
	{
		m_pbtnSonMenu[m_nCurrentSonNum].SetBitmaps(IDB_SonMenu[m_nCurrentSonNum],RGB(228,228,228));
		m_pbtnSonMenu[m_nNextSonNum].SetBitmaps(IDB_SonMenuDown[m_nNextSonNum],RGB(228,228,228));
	}


	m_nCurrentSonNum=m_nNextSonNum;

}
void CMainDlg::OnMainMenu(int nMainMenuNum)
{
	m_nNextDlgStatus=DlgSMain;
	m_nNextMainNum=nMainMenuNum;
	if(m_nCurrentMainNum==m_nNextMainNum)
	{
		if(m_nCurrentDlgStatus==DlgSMain)
		{
			return ;
		}
		else
		{
			int t=MessageBox(_T("ȷ���ص������棿"),_T("�ȼ�������ϰϵͳ"),MB_OKCANCEL);
			if(t==IDOK)
			{
				m_nChoiceAns=-1;
				__HideDownALL();
				__ShowSonMenu();
				__ShowMenuExplain();
				m_nNextDlgStatus=DlgSMain;
				Invalidate();
				UpdateData();
			}
			else
			{
				return ;
			}
		}
	}
	else
	{
		if(m_nCurrentDlgStatus==DlgSMain)
		{
			__ShowMainMenu();
			m_nCurrentSonNum=-1;
			m_nNextSonNum=0;
			__ShowSonMenu();
			__ShowMenuExplain();
		}
		else
		{
			int t=MessageBox(_T("ȷ���ص������棿"),_T("�ȼ�������ϰϵͳ"),MB_OKCANCEL);
			if(t==IDOK)
			{
				m_nChoiceAns=-1;
				__ShowMainMenu();
				__HideDownALL();
				m_nCurrentSonNum=-1;
				m_nNextSonNum=0;
				__ShowSonMenu();
				__ShowMenuExplain();
				m_nNextDlgStatus=DlgSMain;
				Invalidate();
				UpdateData();
			}
			else
			{
				return ;
			}
		}
	}
//	Invalidate();
//	UpdateData();
}
void CMainDlg::OnMainMenu1()
{
	OnMainMenu(0);
}

void CMainDlg::OnMainMenu2()
{
	OnMainMenu(1);
}

void CMainDlg::OnMainMenu3()
{
	OnMainMenu(2);
}

void CMainDlg::OnMainMenu4()
{
	OnMainMenu(3);
}

void CMainDlg::__InitVariable()
{//��ʼ���ڲ�����

	int i;
	//��ʼ�����˵� 4��
//	UINT MainMenu[4]={IDB_MAINMENU1,IDB_MAINMENU2,IDB_MAINMENU3,IDB_MAINMENU4};
//	UINT MainMenuDown[4]={IDB_MAINMENU1DOWN,IDB_MAINMENU2DOWN,IDB_MAINMENU3DOWN,IDB_MAINMENU4DOWN};
//	UINT MainMenuButton[4]={IDBTN_MAINMENU1,IDBTN_MAINMENU2,IDBTN_MAINMENU3,IDBTN_MAINMENU4};
//	m_pbtnMainMenu=new CButtonST[4];
//	m_nCurrentMainNum=-1;
//	m_nNextMainNum=0;
	//��ʼ�����˵� 3��
	UINT MainMenu[3]={IDB_MAINMENU1,IDB_MAINMENU3,IDB_MAINMENU4};
	UINT MainMenuDown[3]={IDB_MAINMENU1DOWN,IDB_MAINMENU3DOWN,IDB_MAINMENU4DOWN};
	UINT MainMenuButton[3]={IDBTN_MAINMENU1,IDBTN_MAINMENU2,IDBTN_MAINMENU3};
	m_pbtnMainMenu=new CButtonST[3];
	m_nCurrentMainNum=-1;
	m_nNextMainNum=0;
	for(i=0;i<3;i++)
	{
		m_pbtnMainMenu[i].Create("",WS_CHILD | WS_VISIBLE,CRect(25+115*i,42,132+115*i,115),this,MainMenuButton[i]);
		m_pbtnMainMenu[i].SetBitmaps(MainMenu[i],RGB(0,0,0));
		m_pbtnMainMenu[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
		m_pbtnMainMenu[i].DrawBorder(FALSE);
		m_pbtnMainMenu[i].DrawTransparent(TRUE);
		m_pbtnMainMenu[i].SetBtnCursor(IDC_HAND);
	}

	//����LOGO
	CButtonST *btnLogo=new CButtonST;
	btnLogo->Create("",WS_CHILD | WS_VISIBLE ,CRect(477,50,777,110),this,IDBTN_LOGO);
	btnLogo->m_bShowDisabledBitmap = FALSE;
	btnLogo->SetBitmaps(IDB_LOGO2,RGB(151,210,255));
	btnLogo->OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	btnLogo->DrawBorder(FALSE);
	btnLogo->DrawTransparent(TRUE);
	btnLogo->EnableWindow(false);

	//��ʼ���Ӳ˵�  3��
	m_nSonMenuTotalNum=3;
	m_pbtnSonMenu=new CButtonST[m_nSonMenuTotalNum];
	for(i=0;i<m_nSonMenuTotalNum;i++)
	{
		m_pbtnSonMenu[i].Create("",WS_CHILD | WS_VISIBLE  |BS_AUTO3STATE ,
			CRect(24,170+100*i,227,248+100*i),this,IDBTN_SONMENU1+i);
		m_pbtnSonMenu[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
		m_pbtnSonMenu[i].DrawBorder(FALSE);
		m_pbtnSonMenu[i].DrawTransparent(TRUE);
		m_pbtnSonMenu[i].SetBtnCursor(IDC_HAND);
		m_pbtnSonMenu[i].ShowWindow(SW_SHOW);
	}
	
	//��ʼ���˵�����
	CFont *pstfont=new CFont;
	pstfont->CreateFont(25,0,0,0,FW_BOLD,TRUE,        // bItalic 
		FALSE,       // bUnderline 
		0,           // cStrikeOut 
		ANSI_CHARSET,              // nCharSet 
		OUT_DEFAULT_PRECIS,        // nOutPrecision 
		CLIP_DEFAULT_PRECIS,       // nClipPrecision 
		DEFAULT_QUALITY,           // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("Arial")
	);
	m_pStTitle=new CTransparentStatic;
	m_pStTitle->Create(_T(""),WS_CHILD|WS_VISIBLE,CRect(25,125,200,150),this,IDS_MAINMENUTITLE);	
	m_pStTitle->SetFont(pstfont);

	//��ʼ���˵�˵��
	CFont *pExpfont=new CFont;
	pExpfont->CreateFont(25,0,0,0,FW_NORMAL,
		FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_RASTER_PRECIS,CLIP_DEFAULT_PRECIS,
        VARIABLE_PITCH|PROOF_QUALITY,FF_DONTCARE,"����"
	);
	
	m_pStExplain=new CTransparentStatic;
	m_pStExplain->Create(_T(""),WS_CHILD|WS_VISIBLE,CRect(300,215,738,450),this,IDS_EXPLAIN);	
	m_pStExplain->SetFont(pExpfont);

	//��ʼ���˵�˵����������ť
	m_pbtnNextDlg=new CButtonST[2];
	CFont *pDlgFont=new CFont;
	pDlgFont->CreatePointFont(180,_T("����"));
	for(i=0;i<2;i++)
	{
		m_pbtnNextDlg[i].Create(_T(""),WS_CHILD | WS_VISIBLE ,CRect(450+150*i,455,563+150*i,484),this,IDBTN_NEXTDLG1+i);
		m_pbtnNextDlg[i].SetBitmaps(IDB_NEXTDLGDOWN,RGB(228,228,228),IDB_NEXTDLG,RGB(228,228,228));
		m_pbtnNextDlg[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 50);
		m_pbtnNextDlg[i].DrawBorder(FALSE);
		m_pbtnNextDlg[i].DrawTransparent(TRUE);
		m_pbtnNextDlg[i].SetBtnCursor(IDC_HAND);
		m_pbtnNextDlg[i].ShowWindow(SW_HIDE);
		m_pbtnNextDlg[i].SetAlign(CButtonST::ST_ALIGN_CENTER);
		m_pbtnNextDlg[i].SetFont(pDlgFont);	
	}

	//��ʼ��������״̬
	m_nCurrentDlgStatus=NODlgS;
	m_nNextDlgStatus=DlgSMain;

	//��ʼ��ѡ�������
	m_pdtQueTitle=new CEdit;
	m_pdtQueTitle->Create(WS_VSCROLL|WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_MULTILINE|ES_WANTRETURN|ES_READONLY,
		CRect(17,156,781,250),this,IDDT_QUETITLE);
	m_pdtQueTitle->SetFont(pExpfont);

	//��ʼ���ĸ�ѡ����ѡ��
	m_pbtnChoiceAns=new CButtonST[4];
	for(i=0;i<4;i++)
	{
		m_pbtnChoiceAns[i].Create(_T(""),WS_CHILD | WS_VISIBLE  ,CRect(18,260+68*i,510,324+68*i),this,IDBTN_CHOICEA+i);
		m_pbtnChoiceAns[i].SetBitmaps(IDB_CHOICEANSDOWN,RGB(228,228,228),IDB_CHOICEANS,RGB(228,228,228));
		m_pbtnChoiceAns[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 50);
		m_pbtnChoiceAns[i].DrawBorder(FALSE);
		m_pbtnChoiceAns[i].DrawTransparent(TRUE);
		m_pbtnChoiceAns[i].SetBtnCursor(IDC_HAND);
		m_pbtnChoiceAns[i].ShowWindow(SW_HIDE);
		m_pbtnChoiceAns[i].SetAlign(CButtonST::ST_ALIGN_LEFTTEXT);
		m_pbtnChoiceAns[i].SetFont(pDlgFont);	
	}
	m_nChoiceAns=-1;

	//��ʼ��ѡ����𰸽���
	m_pdtChoiceExplain=new CEdit;
	m_pdtChoiceExplain->Create(WS_VSCROLL|WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_MULTILINE|ES_WANTRETURN|ES_READONLY,
		CRect(520,260,781,565),this,IDDT_CHOICEEXPLAIN);
	m_pdtChoiceExplain->SetFont(pExpfont);

	//��ʼ���½��������ť
	CFont *pNewBtnFont=new CFont;
	pNewBtnFont->CreatePointFont(150,_T("����"));
	m_pbtnNewButton=new CButtonST[5];
	for(i=0;i<5;i++)
	{
		m_pbtnNewButton[i].Create(_T(""),WS_CHILD | WS_VISIBLE  ,CRect(18+100*i,530,109+100*i,563),this,IDBTN_NEWBUTTON1+i);
		m_pbtnNewButton[i].SetBitmaps(IDB_NEWBUTTONDOWN,RGB(228,228,228),IDB_NEWBUTTON,RGB(228,228,228));
		m_pbtnNewButton[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 50);
		m_pbtnNewButton[i].DrawBorder(FALSE);
		m_pbtnNewButton[i].DrawTransparent(TRUE);
		m_pbtnNewButton[i].SetBtnCursor(IDC_HAND);
		m_pbtnNewButton[i].ShowWindow(SW_HIDE);
		m_pbtnNewButton[i].SetAlign(CButtonST::ST_ALIGN_CENTER);
		m_pbtnNewButton[i].SetFont(pNewBtnFont);	
	}

	//��ʼ�����������
	m_pdtOpTitle=new CEdit;
	m_pdtOpTitle->Create(WS_VSCROLL|WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_MULTILINE|ES_WANTRETURN|ES_READONLY,
		CRect(17,156,644,564),this,IDDT_QUETITLE);
	m_pdtOpTitle->SetFont(pExpfont);


	//��ʼ��������8����ť
	m_pbtnOpButton=new CButtonST[8];
	CString strText[8]={"���ļ�","�ָ��ļ�","��һ��","��һ��","ͬ���Ƽ�","�鿴���","�������","����"};
	for(i=0;i<8;i++)
	{
		m_pbtnOpButton[i].Create(_T(""),WS_CHILD | WS_VISIBLE  ,CRect(668,180+45*i,759,213+45*i),this,IDBTN_OPBUTTON1+i);
		m_pbtnOpButton[i].SetBitmaps(IDB_NEWBUTTONDOWN,RGB(228,228,228),IDB_NEWBUTTON,RGB(228,228,228));
		m_pbtnOpButton[i].OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 50);
		m_pbtnOpButton[i].DrawBorder(FALSE);
		m_pbtnOpButton[i].DrawTransparent(TRUE);
		m_pbtnOpButton[i].SetBtnCursor(IDC_HAND);
		m_pbtnOpButton[i].ShowWindow(SW_SHOW);
		m_pbtnOpButton[i].SetAlign(CButtonST::ST_ALIGN_CENTER);
		m_pbtnOpButton[i].SetFont(pNewBtnFont);	
		m_pbtnOpButton[i].SetWindowText(strText[i]);
	}

}
void CMainDlg::OnSonMenu1()
{
	OnSonMenu(0);
}

void CMainDlg::OnSonMenu2()
{
	OnSonMenu(1);
}

void CMainDlg::OnSonMenu3()
{
	OnSonMenu(2);
}

void CMainDlg::OnSonMenu(int nNextSonNum)
{
	if(m_nCurrentSonNum==nNextSonNum)
	{
		return ;
	}
	m_nNextSonNum=nNextSonNum;
	__ShowSonMenu();
	__ShowMenuExplain();
}

void CMainDlg::OnNextDlg1()
{
	OnNextDlg(0);
}

void CMainDlg::OnNextDlg2()
{
	OnNextDlg(1);
}

void CMainDlg::OnNextDlg(int nNextDlgNum)
{
	m_nNextDlgNum=nNextDlgNum;
	CNxtSelectDlg nxtDlg;
	CPointDlg pointDlg;
	int kind=m_nCurrentMainNum*m_nSonMenuTotalNum+m_nCurrentSonNum;
	switch(kind)
	{
	case 0://choice
		if(nNextDlgNum==0)
		{
			pointDlg.CQue=&choiceQue;
			pointDlg.mysql=&mysql;
			pointDlg.m_nkind=1;
			if(IDOK==pointDlg.DoModal())
			{                                                                                                                                                                                                                     
				m_nNextDlgStatus=DlgSChoice;
				strcpy(kaodian,pointDlg.strTemp);
				__HideMain();
				__ShowChoice();
			}
		}
		else
		{
			nxtDlg.CQue=&choiceQue;
			nxtDlg.mysql=&mysql;
			nxtDlg.m_nkind=1;
		//	nxtDlg.nxtDlgNum=nNextDlgNum;
			if(IDOK==nxtDlg.DoModal())
			{
				m_nNextDlgStatus=DlgSChoice;
				__HideMain();
				__ShowChoice();
			}
		}
		break;
	case 1://operating
		if(nNextDlgNum==0)
		{
			pointDlg.opQue=&opQue;
			pointDlg.mysql=&mysql;
			pointDlg.m_nkind=2;
			if(IDOK==pointDlg.DoModal())
			{                                                                                                                                                                                                                     
				m_nNextDlgStatus=DlgSOperating;
				strcpy(kaodian,pointDlg.strTemp);
				__HideMain();
				__ShowOperating();
			}
		}
		else
		{
			nxtDlg.opQue=&opQue;
			nxtDlg.mysql=&mysql;
			nxtDlg.m_nkind=2;
//			nxtDlg.nxtDlgNum=nNextDlgNum;
			if(IDOK==nxtDlg.DoModal())
			{
				m_nNextDlgStatus=DlgSOperating;
				__HideMain();
				__ShowOperating();
			}
		}
		break;
	case 2://wrongQue
		
		if(nNextDlgNum==0)
		{//choice
			if(false==choiceQue.GetWrongQue(&mysql,0,true))
			{
				MessageBox("û�д���");
				return ;
			}
			m_nNextDlgStatus=DlgSWrongQue;
			__HideMain();
			__ShowChoice();
		}
		else
		{//operating
			if(false==opQue.GetWrongOp(&mysql,0,true))
			{
				MessageBox("û�д���");
				return ;
			}
			m_nNextDlgStatus=DlgSWrongQue;
			__HideMain();
			__ShowOperating();
		}
		break;
//	case 6://setting
	case 3:
		if(m_nNextDlgNum==0)
		{
			CIpDlg *pIpDlg=new CIpDlg;
			pIpDlg->m_pmysql=&mysql;
			if(IDOK==pIpDlg->DoModal())
			{
				MessageBox("IP�޸ĳɹ�");
			//	EndDialog(IDCANCEL);
			//	return 1;
			}	
		}
		else
		{
			if(IDOK==MessageBox("ȷ�ϻָ���Ĭ�ϣ�","�ȼ�������ϰϵͳ",MB_OKCANCEL))
			{
				HKEY hkey;

				RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Server",&hkey);
				RegSetValueEx(hkey,"IP",0,REG_SZ,(LPBYTE)"127.0.0.1",strlen("127.0.0.1"));
				RegCloseKey(hkey);
				RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\acshiryu\\Student",&hkey);
				RegSetValueEx(hkey,"ExamNum",0,REG_SZ,(LPBYTE)"",strlen(""));
				RegSetValueEx(hkey,"LOGIN",0,REG_SZ,(LPBYTE)"CLICK",strlen("CLICK"));
				RegSetValueEx(hkey,"password",0,REG_SZ,(LPBYTE)"",strlen(""));
				RegSetValueEx(hkey,"Rember",0,REG_SZ,(LPBYTE)"false",strlen("false"));
				RegCloseKey(hkey);
				MessageBox("��ʼ���ɹ�������������","�ȼ�������ϰϵͳ");
			}
		}
		break;
//	case 7://check
	case 4:
		if(stu.m_admin!=true)
		{
			MessageBox(_T("��������ĿȨ�ޣ�����ϵ����Ա"),_T("�ȼ�������ϰϵͳ"));
			return ;
		}
		if(m_nNextDlgNum==0)
		{
			nxtDlg.CQue=&choiceQue;
			nxtDlg.mysql=&mysql;
			nxtDlg.m_nkind=1;
//			nxtDlg.nxtDlgNum=1;
			if(IDOK==nxtDlg.DoModal())
			{
				m_nNextDlgStatus=DlgSCheck;
				__HideMain();
				__ShowChoice();
			}
		}
		else
		{
			nxtDlg.opQue=&opQue;
			nxtDlg.mysql=&mysql;
			nxtDlg.m_nkind=2;
			if(IDOK==nxtDlg.DoModal())
			{
				m_nNextDlgStatus=DlgSCheck;
				__HideMain();
				__ShowOperating();
			}
		}
		break;
//	case 8://add
	case  5:
		if(stu.m_admin!=true)
		{
			MessageBox(_T("��������ĿȨ�ޣ�����ϵ����Ա"),_T("�ȼ�������ϰϵͳ"));
			return ;
		}
		if(m_nNextDlgNum==0)
		{
			CAddTitleDlg *paddTitleDlg=new CAddTitleDlg;
			paddTitleDlg->m_pmysql=&mysql;
			paddTitleDlg->DoModal();
		}
		else
		{
			CAddOpDlg *paddOpDlg=new CAddOpDlg;
			paddOpDlg->m_pmysql=&mysql;
			paddOpDlg->DoModal();
		}
		break;
	default:
		break;
	}
	Invalidate();
	UpdateData();
}

void CMainDlg::__ShowMenuExplain()
{
	UINT IDSTR_Explain[][3]={
		{IDSTR_CHOICE,IDSTR_OPERATING,IDSTR_WRONGQUE},
		{IDSTR_SETTING,IDSTR_CHECK,IDSTR_ADD},
		{IDSTR_ABOUT,IDSTR_CONTACT,IDSTR_THANKS},
		{IDSTR_EXAM,IDSTR_CONTINUE},
	};

	TCHAR buf[255]={0};
	LoadString(AfxGetInstanceHandle(),
		IDSTR_Explain[m_nCurrentMainNum][m_nCurrentSonNum],buf,sizeof(buf)/sizeof(TCHAR));
	m_pStExplain->SetWindowText(_T(buf));

	switch(IDSTR_Explain[m_nCurrentMainNum][m_nCurrentSonNum])
	{
	case IDSTR_CHOICE:
	case IDSTR_OPERATING:
		m_pbtnNextDlg[0].ShowWindow(SW_SHOW);
		m_pbtnNextDlg[1].ShowWindow(SW_SHOW);
		LoadString(AfxGetInstanceHandle(),IDSTR_POINT,buf,sizeof(buf)/sizeof(TCHAR));
		m_pbtnNextDlg[0].SetWindowText(_T(buf));
		LoadString(AfxGetInstanceHandle(),IDSTR_SEQUENCE,buf,sizeof(buf)/sizeof(TCHAR));
		m_pbtnNextDlg[1].SetWindowText(_T(buf));

		break;
	case IDSTR_ADD:
	case IDSTR_WRONGQUE:
	case IDSTR_CHECK:
		m_pbtnNextDlg[0].ShowWindow(SW_SHOW);
		m_pbtnNextDlg[1].ShowWindow(SW_SHOW);
		m_pbtnNextDlg[0].SetWindowText(_T("ѡ����"));
		m_pbtnNextDlg[1].SetWindowText(_T("������"));
		break;
	case IDSTR_SETTING:
		m_pbtnNextDlg[0].ShowWindow(SW_SHOW);
		m_pbtnNextDlg[1].ShowWindow(SW_SHOW);
		m_pbtnNextDlg[0].SetWindowText(_T("����"));
		m_pbtnNextDlg[1].SetWindowText(_T("��ʼ��"));
		break;
	default:
		m_pbtnNextDlg[0].ShowWindow(SW_HIDE);
		m_pbtnNextDlg[1].ShowWindow(SW_HIDE);
		break;
	}
}
void CMainDlg::__HideDownALL()
{
	int i;
	for(i=0;i<m_nSonMenuTotalNum;i++)
		m_pbtnSonMenu[i].ShowWindow(SW_HIDE);

	m_pStExplain->ShowWindow(SW_HIDE);

	m_pbtnNextDlg[0].ShowWindow(SW_HIDE);
	m_pbtnNextDlg[1].ShowWindow(SW_HIDE);

	m_pdtQueTitle->ShowWindow(SW_HIDE);

	for(i=0;i<4;i++)
	{
		m_pbtnChoiceAns[i].ShowWindow(SW_HIDE);
	}

	m_pdtChoiceExplain->ShowWindow(SW_HIDE);

	for(i=0;i<5;i++)
	{
		m_pbtnNewButton[i].ShowWindow(SW_HIDE);
	}
	m_pdtOpTitle->ShowWindow(SW_HIDE);
	for(i=0;i<8;i++)
	{
		m_pbtnOpButton[i].ShowWindow(SW_HIDE);
	}
}
void CMainDlg::__HideMain()
{
	int i;
	for(i=0;i<m_nSonMenuTotalNum;i++)
		m_pbtnSonMenu[i].ShowWindow(SW_HIDE);
	
	m_pStExplain->ShowWindow(SW_HIDE);
	
	m_pbtnNextDlg[0].ShowWindow(SW_HIDE);
	m_pbtnNextDlg[1].ShowWindow(SW_HIDE);
}

void CMainDlg::OnPreChoice()
{
	if(m_nNextDlgStatus==DlgSChoice)
	{
		if(m_nNextDlgNum==0)
		{
			choiceQue.GetPointQue(&mysql,kaodian,choiceQue.m_id,false,false);
			m_nChoiceAns=-1;
		}
		else
		{
			choiceQue.GetOrderQue(&mysql,choiceQue.m_id,false,false);
			m_nChoiceAns=-1;
		}
	}
	else if(m_nNextDlgStatus==DlgSWrongQue)
	{
		choiceQue.GetWrongQue(&mysql,choiceQue.m_id,false,false);
		m_nChoiceAns=-1;
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		choiceQue.GetOrderQue(&mysql,choiceQue.m_id,false,false);
		m_nChoiceAns=-1;
	}
	__ShowChoice();
}
void CMainDlg::OnNxtChoice()
{
	if(m_nNextDlgStatus==DlgSChoice)
	{
		if(m_nNextDlgNum==0)
		{
			choiceQue.GetPointQue(&mysql,kaodian,choiceQue.m_id,false,true);
			m_nChoiceAns=-1;
		}
		else
		{
			choiceQue.GetOrderQue(&mysql,choiceQue.m_id,false,true);
			m_nChoiceAns=-1;
		}
	}
	else if(m_nNextDlgStatus==DlgSWrongQue)
	{
		choiceQue.GetWrongQue(&mysql,choiceQue.m_id,false,true);
		m_nChoiceAns=-1;
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		choiceQue.GetOrderQue(&mysql,choiceQue.m_id,false,true);
		m_nChoiceAns=-1;
	}
	__ShowChoice();
}
void CMainDlg::OnSameChoice()
{
	switch(m_nNextDlgStatus)
	{
	case DlgSChoice:
	case DlgSWrongQue:
	//	MessageBox("��δ��������ȴ�");
		if(true==choiceQue.GetSameChoice(&mysql,choiceQue.m_id))
		{
			m_nChoiceAns=-1;
			__ShowChoice();
		}
		else
		{
			MessageBox("û����Ŀ���Ƽ�");
		}
		break;
	case DlgSCheck:
		CAddTitleDlg *paddTitleDlg=new CAddTitleDlg;
		paddTitleDlg->m_pmysql=&mysql;
		paddTitleDlg->m_id=choiceQue.m_id;
		paddTitleDlg->m_choiceQue=&choiceQue;
		if(IDOK==paddTitleDlg->DoModal())
		{
			__ShowChoice();
		}
		break;
	}
}
void CMainDlg::OnAddWrong()
{
	CAddWA* addWA;
	CSubmitDlg *subDlg;
	switch(m_nNextDlgStatus)
	{
	case DlgSChoice:
	case DlgSWrongQue:
		addWA=new CAddWA;
		addWA->mysql=&mysql;
		addWA->stu_id=stu.m_id;
		addWA->choice_id=choiceQue.m_id;
		addWA->operating_id=-1;
		if(IDOK==addWA->DoModal())
		{
			
		}
		break;
	case DlgSCheck:
		subDlg=new CSubmitDlg;
		subDlg->nkind=1;
		subDlg->choice_id=choiceQue.m_id;
		subDlg->mysql=&mysql;
		subDlg->DoModal();
		break;
	}

}
void CMainDlg::OnExitChoice()
{
	m_nChoiceAns=-1;
	__HideDownALL();
	__ShowSonMenu();
	__ShowMenuExplain();
	m_nNextDlgStatus=DlgSMain;
	Invalidate();
	UpdateData();
}
void CMainDlg::__ShowChoice()
{
	TCHAR title[1000]="";
	sprintf(title,"ѡ����%d:\r\n    %s\r\nA. %s\r\nB. %s\r\nC. %s\r\nD. %s",choiceQue.m_id,choiceQue.m_pstrTitle,choiceQue.m_pstrA,choiceQue.m_pstrB,choiceQue.m_pstrC,choiceQue.m_pstrD);
	m_pdtQueTitle->SetWindowText(_T(title));
	m_pdtQueTitle->ShowWindow(SW_SHOW);

	int nChoiceAns=choiceQue.m_icorrentAnswer;
	for(int i=0;i<4;i++)
	{
		m_pbtnChoiceAns[i].ShowWindow(SW_SHOW);
	}
	m_pdtChoiceExplain->ShowWindow(SW_SHOW);
	if(m_nNextDlgStatus!=DlgSCheck)
	{
		if(m_nChoiceAns==-1)
		{
			LPSTR ANS[4]={choiceQue.m_pstrA,choiceQue.m_pstrB,choiceQue.m_pstrC,choiceQue.m_pstrD};
			for(int i=0;i<4;i++)
			{
				TCHAR output[500]="";
				sprintf(output,"%c. %s",i+'A',ANS[i]);
				m_pbtnChoiceAns[i].SetWindowText(_T(output));
				m_pbtnChoiceAns[i].SetBitmaps(IDB_CHOICEANS,RGB(228,228,228));
			}
			m_pdtChoiceExplain->SetWindowText(_T(""));
		}
		else
		{
			LPSTR yesStr;
			TCHAR sql_query2[255]="";
			if(m_nChoiceAns!=nChoiceAns)
			{
				m_pbtnChoiceAns[m_nChoiceAns].SetBitmaps(IDB_CHOICEANSNO,RGB(228,228,228));
				yesStr="no";
				sprintf(sql_query2,"UPDATE choice SET choice_submit_num=choice_submit_num+1 WHERE choice_id=\'%d\';",choiceQue.m_id);
			}
			else
			{
				yesStr="yes";
				sprintf(sql_query2,"UPDATE choice SET choice_submit_num=choice_submit_num+1 ,choice_right_num=choice_right_num+1 WHERE choice_id=\'%d\';",choiceQue.m_id);
			}
			mysql_real_query(&mysql,sql_query2,sizeof(sql_query2));
			m_pbtnChoiceAns[nChoiceAns].SetBitmaps(IDB_CHOICEANSYES,RGB(228,228,228));		
			m_pdtChoiceExplain->SetWindowText(_T(choiceQue.m_pstrExplain));

			//TODO zengjiazuotijilu;
			TCHAR sql_query[255]="";
			sprintf(sql_query,"INSERT INTO choicerecord(student_id,choice_id,choicerecord_isyes,choicerecord_answer) VALUES(\'%d\',\'%d\',\'%s\',\'%d\');",stu.m_id,choiceQue.m_id,yesStr,m_nChoiceAns);
			if(0!=mysql_real_query(&mysql,sql_query,sizeof(sql_query)))
				return;
		}
	}
	else
	{
		LPSTR ANS[4]={choiceQue.m_pstrA,choiceQue.m_pstrB,choiceQue.m_pstrC,choiceQue.m_pstrD};
		for(int i=0;i<4;i++)
		{
			TCHAR output[500]="";
			sprintf(output,"%c. %s",i+'A',ANS[i]);
			m_pbtnChoiceAns[i].SetWindowText(_T(output));
			m_pbtnChoiceAns[i].SetBitmaps(IDB_CHOICEANS,RGB(228,228,228));
		}
		m_pbtnChoiceAns[choiceQue.m_icorrentAnswer].SetBitmaps(IDB_CHOICEANSYES,RGB(228,228,228));		
		m_pdtChoiceExplain->SetWindowText(_T(choiceQue.m_pstrExplain));
	}
	if(m_nNextDlgStatus==DlgSChoice)
	{
		CString strText[5]={"��һ��","��һ��","ͬ���Ƽ�","�������","����"};
		for(i=0;i<5;i++)
		{
			m_pbtnNewButton[i].SetWindowText(_T(strText[i]));
			m_pbtnNewButton[i].ShowWindow(SW_SHOW);
		}
	}//DlgSCheck
	else if(m_nNextDlgStatus==DlgSWrongQue)
	{
		CString strText[5]={"��һ��","��һ��","ͬ���Ƽ�","����˵��","����"};
		for(i=0;i<5;i++)
		{
			m_pbtnNewButton[i].SetWindowText(_T(strText[i]));
			m_pbtnNewButton[i].ShowWindow(SW_SHOW);
		}
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		CString strText[5]={"��һ��","��һ��","�޸���Ŀ","�鿴�ύ","����"};
		for(i=0;i<5;i++)
		{
			m_pbtnNewButton[i].SetWindowText(_T(strText[i]));
			m_pbtnNewButton[i].ShowWindow(SW_SHOW);
		}
	}
}

void CMainDlg::OnChoiceA() 
{
	// TODO: Add your control notification handler code here
	OnChoice(0);
}

void CMainDlg::OnChoiceB() 
{
	// TODO: Add your control notification handler code here
	OnChoice(1);
}

void CMainDlg::OnChoiceC() 
{
	// TODO: Add your control notification handler code here
	OnChoice(2);
}

void CMainDlg::OnChoiceD() 
{
	// TODO: Add your control notification handler code here
	OnChoice(3);
}

void CMainDlg::OnChoice(int nChoiceAns)
{
	if(m_nNextDlgStatus==DlgSCheck)
	{
		return ;
	}
	if(m_nChoiceAns!=-1)
	{
		MessageBox(_T("���Ѿ����һ���ˣ�"),_T("�ȼ�������ϰϵͳ"));
		return ;
	}
	m_nChoiceAns=nChoiceAns;
	__ShowChoice();
//	Invalidate();
//	UpdateData();
}

void CMainDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

BOOL CMainDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN)
    {
        switch (pMsg->wParam)
        {
        case VK_RETURN: //���λس���
            return TRUE;
        case VK_ESCAPE: //����ESC��
            return TRUE;
        case VK_TAB:
            {
			 /*   int nStart, nEnd; 
                HWND hWnd = ::SetFocus(m_ctrlEditContent.m_hWnd);// m_ctrlEditContentΪ�༭������ 
                if(hWnd != m_ctrlEditContent.m_hWnd)
                {
                    ::SetFocus(hWnd);    
                }
                else        //����༭���е�Tab����ʹ�ÿ��������������Ʊ��'\t'
                {    
                    m_ctrlEditContent.GetSel(nStart,nEnd);    
                    m_ctrlEditContent.SetSel(nStart,nEnd);    
                    m_ctrlEditContent.ReplaceSel("\t");
                    return TRUE;
                }   
				*/
				return TRUE;
            }        
        default:
            break;
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}

void CMainDlg::OnOpenC()
{
	char strFile[3][10]={"blank.c","modi.c","prog.c"};
	ShellExecute(this->m_hWnd,"open", LPCSTR(CString("C:\\test\\")+strFile[opQue.m_nType]),"","",SW_SHOW );
}
void CMainDlg::OnRecoverC()
{
	char strFile[3][10]={"blank.c","modi.c","prog.c"};
	CFile file(LPCSTR(CString("C:\\test\\")+strFile[opQue.m_nType]),CFile::modeCreate | CFile::modeWrite);
	file.Write(opQue.m_strC,strlen(opQue.m_strC));
	file.Close();
	MessageBox(LPCSTR(CString("C:\\test\\")+strFile[opQue.m_nType]+"  �ָ��ɹ�"));
}
void CMainDlg::OnPreOp()
{
	if(m_nNextDlgStatus==DlgSOperating)
	{
		if(m_nNextDlgNum==0)
		{
			opQue.GetPointOp(&mysql,kaodian,opQue.m_id,false,false);
		}
		else
		{
			opQue.GetOrderOp(&mysql,opQue.m_id,false,false);
		}
	}
	else if(m_nNextDlgStatus==DlgSWrongQue)
	{
		opQue.GetWrongOp(&mysql,opQue.m_id,false,false);
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		opQue.GetOrderOp(&mysql,opQue.m_id,false,false);
	}
	__ShowOperating();
}
void CMainDlg::OnNxtOp()
{
	if(m_nNextDlgStatus==DlgSOperating)
	{
		if(m_nNextDlgNum==0)
		{
			opQue.GetPointOp(&mysql,kaodian,opQue.m_id,false,true);
		}
		else
		{
			opQue.GetOrderOp(&mysql,opQue.m_id,false,true);
		}
	}
	else if(m_nNextDlgStatus==DlgSWrongQue)
	{
		opQue.GetWrongOp(&mysql,opQue.m_id,false,true);
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		opQue.GetOrderOp(&mysql,opQue.m_id,false,true);
	}
	__ShowOperating();
}
void CMainDlg::OnSameOp()
{
	if(m_nNextDlgStatus==DlgSOperating||m_nNextDlgStatus==DlgSWrongQue)
	{
	//	MessageBox("δ���š�����");
		if(true==opQue.GetSameOp(&mysql,opQue.m_id))
		{
			//MessageBox("�Ƽ���Ŀ��������"+CString(CString("")+(int)opQue.m_id));
			CString rec;
			rec.Format("�Ƽ���Ŀ��������%d",opQue.m_id);
			MessageBox(rec);
			__ShowOperating();
		}
		else
		{
			MessageBox("û����Ŀ���Ƽ�");
		}
	}
	else if(m_nNextDlgStatus==DlgSCheck)
	{
		CAddOpDlg *paddOpDlg=new CAddOpDlg;
		paddOpDlg->m_id=opQue.m_id;
		paddOpDlg->opQue=&opQue;
		paddOpDlg->m_pmysql=&mysql;
		paddOpDlg->DoModal();
		__ShowOperating();
	}
}
void CMainDlg::OnOpAnswer()
{
	COpAnsDlg *opAns=new COpAnsDlg;
	CString strAns;
	CString strTitle;
	CString strFileName;
	if(opQue.m_nType==0)
	{//���������
		strTitle.Format("������%d:���������",opQue.m_id);
		opQue.m_strAns1.Replace("$$","��");
		opQue.m_strAns2.Replace("$$","��");
		opQue.m_strAns3.Replace("$$","��");
		strAns.Format("���ο��𰸡�\r\n��һ��:%s     �ڶ���:%s     ������:%s",opQue.m_strAns1,opQue.m_strAns2,opQue.m_strAns3);
		opQue.m_strAns1.Replace("��","$$");
		opQue.m_strAns2.Replace("��","$$");
		opQue.m_strAns3.Replace("��","$$");
		strFileName="C:\\test\\blank.c";
	}
	else if(opQue.m_nType==1)
	{//�����޸���
		strTitle.Format("������%d:�����޸���",opQue.m_id);
		opQue.m_strAns1.Replace("$$","��");
		opQue.m_strAns2.Replace("$$","��");
		strAns.Format("���ο��𰸡�\r\n��һ��:%s     �ڶ���:%s",opQue.m_strAns1,opQue.m_strAns2);
		opQue.m_strAns1.Replace("��","$$");
		opQue.m_strAns2.Replace("��","$$");
		strFileName="C:\\test\\modi.c";
	}
	else if(opQue.m_nType==2)
	{//���������
		strTitle.Format("������%d:���������",opQue.m_id);
		strAns.Format("���ο����롿\r\n%s",opQue.m_strAns1);
		strFileName="C:\\test\\prog.c";
	}
	if(m_nNextDlgStatus==DlgSCheck)
	{
		(opAns->m_strOpAns).Format("%s\r\n%s\r\n%s\r\n",strTitle,strAns,opQue.m_strExplain);
		opAns->DoModal();
	}
	else
	{
		CString strC;
		CFile file(strFileName,CFile::modeRead);
		DWORD dwFileLen;
		dwFileLen=file.GetLength();
		char *pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();
		strC.Format("����Ĵ��롿\r\n%s",pBuf);
		(opAns->m_strOpAns).Format("%s\r\n%s\r\n%s\r\n%s\r\n",strTitle,strC,strAns,opQue.m_strExplain);

		CString sql_query;
		sql_query.Format("INSERT INTO oprecord(student_id,op_id,oprecord_ansC) VALUES(\'%d\',\'%d\',\'%s\');",
			stu.m_id,opQue.m_id,pBuf);
		if(0!=mysql_real_query(&mysql,sql_query,sql_query.GetLength()))
		{
			MessageBox("���ݿ����","�ȼ�������ϰϵͳ");
			return;
		}
		opAns->DoModal();
	}
}
void CMainDlg::OnAddOpWrong()
{
	CAddWA* addWA=new CAddWA;
	CSubmitDlg *subDlg;
	switch(m_nNextDlgStatus)
	{
	case DlgSOperating:
	case DlgSWrongQue:
		addWA->mysql=&mysql;
		addWA->stu_id=stu.m_id;
		addWA->choice_id=-1;
		addWA->operating_id=opQue.m_id;
		if(IDOK==addWA->DoModal())
		{
			
		}
	//	MessageBox("grrfrhg");
		break;
	case DlgSCheck:
		subDlg=new CSubmitDlg;
		subDlg->nkind=2;
		subDlg->op_id=opQue.m_id;
		subDlg->mysql=&mysql;
		subDlg->DoModal();
		break;
	default:
		MessageBox("default");
		break;
	}

}
void CMainDlg::OnExitOp()
{
	__HideDownALL();
	__ShowSonMenu();
	__ShowMenuExplain();
	m_nNextDlgStatus=DlgSMain;
	Invalidate();
	UpdateData();
}

void CMainDlg::__ShowOperating()
{
	if(m_nNextDlgStatus!=DlgSCheck)
	{
		_mkdir("C:\\test");
		m_pStTitle->SetWindowText("�����ⵥ��ѵ��");
		m_pdtOpTitle->ShowWindow(SW_SHOW);
		char strType[3][155]={"���������(C:\\test\\blank.c)","�����޸���(C:\\test\\modi.c)","���������(C:\\test\\prog.c)"};
		char strFile[3][10]={"blank.c","modi.c","prog.c"};
		CString strTitle;
		strTitle.Format("������%d��%s\r\n    %s\r\n/*\r\n *  FILE:%s\r\n */\r\n%s",opQue.m_id,strType[opQue.m_nType],opQue.m_strTitle,strFile[opQue.m_nType],opQue.m_strC);
		m_pdtOpTitle->SetWindowText(strTitle);
		CFile file(LPCSTR(CString("C:\\test\\")+strFile[opQue.m_nType]),CFile::modeCreate | CFile::modeWrite);
		file.Write(opQue.m_strC,strlen(opQue.m_strC));
		file.Close();

		int i;
		CString wrongQue;
		if(m_nNextDlgStatus==DlgSOperating)
			wrongQue="�������";
		else
			wrongQue="����˵��";
		CString strText[8]={"���ļ�","�ָ��ļ�","��һ��","��һ��","ͬ���Ƽ�","�鿴���",wrongQue,"����"};
		for(i=0;i<8;i++)
		{
			m_pbtnOpButton[i].SetWindowText(strText[i]);
			m_pbtnOpButton[i].ShowWindow(SW_SHOW);
		}
	}
	else
	{
		_mkdir("C:\\test");
		m_pStTitle->SetWindowText("�����ⵥ��ѵ��");
		m_pdtOpTitle->ShowWindow(SW_SHOW);
		char strType[3][155]={"���������(C:\\test\\blank.c)","�����޸���(C:\\test\\modi.c)","���������(C:\\test\\prog.c)"};
		char strFile[3][10]={"blank.c","modi.c","prog.c"};
		CString strTitle;
		strTitle.Format("������%d��%s\r\n    %s\r\n/*\r\n *  FILE:%s\r\n */\r\n%s",opQue.m_id,strType[opQue.m_nType],opQue.m_strTitle,strFile[opQue.m_nType],opQue.m_strC);
		m_pdtOpTitle->SetWindowText(strTitle);
		CFile file(LPCSTR(CString("C:\\test\\")+strFile[opQue.m_nType]),CFile::modeCreate | CFile::modeWrite);
		file.Write(opQue.m_strC,strlen(opQue.m_strC));
		file.Close();

		int i;
		CString strText[8]={"���ļ�","�ָ��ļ�","��һ��","��һ��","�޸���Ŀ","�鿴���","�鿴�ύ","����"};
		for(i=0;i<8;i++)
		{
			m_pbtnOpButton[i].SetWindowText(strText[i]);
			m_pbtnOpButton[i].ShowWindow(SW_SHOW);
		}
	}
}

void CMainDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here

}
LRESULT CMainDlg::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
      //TODO: Add your message handle code

      return 0;
}
