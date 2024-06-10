#pragma once
#include "afxdialogex.h"


// Hist 对话框

class Hist : public CDialogEx
{
	DECLARE_DYNAMIC(Hist)

public:
	Hist(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Hist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Hist };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl llr_list;
	void ListRRenew();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	
};
