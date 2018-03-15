#include"StudentProfile.h"
#include<iostream>
using namespace std;


void StudentProf::SetAStudentProf(string Fn, string Ln, long ssn, int age, char gend,
  long StuNum, string C1Name, long C1Num, string C2Name, long C2Num, string C3Name, long C3Num)
{
  PrsnInfo.SetAPerson(Fn, Ln, ssn, age, gend);
  StdInfo.SetAStudent(StuNum, C1Name, C1Num, C2Name, C2Num, C3Name, C3Num);
}


void StudentProf::PrintAStudentProf()
{
 PrsnInfo.PrintAPerson();
 StdInfo.PrintAStudent();
}
