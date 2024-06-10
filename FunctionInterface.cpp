#include "pch.h"
#include "FunctionInterface.h"

bool FunctionInterface::DengLu(Student stu)
{
    CString FilePath1 = _T(".\\学生.txt");
    CString FilePath2 = _T(".\\SubInfo.txt");
    ifstream in1(FilePath1, ios::in);
    ifstream in2(FilePath2, ios::in);
    int num1, num2;
    if (in1.is_open())
    {
        in1 >> num1;
        for (int i = 0; i < num1; i++)
        {
            Student SS;
            SS.inputP(in1);
            Students.push_back(SS);
        }
    }
    for (int i = 0; i < num1; i++)
    {
        if (stu.id == Students[i].id && stu.name == Students[i].name && stu.Verify == Students[i].Verify) 
        {
            if (in2.is_open())
            {
                in2 >> num2;
                for (int i = 0; i < num2; i++)
                {
                    Profession PP;
                    PP.inputP(in2);
                    subs.push_back(PP);
                }
            }
            return true;
        }
    }
    return false;
}

bool FunctionInterface::Zhuce(Student st)
{
    CString FilePath = _T(".\\学生.txt");
    Students.clear();
    ifstream in(FilePath, ios::in);
    int num;
    if (in.is_open())
    {
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Student SS;
            SS.inputP(in);
            Students.push_back(SS);
        }
    }
    Students.push_back(st);
    //注册信息写回
    return Save(FilePath);
}

bool FunctionInterface::Save(CString FilePath)
{
    ofstream out(FilePath, ios::out);
    if (out.is_open())
    {
        out << Students.size() << endl;
        for (int i = 0; i < Students.size(); i++)
        {
            Students[i].outputF(out);
        }
        out.close();
        return true;
    }
    return false;
}

CString FunctionInterface::LuQu(CString af)
{
    CString FilePath = _T(".\\Admission.txt");
    ifstream in(FilePath, ios::in);
    vector<CString> idd;
    vector<CString> sub;
    if (in.is_open())
    {
        int num;
        in >> num;
        for (int i = 0; i < num; i++)
        {
            string old_id, old_sub;
            in >> old_id;
            in >> old_sub;
            idd.push_back(old_id.c_str());
            sub.push_back(old_sub.c_str());
        }
    }
    for (int i = 0; i < idd.size(); i++)
    {
        if (af == idd[i]) 
        {
            return sub[i];
        }
    }
    CString ans ="null";
    return ans;
}

