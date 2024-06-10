// Introduce.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Introduce.h"
#include "Profession.h"

// Introduce 对话框

IMPLEMENT_DYNAMIC(Introduce, CDialogEx)

Introduce::Introduce(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Introduce, pParent)
{

}

Introduce::~Introduce()
{
}

void Introduce::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, s_list);
}


BEGIN_MESSAGE_MAP(Introduce, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Introduce::OnBnClickedButton1)
END_MESSAGE_MAP()


// Introduce 消息处理程序


BOOL Introduce::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = s_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	s_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	s_list.InsertColumn(0, TEXT("专业代码"), 0, 110);
	s_list.InsertColumn(1, TEXT("专业名称"), 0, 110);
	s_list.InsertColumn(2, TEXT("预计招收人数"), 0, 110);
	s_list.InsertColumn(3, TEXT("1科目要求"), 0, 110);
	s_list.InsertColumn(4, TEXT("2科目要求"), 0, 110);
	ListRRenew();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Introduce::ListRRenew()
{
	//s_list.DeleteAllItems();
	CString str;
	vector<Profession> subss;
	CString FilePath = _T(".\\SubInfo.txt");
	ifstream in(FilePath, ios::in);
	if (in.is_open())
	{
		int num;
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Profession P;
			P.inputP(in);
			subss.push_back(P);

		}
	}
	for (int i = 0; i < subss.size(); i++)
	{
		s_list.InsertItem(i, subss[i].code.c_str());
		s_list.SetItemText(i, 1, subss[i].p_name.c_str());
		str.Format(TEXT("%d"), subss[i].num);
		s_list.SetItemText(i, 2, str);
		s_list.SetItemText(i, 3, subss[i].first.c_str());
		s_list.SetItemText(i, 4, subss[i].second.c_str());
	}
}


void Introduce::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = s_list.GetSelectionMark();
	if (index > -1)
	{
		string stt;
		switch (index)
		{
		case 0: stt = "专业名称：哲学\n修业年限：四年\n授予学位：哲学学士学位\n培养目标：本专业旨在培养具有系统的哲学专业基础知识.和较高的哲学理论忠维能力, 并兼具多学科融合的广博的知识水平，学思并进、德才兼备，深植家国情怀和淑世精神的复合型人才，通过四年的学习和专业训练，学生将初步具备哲学原典的阅读能力、哲学问题的研究能力，以及良好的语言表达沟通能力，和运用所学知识解决现实问题的实践能力等\n 师资队伍：现有专任教师26人，其中教授10人，博士生导师13人。多数毕业于北京大学、清华大学、复旦大学、武汉大学、美国普渡大学、英国约克大学、德国海德堡大学、德国弗莱堡大学、新加坡南洋理工大学、香港中文大学等世界知名高校。近年来主持国家级重大、重点社科基金项目近十项，科研实力雄厚。"; break;
		case 1: stt = "专业名称：基础医学\n修业年限：五年\n授予学位：医学学士学位\n培养目标：基础医学专业培养具备自然科学、生命科学和医学科学基本理论知识和实验技能，能够从事基础医学各学科的教学、科学研究及基础与临床相结合的医学实验研究工作的医学高级专门人才。主要课程包括人体解剖学、组织学与胚胎学、正常人体形态学实验等。\n师资队伍：现有专任教师80人，其中教授33人，博士生导师49人。多数毕业于北京大学、清华大学、复旦大学、武汉大学、四川大学、美国普渡大学、英国约克大学、德国弗莱堡大学、新加坡南洋理工大学等世界知名高校。近年来主持国家级重大、重点社科基金项目近百项，科研实力雄厚。"; break;
		case 2: stt = "专业名称：计算机科学与技术\n修业年限：四年\n授予学位：工学学士学位\n培养目标：计算机科学与技术专业以数理知识和程序设计为基础，涵盖编程语言、数据结构与算法、计算机系统、计算机网络等领域。该专业培养能够分析和解决复杂计算机系统问题，具有竞争力的工程复合型高素质专门人才。\n师资队伍：现有专任教师145人，其中教授62人，博士生导师89人。多数毕业于北京大学、清华大学、复旦大学、武汉大学、浙江大学、美国斯坦福大学、英国牛津大学、德国弗莱堡大学、新加坡南洋理工大学等世界知名高校。近年来主持国家级重大、重点社科基金项目逾百项，科研实力雄厚。"; break;
		case 3: stt = "专业名称：经济学\n修业年限：四年\n授予学位：经济学学士学位\n培养目标：法学专业培养学生系统掌握法学基本理论知识，具备实践能力突出，能够应对司法改革需要，胜任公、检、法等国家机关和企事业单位岗位，从事法律实务或法学教育工作的应用型法律人才。主要课程包括法理学、宪法学、中国法律史等。\n师资队伍：现有专任教师145人，其中教授62人，博士生导师89人。多数毕业于北京大学、清华大学、复旦大学、武汉大学、浙江大学、美国斯坦福大学、英国牛津大学、德国弗莱堡大学、新加坡南洋理工大学等世界知名高校。近年来主持国家级重大、重点社科基金项目逾百项，科研实力雄厚。"; break;
		case 5: stt = "专业名称：小学教育\n修业年限：三年\n授予学位：无\n培养目标：小学教育专业培养德、智、体、美全面发展，具有良好职业道德和人文素养，掌握较系统的专业知识与专业技能，具备较强保育能力、活动设计与组织能力、实践反思与自我发展能力的教师。主要课程包括《学前儿童卫生与保健》、《学前儿童发展心理学》等。"; break;
		case 6: stt = "专业名称：汉语言文学\n修业年限：四年\n授予学位：文学学士学位\n培养目标：汉语言文学专业培养学生具备扎实的汉语和中国文学方面的知识，能在新闻文艺出版部门、高校、科研机构和机关企事业单位从事文学评论、汉语言文学教学与研究工作。主要课程包括中国文学史、中国现代文学史、外国文学史等。"; break;
		case 7: stt = "专业名称：历史学\n修业年限：四年\n授予学位：历史学学士学位\n培养目标：历史学专业培养学生系统掌握中国历史和世界历史的基本理论和基本知识，能够从事历史研究、教学和文化工作。主要课程包括中国古代史、中国近代史、世界史等。"; break;
		case 8: stt = "专业名称：应用化学\n修业年限：四年\n授予学位：理学学士学位\n培养目标：应用化学专业培养学生掌握化学的基本理论、基本知识和基本技能，以及相关的工程技术知识，具备从事化学及相关领域的科学研究、技术开发、教育和管理的能力。主要课程包括无机化学、有机化学、分析化学等。"; break;
		case 9: stt = "专业名称：电子科学与技术\n修业年限：四年\n授予学位：工学学士学位\n培养目标：电子科学与技术专业培养学生掌握电子科学与技术的基本理论和基本知识，具备从事电子材料、器件、集成电路、系统的设计、制造和相应的新产品、新技术、新工艺的研究与开发的能力。主要课程包括电路分析基础、模拟电路、数字电路等。"; break;
		case 10: stt = "专业名称：土木工程\n修业年限：四年\n授予学位：工学学士学位\n培养目标：主要课程包括土木工程材料、结构设计原理、土力学与基础工程、房屋建筑学、道路工程等。学生将学习如何应用数学、物理、化学等基础知识来解决土木工程中的实际问题。该专业旨在培养能够从事土木工程项目的设计、施工、管理和研究工作的专门人才。"; break;
		case 11: stt = "专业名称：戏剧学\n修业年限：四年\n授予学位：艺术学学士学位\n培养目标：主要课程包括戏剧概论、中外戏剧史、戏剧理论、戏剧批评、戏剧表演等。学生将学习戏剧艺术的创作原理、表演技巧、批评方法等方面的知识。该专业旨在培养具备戏剧理论素养、戏剧文学创作和戏剧批评能力的人才，以及能够从事戏剧教育、戏剧研究和戏剧管理工作的人员。"; break;
		case 4: stt = "专业名称：法学\n修业年限：四年\n授予学位：法学学士学位\n培养目标：法学专业培养学生系统掌握法学基本理论知识，具备实践能力突出，能够应对司法改革需要，胜任公、检、法等国家机关和企事业单位岗位，从事法律实务或法学教育工作的应用型法律人才。主要课程包括法理学、宪法学、中国法律史等。"; break;
		default:
			break;
		}
		CString ans;
		ans.Format(TEXT("%s"), stt.c_str());
		MessageBox(ans, TEXT("专业信息"));
	}
	else
	{
		MessageBox(TEXT("请选择专业进行查询"), TEXT("提示"));
	}
}
