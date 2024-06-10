#pragma once
class Student
{
public:
	Student();
	Student(string idd, string namee, string VE);
	string id;//虚拟考生编号
	string name;//虚拟考生姓名
	string Verify; //虚拟考生身份证后六位号码
	void inputP(ifstream& in);//输入到程序
	void outputF(ofstream& out);//输出到文件

};

