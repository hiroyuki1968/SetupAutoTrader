// SetupAutoTrader.h : SETUPAUTOTRADER �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_)
#define AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� SetupAutoTrader.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CSetupAutoTraderApp : public CWinApp
{
public:
	CSetupAutoTraderApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupAutoTraderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CSetupAutoTraderApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_)
