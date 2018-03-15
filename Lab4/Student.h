#ifndef STUDENT_H
#define STUDENT_H

#include"Course.h"


class Student
{
 private:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
 public:
  void SetAStudent(long StuNum, string C1Name, long C1Num, string C2Name,
                   long C2Num, string C3Name, long C3Num);
  void PrintAStudent();
};

#endif
