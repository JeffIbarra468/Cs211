#include"Employee.h"


int main()
{
 Employee emp1;
 emp1.Print(); 

 Employee emp2("unknown", 10, '?', 0);
 emp2.GetInfo();
 SetSalary(emp2);
 emp2.Print();
 
 return 0;
}


void SetSalary(Employee& Emp)
{
 if(Emp.empPosition == 'E' && Emp.yearOfExp < 2)
   Emp.salary = 50000;
 else if(Emp.empPosition == 'E' && Emp.yearOfExp >= 2)
   Emp.salary = 55000;
 else if(Emp.empPosition == 'P' && Emp.yearOfExp < 4)
   Emp.salary = 60000;
 else if(Emp.empPosition == 'P' && Emp.yearOfExp >= 4)
   Emp.salary = 65000;
 else if(Emp.empPosition == 'M')
   Emp.salary = 70000;
 else if(Emp.empPosition == 'D')
   Emp.salary = 80000;
}
