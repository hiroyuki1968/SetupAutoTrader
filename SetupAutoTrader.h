// SetupAutoTrader.h : SETUPAUTOTRADER アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_)
#define AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CSetupAutoTraderApp:
// このクラスの動作の定義に関しては SetupAutoTrader.cpp ファイルを参照してください。
//

class CSetupAutoTraderApp : public CWinApp
{
public:
	CSetupAutoTraderApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupAutoTraderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CSetupAutoTraderApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPAUTOTRADER_H__FD294FC4_C902_4D2D_A8B8_FA74811AAD84__INCLUDED_)
