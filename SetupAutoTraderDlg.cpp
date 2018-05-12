// SetupAutoTraderDlg.cpp : �C���v�������e�[�V���� �t�@�C��
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
// CSetupAutoTraderDlg �_�C�A���O

CSetupAutoTraderDlg::CSetupAutoTraderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupAutoTraderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupAutoTraderDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetupAutoTraderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupAutoTraderDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
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
// CSetupAutoTraderDlg ���b�Z�[�W �n���h��

BOOL CSetupAutoTraderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B

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
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CSetupAutoTraderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CSetupAutoTraderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetupAutoTraderDlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������

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
			strAlphaBeta = "��";
		else
			strAlphaBeta = "��";

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

	strFPath = m_strAutoTraderDPath + "\\AutoTrader ������.txt";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "�@�@AutoTrader - �g���[�f�B���O�c�[�� Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "�@���D�t�@�C�� AutoTrader";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "�@���D�𓀂����t�H���_�ɂł��� AutoTrader";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				if (nRevVer)
					strLine.Format(strKey0 + "%d.%d.%d%s ������", nMajorVer, nMinorVer, nRevVer, strAlphaBeta);
				else
					strLine.Format(strKey0 + "%d.%d ������", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d%02d.zip ��K���ȃt�H���_�ɉ𓀂��܂��B", nMajorVer, nMinorVer, nRevVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d%02d �t�H���_���̃t�@�C��", nMajorVer, nMinorVer, nRevVer);
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
		strKey0 = "<H3 STYLE=\"color: #FFFFFF; background-color: #00CCFF;\"><FONT size=7>AutoTrader</FONT> - �g���[�f�B���O�c�[�� Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "	<LI>�t�@�C�� AutoTrader";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "	<LI>�𓀂����t�H���_�ɂł��� AutoTrader";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				if (nRevVer)
					strLine.Format(strKey0 + "%d.%d.%d%s <FONT color=yellow>�w���v</FONT></H3>", nMajorVer, nMinorVer, nRevVer, strAlphaBeta);
				else
					strLine.Format(strKey0 + "%d.%d <FONT color=yellow>�w���v</FONT></H3>", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d%02d.zip ��K���ȃt�H���_�ɉ𓀂��܂��B", nMajorVer, nMinorVer, nRevVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d%02d �t�H���_���̃t�@�C�� SETUP.EXE �����s���܂��B", nMajorVer, nMinorVer, nRevVer);
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������

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
