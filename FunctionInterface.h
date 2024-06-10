#pragma once
#include "Profession.h"
#include "Student.h"
class FunctionInterface
{
public:
	bool DengLu(Student stu);
	bool Zhuce(Student st);
	vector<Student> Students;
	vector<Profession> subs;
	bool Save(CString FilePath);
	CString LuQu(CString af);
};

