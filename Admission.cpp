// Admission.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Admission.h"


// Admission 对话框

IMPLEMENT_DYNAMIC(Admission, CDialogEx)

Admission::Admission(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Admission, pParent)
	, a_admission(_T(""))
{

}

Admission::~Admission()
{
}

void Admission::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a_admission);
}


BEGIN_MESSAGE_MAP(Admission, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Admission::OnBnClickedButton1)
END_MESSAGE_MAP()


// Admission 消息处理程序


void Admission::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if (a_admission  != "")
	{
		OnOK();
	}
	else
	{
		MessageBox(TEXT("信息空缺，请补充"), TEXT("提示"));
	}
}


BOOL Admission::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	a_font.CreatePointFont(200, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&a_font);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

