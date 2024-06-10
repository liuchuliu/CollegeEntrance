// Brochure.cpp: 实现文件
//

#include "pch.h"
#include "UniEntrance.h"
#include "afxdialogex.h"
#include "Brochure.h"


// Brochure 对话框

IMPLEMENT_DYNAMIC(Brochure, CDialogEx)

Brochure::Brochure(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Brochure, pParent)
{

}

Brochure::~Brochure()
{
}

void Brochure::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_richEditCtrl);
}


BEGIN_MESSAGE_MAP(Brochure, CDialogEx)
	ON_EN_CHANGE(IDC_RICHEDIT21, &Brochure::OnEnChangeRichedit21)
	ON_BN_CLICKED(IDOK, &Brochure::OnBnClickedOk)
END_MESSAGE_MAP()


// Brochure 消息处理程序


void Brochure::OnEnChangeRichedit21()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序
}


void Brochure::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL Brochure::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	string sdd = "某某大学本科招生章程\n一、学校简介\n某某大学是一所历史悠久、文化底蕴深厚的综合类本科院校。学校坐落于首都北京，占地面积8000亩，拥有现代化\n的教学设施和优美的校园环境。学校致力于培养具有创新精神和实践能力的高素质人才。\n二、招生专业与计划\n某某大学设有文、理、工、法、教育、艺术等多个学科门类，涵盖230个本科专业。学校根据国家教育部及省级招生\n部门的相关政策，结合学校实际情况，制定年度本科招生计划。具体招生专业及计划以当年公布的招生章程为准。\n三、报考条件\n考生须参加当年全国普通高等学校招生统一考试（高考），并取得有效成绩；\n考生须符合所在省（市、自治区）招生部门规定的报考条件；\n考生身体健康，符合《普通高等学校招生体检工作指导意见》的相关规定。\n四、录取原则\n学校遵循公平、公正、公开的原则，按照考生高考成绩及志愿顺序进行录取；\n对于达到我校录取分数线的考生，学校将根据其专业志愿和综合素质进行综合评价，择优录取；\n学校将根据招生计划和考生报考情况，适时调整录取分数线及录取批次。\n五、学费与奖学金\n学费标准：学校将按照国家和省级物价部门核定的标准收取学费，具体收费标准以学校公布的为准；\n奖学金政策：学校设有各类奖学金，以鼓励优秀学生全面发展。具体奖学金种类、评定标准及发放办法详见学校相\n关规定。\n六、其他事项\n本招生简章未尽事宜，按照国家和省级招生部门的相关规定执行；\n学校将通过官方网站、招生咨询热线等渠道发布招生信息，请考生及家长密切关注；\n学校保留对招生章程进行解释和修改的权利。";

	// 设置 CRichEditCtrl 的文本
	m_richEditCtrl.SetWindowText(sdd.c_str());
	m_richEditCtrl.UpdateWindow();

	//RECT rect;
	//m_richEditCtrl.GetClientRect(&rect);

	// 创建一个新的矩形，用于限制文本显示区域（例如，缩小高度）  
	//RECT textRect = { rect.left, rect.top, rect.right, rect.top + 100 }; // 假设我们限制高度为100  

	// 使用 EM_SETRECT 消息设置文本渲染区域  
	//m_richEditCtrl.SendMessage(EM_SETRECT, 0, reinterpret_cast<LPARAM>(&textRect));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
