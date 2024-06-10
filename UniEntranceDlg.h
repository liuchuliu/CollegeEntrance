
// UniEntranceDlg.h: 头文件
//

#pragma once
#include "FunctionInterface.h"
#include "Student.h"

// CUniEntranceDlg 对话框
class CUniEntranceDlg : public CDialogEx
{
// 构造
public:
	CUniEntranceDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UniEntrance_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl sc_list;
	CComboBox PhyOrHis;
	CComboBox m_choice1;
	CComboBox m_choice2;
	int Chinese;
	int Maths;
	int English;
	int score1;
	int score2;
	int score3;
	bool isLogin = false;
	afx_msg void OnBnClickedButton2();
	FunctionInterface DataInterface;
	void ListRRenew();
	CFont m_font;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
};
