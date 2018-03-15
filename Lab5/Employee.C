#include"Employee.h"
#include<string>


int Employee::totalNumofEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;


Employee::Employee():officeNo(nextOfficeNo), empId(nextEmpId)
{
 name = "unknown";
 deptNo = 0;
 empPosition = 'E';
 yearOfExp = 0;
 salary = 0;

 totalNumofEmployees++;
 nextEmpId++;
 nextOfficeNo++;
}

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):officeNo(nextOfficeNo), empId(nextEmpId)
{
 name = theName;
 deptNo = theDeptNo;
 empPosition = theEmpPosition;
 yearOfExp = theYearOfExp;
 salary = 0;

 totalNumofEmployees++;
 nextEmpId++;
 nextOfficeNo++;
}


void Employee::Print() const
{
 cout << "\nName: " << name << endl
      << "Dept No: " << deptNo << endl
      << "Emp Position: " << empPosition << endl
      << "Year of Exp: " << yearOfExp << endl
      << "Salary: " << salary << endl
      << "Office No: " << officeNo << endl
      << "Employee ID: " << empId << endl
      << "Num of Employees: " << totalNumofEmployees << endl
      << "Next Emp Id: " << nextEmpId << endl
      << "Next Office No: " << nextOfficeNo << endl;
}


void Employee::GetInfo()
{
 cout << "\nEnter Name (No Spaces): ";
  getline(cin, name);

 cout << "Enter Position(E = Entry , M = Manager, D = Director, P = ProjectLeader):";
  cin >> empPosition;

 cout << "Enter Year Of Exp: ";
  cin >> yearOfExp;
}


Employee::~Employee()
{
 totalNumofEmployees--;
}
