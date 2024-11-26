// OpAnsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "OpAnsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpAnsDlg dialog


COpAnsDlg::COpAnsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpAnsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpAnsDlg)
	m_strOpAns = _T("");
	//}}AFX_DATA_INIT
}


void COpAnsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpAnsDlg)
	DDX_Text(pDX, IDC_OPANS, m_strOpAns);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpAnsDlg, CDialog)
	//{{AFX_MSG_MAP(COpAnsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpAnsDlg message handlers

BOOL COpAnsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFont *pfont=new CFont;
	pfont->CreateFont(25,0,0,0,FW_NORMAL,
		FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_RASTER_PRECIS,CLIP_DEFAULT_PRECIS,
        VARIABLE_PITCH|PROOF_QUALITY,FF_DONTCARE,"Á¥Êé"
	);
	((CButton*)GetDlgItem(IDC_OPANS))->SetFont(pfont);

//	UpdateData(true);
//	((CButton*)GetDlgItem(IDOK))->SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
