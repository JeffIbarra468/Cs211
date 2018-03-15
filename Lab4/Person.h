#ifndef PERSON_H
#define PERSON_H

#include<string>
using namespace std;


class Person
{
 private:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender; // (.M. for Male and .F. for Female)
 public:
  void SetAPerson(string Fn, string Ln, long ssn, int age, char gend);
  void PrintAPerson();
};

#endif
