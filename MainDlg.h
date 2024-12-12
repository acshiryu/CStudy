// MainDlg.h : header file
//
#include "BtnST.h"
#include "TransparentStatic.h"



#if !defined(AFX_MAINDLG_H__0D21C3D9_900E_478C_9F7A_4FE42C4B9813__INCLUDED_)
#define AFX_MAINDLG_H__0D21C3D9_900E_478C_9F7A_4FE42C4B9813__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	void __ShowOperating();
	CMainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAIN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMinimize();
	afx_msg void OnMainMenu1();
	afx_msg void OnMainMenu2();
	afx_msg void OnMainMenu3();
	afx_msg void OnMainMenu4();
	afx_msg void OnSonMenu1();
	afx_msg void OnSonMenu2();
	afx_msg void OnSonMenu3();
	afx_msg void OnNextDlg1();
	afx_msg void OnNextDlg2();
	afx_msg void OnChoiceA();
	afx_msg void OnChoiceB();
	afx_msg void OnChoiceC();
	afx_msg void OnChoiceD();
	virtual void OnOK();
	afx_msg void OnPreChoice();
	afx_msg void OnNxtChoice();
	afx_msg void OnSameChoice();
	afx_msg void OnAddWrong();
	afx_msg void OnExitChoice();
	afx_msg void OnOpenC();
	afx_msg void OnRecoverC();
	afx_msg void OnPreOp();
	afx_msg void OnNxtOp();
	afx_msg void OnSameOp();
	afx_msg void OnOpAnswer();
	afx_msg void OnAddOpWrong();
	afx_msg void OnExitOp();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CButtonST* m_pbtnNewButton;
	CButtonST* m_pbtnOpButton;
	void OnSonMenu(int nSonMenuNum);
	void OnMainMenu(int nMainMenuNum);
	CEdit* m_pdtChoiceExplain;
	void OnChoice(int nChoiceAns);
	int m_nChoiceAns;
	CButtonST* m_pbtnChoiceAns;
	CEdit* m_pdtQueTitle;
	CEdit* m_pdtOpTitle;
	void __HideDownALL();
	void __HideMain();
	void OnNextDlg(int nNextDlgNum);
	void __ShowChoice();
	CButtonST* m_pbtnNextDlg;
	int m_nCurrentDlgStatus;
	int m_nNextDlgStatus;
	void __ShowMenuExplain();
	int m_nSonMenuTotalNum;
	void __InitVariable();
	CTransparentStatic* m_pStTitle;
	CTransparentStatic* m_pStExplain;
	CButtonST* m_pbtnMainMenu;
	CButtonST* m_pbtnSonMenu;
	void __ShowSonMenu();
	void __ShowMainMenu();
	int m_nCurrentSonNum;
	int m_nCurrentMainNum;
	int m_nNextSonNum;
	int m_nNextMainNum;
	int m_nNextDlgNum;
	CButtonST* m_pbtnClose;//关闭窗口
	CButtonST* m_pbtnMinimize;//最小化窗口
	enum{
		DlgSMain,
		DlgSChoice,
		DlgSOperating,
		DlgSWrongQue,
		DlgSCheck,
		NODlgS
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__0D21C3D9_900E_478C_9F7A_4FE42C4B9813__INCLUDED_)
