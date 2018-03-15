#include"Course.h"
#include<iostream>
using namespace std;


void Course::SetACourse(string name, long num)
{
 CourseNum = num;
 CourseName = name;
}


void Course::PrintACourse()
{
 cout << "Course Name: " << CourseName << endl
      << "Course Num: " << CourseNum << endl;
}
