/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#ifndef HUSBAND_H
#define HUSBAND_H

#include"Wife.h"

class Husband;
typedef Husband* HusPtr;

/*
  Purpose: Declares & Initialzes Husband Node
  Author: Jeff Ibarra
  Description: Has protected members and constructors
*/
class Husband: public Person
{
 friend class Family;

 protected:
  HusPtr nextFamily;
  WifePtr myWife;
 public:
  Husband(){nextFamily = NULL; myWife = NULL;}
  Husband(long id, string Fn, string Ln):Person(id, Fn, Ln)
   {nextFamily = NULL; myWife = NULL;}
};

#endif
