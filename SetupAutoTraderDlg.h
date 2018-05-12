// SetupAutoTraderDlg.h : ヘッダー ファイル
//

#if !defined(AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_)
#define AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderDlg ダイアログ

class CSetupAutoTraderDlg : public CDialog
{
// 構築
public:
	CSetupAutoTraderDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CSetupAutoTraderDlg)
	enum { IDD = IDD_SETUPAUTOTRADER_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupAutoTraderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;
	CFileStatus m_FileStatus;
	CString m_strAutoTraderDPath;
	CString m_strProductCodeFPath;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSetupAutoTraderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CString GetLastErrorMessage(DWORD dwLastError = NULL);
CString GetExceptionErrorMessage(CException* pEx);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_)
