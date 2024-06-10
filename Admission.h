#pragma once
#include "afxdialogex.h"


// Admission 对话框

class Admission : public CDialogEx
{
	DECLARE_DYNAMIC(Admission)

public:
	Admission(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Admission();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Admission };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString a_admission;
	afx_msg void OnBnClickedButton1();
	CFont a_font;
	virtual BOOL OnInitDialog();
};
