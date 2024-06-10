#include "pch.h"
#include "Student.h"

Student::Student()
{
}

Student::Student(string idd, string namee, string VE)
{
	this->id = idd;
	this->name = namee;
	this->Verify = VE;
}

void Student::inputP(ifstream& in)
{
	in >> id;
	in >> name;
	in >> Verify;
}

void Student::outputF(ofstream& out)
{
	out << id << "\t" << name << "\t" << Verify << "\n";
}
