/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#ifndef CHILD_H
#define CHILD_H

#include"Person.h"

class Child;
typedef Child* ChildPtr;

/*
  Purpose: Declares & Initialzes Child Node
  Author: Jeff Ibarra
  Description: Has protected members and constructors
*/
class Child: public Person
{
 friend class Family;

 protected:
  ChildPtr mySibling;
 public:
  Child(){mySibling = NULL;}
  Child(long id, string Fn, string Ln):Person(id, Fn, Ln)
   {mySibling = NULL;}
};

#endif
