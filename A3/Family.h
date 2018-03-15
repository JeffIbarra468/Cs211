/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#ifndef FAMILY_H
#define FAMILY_H

#include"Husband.h"

/*
  Purpose: Declares & Initialzes Family Node
  Author: Jeff Ibarra
  Description: Has a protected "top" member, and functions of program
*/
class Family
{
 protected:
  HusPtr top;
 public:
  Family(){top = NULL;}
  bool destroy();
  ~Family(){destroy();}
  HusPtr Search(long id);
  bool AddHusband(long id, string Fn, string Ln);
  void RemoveHusband(long id);
  bool AddWife(long id, string Fn, string Ln, long husbandId);
  void RemoveWife(long husbandId);
  bool AddAChild(long id, string Fn, string Ln, long fatherId);
  bool RemoveAChild(long fatherId, long childId);
  void PrintAFamily(long fatherId);
  void PrintAllFamilies();
  void ReadTransactionFile();
};

#endif
