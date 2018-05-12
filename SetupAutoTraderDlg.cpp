// SetupAutoTraderDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "SetupAutoTrader.h"
#include "SetupAutoTraderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderDlg ダイアログ

CSetupAutoTraderDlg::CSetupAutoTraderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupAutoTraderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupAutoTraderDlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetupAutoTraderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupAutoTraderDlg)
		// メモ: この場所には ClassWizard によって DDX と DDV の呼び出しが追加されます。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetupAutoTraderDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupAutoTraderDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderDlg メッセージ ハンドラ

BOOL CSetupAutoTraderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。

	CEdit* pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit *)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit *)GetDlgItem(IDC_EDIT3);
	CButton* pBtn = (CButton *)GetDlgItem(IDOK);

//	char szPersonalDPath[_MAX_PATH];
//	SHGetSpecialFolderPath(m_hWnd, szPersonalDPath, CSIDL_PERSONAL, FALSE);

//	CString strPersonalDPath = szPersonalDPath;
	CString strPersonalDPath = "D:\\home";
	m_strAutoTraderDPath = strPersonalDPath + "\\Visual Studio Projects\\AutoTrader";
	m_strProductCodeFPath = m_strAutoTraderDPath + "\\ProductCode.txt";
	try {
		CString strLine;

		CString strVerHFPath = m_strAutoTraderDPath + "\\AutoTraderVer.h";

		CString strKey0 = "#define BASE_VER	";
		int nKeyLen0 = strKey0.GetLength();

		CString strKey1 = "#define THIS_VER	";
		int nKeyLen1 = strKey1.GetLength();

		char pszVer[MAX_PATH];

		CStdioFile SfVerH(strVerHFPath, CFile::modeRead);
		while (SfVerH.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0) {
				if (sscanf(strLine, "%*s %*s %s", pszVer) == 1)
					pEdit1->SetWindowText(pszVer);
			} else if (strLine.Left(nKeyLen1) == strKey1) {
				if (sscanf(strLine, "%*s %*s %s", pszVer) == 1)
					pEdit2->SetWindowText(pszVer);
				break;
			}
		}
		SfVerH.Close();

		if (CFile::GetStatus(m_strProductCodeFPath, m_FileStatus)) {
			CStdioFile SfProductCode(m_strProductCodeFPath, CFile::modeRead);
			SfProductCode.ReadString(strLine);
			SfProductCode.Close();
			pEdit3->SetWindowText(strLine);
		}
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
	}
	pEdit2->SetFocus();
	pEdit2->SetSel(0, -1);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CSetupAutoTraderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CSetupAutoTraderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetupAutoTraderDlg::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください

	int i;
	CString strBaseVer;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strBaseVer);
	int nBaseVerLen = strBaseVer.GetLength();
	CString strMajorBaseVer = strBaseVer.Left(nBaseVerLen - 4);
	CString strMinorBaseVer = strBaseVer.Mid(nBaseVerLen - 4, 2);
	CString strRevBaseVer = strBaseVer.Right(2);
	int nBaseVer = atoi(strBaseVer);
	int nMajorBaseVer = atoi(strMajorBaseVer);
	int nMinorBaseVer = atoi(strMinorBaseVer);
	int nRevBaseVer = atoi(strRevBaseVer);

	CString strVer;
	GetDlgItem(IDC_EDIT2)->GetWindowText(strVer);
	int nVerLen = strVer.GetLength();
	CString strMajorVer = strVer.Left(nVerLen - 4);
	CString strMinorVer = strVer.Mid(nVerLen - 4, 2);
	CString strRevVer = strVer.Right(2);
	int nVer = atoi(strVer);
	int nMajorVer = atoi(strMajorVer);
	int nMinorVer = atoi(strMinorVer);
	int nRevVer = atoi(strRevVer);
	CString strAlphaBeta;
	if (nRevVer)
		if (nRevVer < 51)
			strAlphaBeta = "α";
		else
			strAlphaBeta = "β";

	CString strFPath;
	CString strFPathC;
	CString strLine;
	CString strKey0;
	CString strKey1;
	CString strKey2;
	CString strKey3;
	int nKeyLen0;
	int nKeyLen1;
	int nKeyLen2;
	int nKeyLen3;

	strFPath = m_strAutoTraderDPath + "\\AutoTraderVer.h";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "#define BASE_VER	";
		nKeyLen0 = strKey0.GetLength();

		strKey1 = "#define THIS_VER	";
		nKeyLen1 = strKey1.GetLength();

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				strLine = strKey0 + strBaseVer;
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine = strKey1 + strVer;
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	static const char* ppszManifestFName[] = {
		"AutoTrader",
		"KehaiViewer\\KehaiViewer",
		"TradeHelper\\TradeHelper",
		"TradeConsole\\TradeConsole",
		"RandChart\\RandChart",
		NULL
	};
	for (i = 0;  ppszManifestFName[i];  i ++) {
		strFPath = m_strAutoTraderDPath + '\\' + ppszManifestFName[i] + ".exe.manifest";
		strFPathC = strFPath + '~';
		try {
			strKey0 = "    version=\"";
			nKeyLen0 = strKey0.GetLength();

			CStdioFile Sf(strFPath, CFile::modeRead);
			CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
			while (Sf.ReadString(strLine)) {
				if (strLine.Left(nKeyLen0) == strKey0)
					strLine.Format(strKey0 + "%d.%d.%d.1\"", nMajorVer, nMinorVer, nRevVer);
				SfC.WriteString(strLine + "\n");
			}
			SfC.Close();
			Sf.Close();
		}
		catch (CException* pEx) {
			MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
			pEx->Delete();
			return;
		}
		if (! DeleteFile(strFPath)) {
			MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}
		if (! MoveFile(strFPathC, strFPath)) {
			MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}
	}

	static const char* ppszRcFName[] = {
		"AutoTrader",
		"ChartViewer\\ChartViewer",
		"KehaiViewer\\KehaiViewer",
		"TradeHelper\\TradeHelper",
		"TradeConsole\\TradeConsole",
		"RandChart\\RandChart",
		"AutoTraderUpdateManager\\AutoTraderUpdateManager",
		NULL
	};
	for (i = 0;  ppszRcFName[i];  i ++) {
		strFPath = m_strAutoTraderDPath + '\\' + ppszRcFName[i] + ".rc";
		strFPathC = strFPath + '~';

		try {
			strKey0 = " FILEVERSION ";
			nKeyLen0 = strKey0.GetLength();

			strKey1 = " PRODUCTVERSION ";
			nKeyLen1 = strKey1.GetLength();

			strKey2 = "            VALUE \"FileVersion\", \"";
			nKeyLen2 = strKey2.GetLength();

			strKey3 = "            VALUE \"ProductVersion\", \"";
			nKeyLen3 = strKey3.GetLength();

			CStdioFile Sf(strFPath, CFile::modeRead);
			CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
			while (Sf.ReadString(strLine)) {
				if (strLine.Left(nKeyLen0) == strKey0)
					strLine.Format(strKey0 + "%d,%d,%d,1", nMajorVer, nMinorVer, nRevVer);
				else if (strLine.Left(nKeyLen1) == strKey1)
					strLine.Format(strKey1 + "%d,%d,%d,1", nMajorVer, nMinorVer, nRevVer);
				else if (strLine.Left(nKeyLen2) == strKey2)
					strLine.Format(strKey2 + "%d, %d, %d, 1\\0\"", nMajorVer, nMinorVer, nRevVer);
				else if (strLine.Left(nKeyLen3) == strKey3)
					strLine.Format(strKey3 + "%d, %d, %d, 1\\0\"", nMajorVer, nMinorVer, nRevVer);
				SfC.WriteString(strLine + "\n");
			}
			SfC.Close();
			Sf.Close();
		}
		catch (CException* pEx) {
			MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
			pEx->Delete();
			return;
		}
		if (! DeleteFile(strFPath)) {
			MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}
		if (! MoveFile(strFPathC, strFPath)) {
			MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}

		strFPath = m_strAutoTraderDPath + '\\' + ppszRcFName[i] + ".aps";
		if (CFile::GetStatus(strFPath, m_FileStatus))
			if (! DeleteFile(strFPath)) {
				MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
				return;
			}
	}

	strFPath = m_strAutoTraderDPath + "\\AutoTrader 説明書.txt";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "　　AutoTrader - トレーディングツール Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "　ａ．ファイル AutoTrader";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "　ｂ．解凍したフォルダにできた AutoTrader";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				if (nRevVer)
					strLine.Format(strKey0 + "%d.%d.%d%s 説明書", nMajorVer, nMinorVer, nRevVer, strAlphaBeta);
				else
					strLine.Format(strKey0 + "%d.%d 説明書", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d%02d.zip を適当なフォルダに解凍します。", nMajorVer, nMinorVer, nRevVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d%02d フォルダ内のファイル", nMajorVer, nMinorVer, nRevVer);
*/
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	strFPath = m_strAutoTraderDPath + "\\HTML Help\\AutoTrader.htm";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "<H3 STYLE=\"color: #FFFFFF; background-color: #00CCFF;\"><FONT size=7>AutoTrader</FONT> - トレーディングツール Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "	<LI>ファイル AutoTrader";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "	<LI>解凍したフォルダにできた AutoTrader";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				if (nRevVer)
					strLine.Format(strKey0 + "%d.%d.%d%s <FONT color=yellow>ヘルプ</FONT></H3>", nMajorVer, nMinorVer, nRevVer, strAlphaBeta);
				else
					strLine.Format(strKey0 + "%d.%d <FONT color=yellow>ヘルプ</FONT></H3>", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d%02d.zip を適当なフォルダに解凍します。", nMajorVer, nMinorVer, nRevVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d%02d フォルダ内のファイル SETUP.EXE を実行します。", nMajorVer, nMinorVer, nRevVer);
*/
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	
	CDialog::OnOK();
}

void CSetupAutoTraderDlg::OnButton1() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください

	GUID guid = GUID_NULL;

	char szProductCode[MAX_PATH] = {0};
	DWORD dwProductCodeSize = MAX_PATH;

	if (CoCreateGuid(&guid) != S_OK) {
		MessageBox("CoCreateGuid(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	dwProductCodeSize =
		sprintf(szProductCode, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			guid.Data1, guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
			guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]
		);

	GetDlgItem(IDC_EDIT3)->SetWindowText(szProductCode);

	try {
		CStdioFile SfProductCode(m_strProductCodeFPath, CFile::modeCreate | CFile::modeWrite);
		SfProductCode.WriteString(szProductCode);
		SfProductCode.WriteString("\n");
		SfProductCode.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
	}
}

CString GetLastErrorMessage(DWORD dwLastError)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwLastError ? dwLastError : GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
	);
	// Process any inserts in lpMsgBuf.
	CString strMsg((LPCTSTR)lpMsgBuf);
	// Free the buffer.
	LocalFree( lpMsgBuf );

	return strMsg;
}

CString GetExceptionErrorMessage(CException* pEx)
{
	TCHAR   szCause[255];

	pEx->GetErrorMessage(szCause, 255);
	return szCause;
}
