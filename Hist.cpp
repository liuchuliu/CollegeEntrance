// Hist.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Hist.h"
#include "Lishi.h"


// Hist 对话框

IMPLEMENT_DYNAMIC(Hist, CDialogEx)

Hist::Hist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Hist, pParent)
{

}

Hist::~Hist()
{
}

void Hist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, llr_list);
}


BEGIN_MESSAGE_MAP(Hist, CDialogEx)
	ON_BN_CLICKED(IDOK, &Hist::OnBnClickedOk)
END_MESSAGE_MAP()


// Hist 消息处理程序


void Hist::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL Hist::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = llr_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	
	llr_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	llr_list.InsertColumn(0, TEXT("专业代码"), 0, 110);
	llr_list.InsertColumn(1, TEXT("专业名"), 0, 110);
	llr_list.InsertColumn(2, TEXT("4"), 0, 110);
	llr_list.InsertColumn(3, TEXT("3"), 0, 110);
	llr_list.InsertColumn(4, TEXT("2"), 0, 110);
	llr_list.InsertColumn(5, TEXT("1"), 0, 110);
	ListRRenew();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Hist::ListRRenew()
{
	CString str;
	vector<Lishi> bss;
	CString FilePath = _T(".\\Hist.txt");
	ifstream in(FilePath, ios::in);
	if (in.is_open())
	{
		int num;
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Lishi P;
			P.inputP(in);
			bss.push_back(P);

		}
	}
	for (int i = 0; i < bss.size(); i++)
	{
		llr_list.InsertItem(i, bss[i].idd.c_str());
		llr_list.SetItemText(i, 1, bss[i].nname.c_str());
		str.Format(TEXT("%d"), bss[i].s23);
		llr_list.SetItemText(i, 2, str);
		str.Format(TEXT("%d"), bss[i].s22);
		llr_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), bss[i].s21);
		llr_list.SetItemText(i, 4, str);
		str.Format(TEXT("%d"), bss[i].s20);
		llr_list.SetItemText(i, 5, str);
	}
}
