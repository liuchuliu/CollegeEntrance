#pragma once
class Student
{
public:
	Student();
	Student(string idd, string namee, string VE);
	string id;//���⿼�����
	string name;//���⿼������
	string Verify; //���⿼�����֤����λ����
	void inputP(ifstream& in);//���뵽����
	void outputF(ofstream& out);//������ļ�

};

