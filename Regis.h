#pragma once
#include "afxdialogex.h"


// Regis 对话框

class Regis : public CDialogEx
{
	DECLARE_DYNAMIC(Regis)

public:
	Regis(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Regis();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Regis };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFont r_font;
	CString rid;
	CString rname;
	CString r_verify;
	afx_msg void OnBnClickedButton1();
};
