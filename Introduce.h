#pragma once
#include "afxdialogex.h"


// Introduce 对话框

class Introduce : public CDialogEx
{
	DECLARE_DYNAMIC(Introduce)

public:
	Introduce(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Introduce();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Introduce };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl s_list;
	virtual BOOL OnInitDialog();
	void ListRRenew();
	afx_msg void OnBnClickedButton1();
};
