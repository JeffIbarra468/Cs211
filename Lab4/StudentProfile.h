#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include"Person.h"
#include"Student.h"
#include<string>


class StudentProf
{
 private:
  Person PrsnInfo;
  Student StdInfo;
 public:
  void SetAStudentProf(string Fn, string Ln, long ssn, int age, char gend, long StuNum,
       string C1Name, long C1Num, string C2Name, long C2Num, string C3Name, long C3Num);
  void PrintAStudentProf();
};

#endif
