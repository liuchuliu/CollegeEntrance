#include "pch.h"
#include "Lishi.h"

Lishi::Lishi()
{
}

Lishi::Lishi(string idd, string nname, int s23, int s22, int s21, int s20)
{
	this->idd = idd;
	this->nname = nname;
	this->s23 = s23;
	this->s22 = s22;
	this->s21 = s21;
	this->s20 = s20;
}

void Lishi::inputP(ifstream& in)
{
	in >> idd;
	in >> nname;
	in >> s23;
	in >> s22;
	in >> s21;
	in >> s20;
}
