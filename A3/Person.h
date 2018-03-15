/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
using namespace std;

class Person;

/*
  Purpose: Parent class of subsequent classes
  Author: Jeff Ibarra
  Description: Has SSN, Fname, Lname as protected members
*/
class Person
{
 friend class Family;

 protected:
  long SSN;
  string Fname, Lname;
 public:
  Person(){SSN = 0; Fname = Lname = " ";}
  Person(long id, string Fn, string Ln)
   {SSN = id; Fname = Fn; Lname = Ln;}
};

#endif
