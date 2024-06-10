
// UniEntranceDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "UniEntrance.h"
#include "UniEntranceDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Student.h"
#include "Regis.h"
#include "Admission.h"
#include "Introduce.h"
#include "Brochure.h"
#include "Hist.h"
#include "BAOKAO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUniEntranceDlg 对话框



CUniEntranceDlg::CUniEntranceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UniEntrance_DIALOG, pParent)
	, Chinese(0)
	, Maths(0)
	, English(0)
	, score1(0)
	, score2(0)
	, score3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUniEntranceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, sc_list);
	DDX_Control(pDX, IDC_COMBO1, PhyOrHis);
	DDX_Control(pDX, IDC_COMBO2, m_choice1);
	DDX_Control(pDX, IDC_COMBO3, m_choice2);
	DDX_Text(pDX, IDC_EDIT1, Chinese);
	DDX_Text(pDX, IDC_EDIT2, Maths);
	DDX_Text(pDX, IDC_EDIT3, English);
	DDX_Text(pDX, IDC_EDIT4, score1);
	DDX_Text(pDX, IDC_EDIT5, score2);
	DDX_Text(pDX, IDC_EDIT6, score3);
}

BEGIN_MESSAGE_MAP(CUniEntranceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CUniEntranceDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CUniEntranceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CUniEntranceDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CUniEntranceDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CUniEntranceDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUniEntranceDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CUniEntranceDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CUniEntranceDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CUniEntranceDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CUniEntranceDlg 消息处理程序

BOOL CUniEntranceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	DWORD dwStyle = sc_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	sc_list.SetExtendedStyle(dwStyle);
	PhyOrHis.AddString(TEXT("历史"));
	PhyOrHis.AddString(TEXT("物理"));
	
	m_choice1.AddString(TEXT("政治"));
	m_choice1.AddString(TEXT("生物"));
	m_choice1.AddString(TEXT("化学"));
	m_choice1.AddString(TEXT("地理"));

	m_choice2.AddString(TEXT("化学"));
	m_choice2.AddString(TEXT("生物"));
	m_choice2.AddString(TEXT("地理"));
	m_choice2.AddString(TEXT("政治"));

	sc_list.InsertColumn(0, TEXT("专业编号"), 0, 120);
	sc_list.InsertColumn(1, TEXT("专业名称"), 0, 120);
	sc_list.InsertColumn(2, TEXT("预计招收数"), 0, 120);
	sc_list.InsertColumn(3, TEXT("科目1要求"), 0, 120);
	sc_list.InsertColumn(4, TEXT("科目2要求"), 0, 120);

	m_font.CreatePointFont(220, _T("华文新魏"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&m_font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUniEntranceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUniEntranceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUniEntranceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUniEntranceDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLogin == false)
	{
		Login deng;
		if (IDOK == deng.DoModal())
		{
			Student sr(deng.sid.GetBuffer(),deng.sname.GetBuffer(),deng.sverify.GetBuffer());
			isLogin = DataInterface.DengLu(sr);
			if (isLogin)
			{
				MessageBox(TEXT("登录成功"), TEXT("提示"));
				ListRRenew();
			}
			else
			{
				MessageBox(TEXT("无效信息，请重新登录"), TEXT("提示"));
			}
		}
	}
	else
	{
		MessageBox(TEXT("考生已登录"), TEXT("提示"));
	}
}

void CUniEntranceDlg::ListRRenew()
{
	sc_list.DeleteAllItems();
	CString str1, str2, str3;
	for (int i = 0; i < DataInterface.subs.size(); i++)
	{
		sc_list.InsertItem(i, DataInterface.subs[i].code.c_str());
		sc_list.SetItemText(i, 1, DataInterface.subs[i].p_name.c_str());
		str1.Format(TEXT("%d"), DataInterface.subs[i].num);
		sc_list.SetItemText(i, 2, str1);
		sc_list.SetItemText(i, 3, DataInterface.subs[i].first.c_str());
		sc_list.SetItemText(i, 4, DataInterface.subs[i].second.c_str());
	}
}


void CUniEntranceDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码，注册
	Regis ree;
	if (IDOK == ree.DoModal())
	{
		Student reg(ree.rid.GetBuffer(), ree.rname.GetBuffer(), ree.r_verify.GetBuffer());
		if (DataInterface.Zhuce(reg))
		{
			isLogin = false;//注册成功重新登录
			MessageBox(TEXT("注册成功"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("无效信息，注册失败"), TEXT("提示"));
		}

	}

}


void CUniEntranceDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码,录取查询，目前只能往届Admission
	if (isLogin == true)
	{
		Admission luq;
		if (IDOK == luq.DoModal())
		{
			CString  ad = luq.a_admission.GetBuffer();
			if (DataInterface.LuQu(ad) == "null")
			{
				MessageBox(TEXT("无此记录。\n应届生密切关注学校的公告发布，以获取关于招生录取的最新动态。\n往届生录取信息查无此人。"), TEXT("提示"));
			}
			else
			{
				//CString r;
				//string ss = CStringA(DataInterface.LuQu(ad)).GetString();
				//r.Format(TEXT("该生已被我校%s专业录取！"), ss);
				MessageBox(DataInterface.LuQu(ad), TEXT("录取专业"));
			}
		}
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}


void CUniEntranceDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码，
	if (isLogin == true)
	{
		Introduce cha;
		if (IDOK == cha.DoModal())
		{
			//专业介绍
		}
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}


void CUniEntranceDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLogin == true)
	{
		string sty = "";
		vector<string> notice;
		vector<string> date;
		CString FilePath = _T(".\\Notice.txt");
		ifstream in(FilePath, ios::in);
		if (in.is_open())
		{
			int num;
			in >> num;
			for (int i = 0; i < num; i++)
			{
				string tmp1, tmp2;
				in >> tmp1;
				in >> tmp2;
				notice.push_back(tmp1);
				date.push_back(tmp2);

			}
		}
		for (int i = 0; i < notice.size(); i++)
		{
			sty += notice[i];
			sty += "\t";
			sty += date[i];
			sty += "\n";
		}
		MessageBox(sty.c_str(), TEXT("通知公告"));
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}


void CUniEntranceDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLogin == true)
	{
		Brochure bro;
		if (IDOK == bro.DoModal())
		{
			//招生简章
		}
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}


void CUniEntranceDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLogin == true)
	{
		Hist b4;
		if (IDOK == b4.DoModal())
		{
			//往年数据
		}
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}



void CUniEntranceDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码，专业推荐
	if (isLogin == true)
	{
		CString str,str2,str3;
		UpdateData(TRUE);
		int yuwen = Chinese;
		int shuxue = Maths;
		int yingyu = English;
		int poh = score1;
		int s2 = score2;
		int s3 = score3;
		int index = PhyOrHis.GetCurSel();
		PhyOrHis.GetLBText(index, str);
		int index2 = m_choice1.GetCurSel();
		m_choice1.GetLBText(index2, str2);
		int index3 = m_choice2.GetCurSel();
		m_choice2.GetLBText(index3, str3);
		string sr = "";
		for (int i = 0; i < DataInterface.subs.size(); i++)
		{
			if (DataInterface.subs[i].first.c_str() == str || DataInterface.subs[i].first.c_str() =="无")
			{
				if (DataInterface.subs[i].second.c_str() == str2 || DataInterface.subs[i].second.c_str() == str3 || DataInterface.subs[i].second.c_str() == "无")
				{
					if (DataInterface.subs[i].p_name =="计算机科学与技术")
					{
						if (poh >= 75)
						{
							sr += DataInterface.subs[i].p_name;
							sr += "\n";
						}
					}
					else if(DataInterface.subs[i].p_name == "哲学")
					{
						if ((s2 >= 80 && str2 == "政治")|| (s3 >= 80 && str3 == "政治"))
						{
							sr += DataInterface.subs[i].p_name;
							sr += "\n";
						}
					}
					else
					{
						sr += DataInterface.subs[i].p_name;
						sr += "\n";
					}
				}
				
			}
		}
		MessageBox(sr.c_str(), TEXT("推荐专业"));

	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}


void CUniEntranceDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLogin == true)
	{
		BAOKAO bk;
		if (IDOK == bk.DoModal())
		{
			//报考
		}
	}
	else
	{
		MessageBox(TEXT("请考生登录"), TEXT("提示"));
	}
}
