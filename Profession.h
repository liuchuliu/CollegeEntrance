#pragma once
class Profession
{
public:
	Profession();
	Profession(string code, string p_name, int num, string first, string second);
	string code; // רҵ����
	string p_name; // רҵ��
	int num; //��������
	string first;//��ѡ��ĿҪ��
	string second; //��ѡ��ĿҪ��
	void inputP(ifstream& in);
};

