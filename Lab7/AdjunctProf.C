#include"AdjunctProf.h"
#include<iostream>


void AdjunctProf::print() const
{
 CompSciProf::print();
 cout << "Degree: " << degree << endl
      << "# of TA: " << NoOfTA << endl
      << "# of Courses: " << NoOfCourses << endl;
}


float AdjunctProf::findSalary() const
{
 float Salary;
 
 if(degree == 'B')
   Salary = 1500 * NoOfTA + 3000 * NoOfCourses;
 else if(degree == 'M')
   Salary = 2000 * NoOfTA + 4000 * NoOfCourses;
 else if(degree == 'P')
   Salary = 2500 * NoOfTA + 5000 * NoOfCourses;

 return Salary;
}
