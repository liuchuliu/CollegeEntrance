#pragma once
#include "afxdialogex.h"


// BAOKAO 对话框

class BAOKAO : public CDialogEx
{
	DECLARE_DYNAMIC(BAOKAO)

public:
	BAOKAO(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BAOKAO();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BAOKAO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
