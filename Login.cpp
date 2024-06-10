// Login.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Login.h"


// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Login, pParent)
	, sid(_T(""))
	, sname(_T(""))
	, sverify(_T(""))
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sid);
	DDX_Text(pDX, IDC_EDIT2, sname);
	DDX_Text(pDX, IDC_EDIT3, sverify);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Login::OnBnClickedButton1)
END_MESSAGE_MAP()


// Login 消息处理程序


void Login::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (sid == TEXT("") || sname == TEXT("") || sverify == TEXT(""))
	{
		MessageBox(TEXT("缺少考生信息，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}

