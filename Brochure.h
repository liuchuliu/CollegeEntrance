#pragma once
#include "afxdialogex.h"


// Brochure 对话框

class Brochure : public CDialogEx
{
	DECLARE_DYNAMIC(Brochure)

public:
	Brochure(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Brochure();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Brochure };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeRichedit21();
	CRichEditCtrl m_richEditCtrl;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
