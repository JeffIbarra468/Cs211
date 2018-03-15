#include"Person.h"
#include<iostream>


void Person::SetAPerson(string Fn, string Ln, long ssn, int age, char gend)
{
 Fname = Fn;
 Lname = Ln;
 SSN = ssn;
 Age = age;
 Gender = gend;
}


void Person::PrintAPerson()
{
 cout << "Name: " << Fname << " " << Lname << endl
      << "SSN: " << SSN << endl
      << "Age: " << Age << endl
      << "Gender: " << Gender << endl;
}
