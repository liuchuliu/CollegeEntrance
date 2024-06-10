#pragma once
class Profession
{
public:
	Profession();
	Profession(string code, string p_name, int num, string first, string second);
	string code; // 专业代码
	string p_name; // 专业名
	int num; //招收人数
	string first;//首选科目要求
	string second; //再选科目要求
	void inputP(ifstream& in);
};

