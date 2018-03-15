#include"TenureTrackProf.h"
#include<iostream>


void TenureTrackProf::print() const
{
 CompSciProf::print();
 cout << "Rank: " << rank << endl
      << "Year of Exp: " << YearOfExp << endl;
}


float TenureTrackProf::findSalary() const
{
 float Salary;
 int BaseSal;

 if(rank == 'A')
  BaseSal = 65000;
 else if(rank == 'S')
  BaseSal = 80000;
 else if(rank == 'F')
  BaseSal = 90000;

 Salary = BaseSal + 1500 * YearOfExp;

 return Salary;
}
