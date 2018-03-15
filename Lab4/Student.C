#include"Student.h"
#include<iostream>
using namespace std;


void Student::SetAStudent(long StuNum, string C1Name, long C1Num, string C2Name, long C2Num, string C3Name, long C3Num)
{
 StNo = StuNum;
 Course1.SetACourse(C1Name, C1Num);
 Course2.SetACourse(C2Name, C2Num);
 Course3.SetACourse(C3Name, C3Num);
}


void Student::PrintAStudent()
{
 cout << "StNo: " << StNo << endl;
 Course1.PrintACourse();
 Course2.PrintACourse();
 Course3.PrintACourse();
}
