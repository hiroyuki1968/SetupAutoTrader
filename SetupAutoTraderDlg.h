// SetupAutoTraderDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_)
#define AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderDlg �_�C�A���O

class CSetupAutoTraderDlg : public CDialog
{
// �\�z
public:
	CSetupAutoTraderDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSetupAutoTraderDlg)
	enum { IDD = IDD_SETUPAUTOTRADER_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupAutoTraderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;
	CFileStatus m_FileStatus;
	CString m_strAutoTraderDPath;
	CString m_strProductCodeFPath;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPAUTOTRADERDLG_H__F416028D_4F7C_4486_86C7_3C281ED6834A__INCLUDED_)
