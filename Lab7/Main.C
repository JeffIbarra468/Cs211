#include"AdjunctProf.h"
#include"TenureTrackProf.h"
#include<iostream>

int main()
{
 AdjunctProf P1("Adam Smith","asmith@csusm.edu",12345,'M',2,1);
 P1.print();
 cout << "Salary: " << P1.findSalary() << endl;

 TenureTrackProf P2("Jim Anderson","janderson@csusm.edu",54321,'S',8);
 P2.print();
 cout << "Salary: " << P2.findSalary() << endl;

 return 0;
}
