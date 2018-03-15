/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#ifndef WIFE_H
#define WIFE_H

#include"Child.h"

class Wife;
typedef Wife* WifePtr;

/*
  Purpose: Declares & Initialzes Wife Node
  Author: Jeff Ibarra
  Description: Has protected members and constructors
*/
class Wife: public Person
{
 friend class Family;

 protected:
  ChildPtr myChildren;
 public:
  Wife(){myChildren = NULL;}
  Wife(long id, string Fn, string Ln):Person(id, Fn, Ln)
   {myChildren = NULL;}
};

#endif
