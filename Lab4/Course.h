#ifndef COURSE_H
#define COURSE_H


#include<string>
using namespace std;


class Course
{
 private:
  long CourseNum;
  string CourseName;
 public:
  void SetACourse(string name, long num);
  void PrintACourse();
};


#endif
