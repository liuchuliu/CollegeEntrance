#include "pch.h"
#include "Profession.h"

Profession::Profession()
{
}

Profession::Profession(string code, string p_name, int num, string first, string second)
{
	this->code = code;
	this->p_name = p_name;
	this->num = num;
	this->first = first;
	this->second = second;
}

void Profession::inputP(ifstream& in)
{
	in >> code;
	in >> p_name;
	in >> num;
	in >> first;
	in >> second;
}
