// BAOKAO.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "BAOKAO.h"
#include "UniEntrance.h"

// BAOKAO 对话框

IMPLEMENT_DYNAMIC(BAOKAO, CDialogEx)

BAOKAO::BAOKAO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BAOKAO, pParent)
{

}

BAOKAO::~BAOKAO()
{
}

void BAOKAO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BAOKAO, CDialogEx)
	ON_BN_CLICKED(IDOK, &BAOKAO::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &BAOKAO::OnBnClickedCancel)
END_MESSAGE_MAP()


// BAOKAO 消息处理程序


void BAOKAO::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void BAOKAO::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
