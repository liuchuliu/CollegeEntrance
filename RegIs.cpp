// Regis.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Regis.h"


// Regis 对话框

IMPLEMENT_DYNAMIC(Regis, CDialogEx)

Regis::Regis(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Regis, pParent)
	, rid(_T(""))
	, rname(_T(""))
	, r_verify(_T(""))
{

}

Regis::~Regis()
{
}

void Regis::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rid);
	DDX_Text(pDX, IDC_EDIT2, rname);
	DDX_Text(pDX, IDC_EDIT3, r_verify);
}


BEGIN_MESSAGE_MAP(Regis, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Regis::OnBnClickedButton1)
END_MESSAGE_MAP()


// Regis 消息处理程序


BOOL Regis::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	r_font.CreatePointFont(150, _T("宋体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&r_font);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Regis::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (rid == TEXT("") || rname == TEXT("") || r_verify == TEXT(""))
	{
		MessageBox(TEXT("缺少信息，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


