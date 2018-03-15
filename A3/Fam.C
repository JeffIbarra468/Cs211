/*
  Jeff Ibarra
  ibarr021@cougars.csusm.edu
  Date: 04/21/16
  Program Purpose: Make a linked list of a family then print them out
*/

#include"Family.h"
#include<fstream>


/*
  Date: 04/21/16
  Purpose: Return pointer to husband w/ id or NULL if not found
  Parameter: id - SSN
  Local Var: Sch - Search pointer
*/
HusPtr Family::Search(long id)
{
 HusPtr Sch = top;

 while(Sch != NULL) // Searches through husband nodes
  {
   if(Sch -> SSN == id) // Compares field of SSN w/ id
     return Sch; // returns address of Family
   else if(Sch != NULL)
     Sch = Sch -> nextFamily;
  }
 
 return NULL;
}


/*
  Date: 05/04/16
  Purpose: deallocates all node in link list
  Local Var: Hus - Husband pointer
             Wifey - Wife pointer
             Chd - Child pointer
             ChdIter - Child Iretator pointer
*/
bool Family::destroy()
{
 HusPtr Hus = top;
 WifePtr Wifey = Hus -> myWife;
 ChildPtr Chd = Wifey -> myChildren;
 ChildPtr ChdIter = Chd;

 while(top != NULL) // CONSIDER DELETING ALL WIVES & CHILDREN
  {
   if(Wifey != NULL) // Wife exists
    {
     while(ChdIter != NULL) // Child exists
      {
       Wifey -> myChildren = Chd -> mySibling; // Wife points to second child
       ChdIter = ChdIter -> mySibling;
       delete Chd; // Deallocation of Child
       Chd = ChdIter;
      }
     delete Wifey; // Deallocation of Wife
     Hus -> myWife = NULL;
    }
   top = top -> nextFamily;
   delete Hus; // Deallocation of Husband
   Hus = top;
  }

 top = NULL;
}


/*
  Date: 04/21/16
  Purpose: To add a Nusband node to the link list
  Parameters: id - SSN, Fn - First name, Ln - Last name
  Local Var: Sch - Search pointer, p - general pointer
*/
bool Family::AddHusband(long id, string Fn, string Ln)
{
 HusPtr Sch = Search(id);

 if(Sch != NULL)
  {
   cout << "This family w/ id " << id << " already exists" << endl;
   return false;
  }

 HusPtr p = new Husband(id, Fn, Ln);

 p -> nextFamily = top; // Husband gets added
 top = p; // New husband becomes top

 cout << "Family w/ id " << id << " was added" << endl;

 return true;
}


void Family::RemoveHusband(long id)
{
 cout << "REMOVE HUSBAND NOT FINISHED" << endl;
 // SHOULD CALL REMOVE WIFE IN THIS
}


/*
  Date: 04/21/16
  Purpose: Add a wife node to the link list
  Paramters: id - SSN, Fn - First name,
             Ln - Last name, husbandId - husband's SSN
  Local Var: p - Search & general pointer
             w - wife search & pointer
*/
bool Family::AddWife(long id, string Fn, string Ln, long husbandId)
{
 HusPtr p = Search(husbandId);

 if(p == NULL)
  {
   cout << "This husband w/ id " << husbandId << " does not exists" << endl;
   return false;
  }

 if(p -> myWife != NULL)
  {
   cout << "This husband w/ id " << husbandId << " is already married" << endl;
   return false;
  }

 WifePtr w = new Wife(id, Fn, Ln);

 p -> myWife = w; // Husband pointer now points at wife node

 cout << "This husband w/ id " << husbandId 
      << " is now married to " << id << endl;

 return true;
}

  
void Family::RemoveWife(long husbandId)
{
 cout << "REMOVE WIFE NOT FINISHED" << endl;
 // SHOULD CALL REMOVE CHILD
}


/*
  Date: 04/28/16
  Purpose: Add a Child to the link list
  Parameters: id - SSN, Fn - First name,
              Ln - Last name, fatherId - father's SSN
  Local Var: p - husband pointer, NewChi - child pointer
             Sib - new child/sibling node, 
             SibIter - iteration pointer for child/sibling
*/
bool Family::AddAChild(long id, string Fn, string Ln, long fatherId)
{
 HusPtr p = Search(fatherId);
 ChildPtr NewChi = p -> myWife -> myChildren;

 if(p == NULL) // Checks if father exist
  {
   cout << "This father w/ id " << fatherId << " does not exists" << endl;
   return false;
  }
 if(p -> myWife == NULL) // Checks if wife exists
  {
   cout << "This father has no wife thus no child" << endl;
   return false;
  }
 if(NewChi != NULL) // A child exists in link list
  {
   while(NewChi != NULL) // Goes through all child nodes
    {
     if(NewChi -> SSN == id) // Child exists in list
      {
       cout << "This father w/ id " << fatherId 
            << " already child w/ " << id << endl;
       return false;
      }
     else // Child is not in list
      {
       if(NewChi -> mySibling == NULL) // Add child to end of list
        {
         ChildPtr Sib = new Child(id, Fn, Ln);
         NewChi -> mySibling = Sib; // Adds child to list

         cout << "This father w/ id " << fatherId
              << " now has a child w/ id " << id << endl;
         return true;
        }
      }
     NewChi = NewChi -> mySibling; // Goes to next Child if condition not true
    }
  }
 if(NewChi == NULL) // If there is no sibling
  {
   ChildPtr Chd = new Child(id, Fn, Ln);

   p -> myWife -> myChildren = Chd;

   cout << "This father w/ id " << fatherId
        << " now has a child w/ id " << id << endl;

   return true;
  }
}


/*
  Date: 05/04/16
  Purpose: To delete a particular child from link list
  Parameters: fatherId - Dad SSN
              childId - Child's SSN
  LOcal Var: Hus - Husband pointer
             Wifey - Wife pointer
             Chd - Child pointer
             ChdIter - Child Iterator pointer
*/
bool Family::RemoveAChild(long fatherId, long childId)
{
 HusPtr Hus = Search(fatherId);

 if(Hus == NULL) // Father does not exist
  {
   cout << "Father w/ id " << fatherId 
        << "does not exist thus there's no child to delete" << endl;
   return false;
  }

 WifePtr Wifey = Hus -> myWife;

 if(Wifey == NULL) // Mother does not exist
  {
   cout << "Father w/ id " << fatherId
        << " has no wife thus there's no child to delete" << endl;
   return false;
  }

 ChildPtr Chd = Wifey -> myChildren;

 if(Chd == NULL) // No child in list
  {
   cout << "Child w/ id " << childId << " doesn't exist" << endl;
   return false;
  } 
 if(Chd != NULL) // A child exists in link list
  {
   ChildPtr ChdIter = Chd;

   while(Chd != NULL) // Child node gies through list
    {
     if(Chd -> SSN == childId) // Child search for found
      {
       if(Chd == Wifey -> myChildren) // Found node first in child list
        {
         Wifey -> myChildren = Chd -> mySibling; // Wife points to "second" child
         delete Chd;

         cout << "Child w/ ID " << childId 
              << " has been succesfully deleted" << endl;
         return true;
        }
       ChdIter -> mySibling = Chd -> mySibling; 
       delete Chd;

       cout << "Child w/ ID " << childId
              << " has been succesfully deleted" << endl;
       return true;
      }
     ChdIter = Chd;
     Chd = Chd -> mySibling; // Goes to next child
    }

  cout << "Child w/ ID " << childId << " can't be deleted" << endl;
  return false;
  } 
}


/*
  Date: 04/28/16
  Purpose: Print a particular family
  Parameter: fatherId - husband's/father's SSN
  Local var: Hus - genral husband pointer
             Wife - Wife pointer
             Child - Child pointer
*/
void Family::PrintAFamily(long fatherId)
{
 HusPtr Hus = Search(fatherId);
 WifePtr Wife = NULL; 
 ChildPtr Child = NULL;

 if(Hus == NULL) // Husband does not exists
  {
   cout << "No Family w/ id " << fatherId << " exists" << endl;
   return;
  }

 while(Hus -> SSN != fatherId)
     Hus = Hus -> nextFamily;

 if(Hus -> SSN == fatherId) // Prints husband
  {
   cout << "\nHus/Fath SSN: " << Hus -> SSN << endl
        << "Hus/Fath Name: " << Hus -> Fname 
        << " " << Hus -> Lname << endl;

   Wife = Hus -> myWife;

   if(Wife == NULL) // If wife node does not exist
    {
     cout << "NO WIFE" << endl; 
    }
   else // Wife exists
    {
     cout << "Wife SSN: " << Wife -> SSN << endl
          << "Wife Name: " << Wife -> Fname
          << " " << Wife -> Lname << endl;

     Child = Wife -> myChildren;

     if(Child == NULL) // Child does not exist
      {
       cout << "NO CHILD" << endl;
      }
     else // Child exist
      {
       cout << "Child SSN: " << Child -> SSN << endl
            << "Child Name: " << Child -> Fname
            << " " << Child -> Lname << endl;

       if(Child -> mySibling == NULL) // If sibling does not exists
         return;
       else
        {
         ChildPtr Sibling = Child -> mySibling;

         while(Sibling != NULL) // If sibling exists
          {
           cout << "Child SSN: " << Sibling -> SSN << endl
                << "Child Name: " << Sibling -> Fname
                << " " << Sibling -> Lname << endl;

           Sibling = Sibling -> mySibling; // Increments to last node
          }
        }
      }
    }
  }
 else // No one exists
   cout << "\nFamily of id " << fatherId << "does not exist" << endl;
}


/*
  Date: 05/03/16
  Purpose: Print all families in link list
  Local Variables: Fam - Family(Husband) pointer
*/
void Family::PrintAllFamilies()
{
 HusPtr Fam = top;

 while(Fam != NULL) // Goes through Husband pointer list
  {
   PrintAFamily(Fam -> SSN);

   Fam = Fam -> nextFamily; // Next Family becomes family
  } 
}


/*
  Date: 05/04/16
  Purpose: Interface of the computer program
  Local Var: cmd - command for functions
             parameter - variable that gets passed as parameter
             MAX_LET - comestic purposes
*/
void Family::ReadTransactionFile()
{
 string cmd;
 long id, husbandId, fatherId, childId;
 string Fn, Ln;
 ifstream fin;
 string fileName;  // FileName for transactionaction file

 cout << "Enter a transaction file: ";
  cin >> fileName;                       // Enters filename
 cout << endl;

 fin.open(fileName.data());

  if(fin.fail())  //File checker
   {
    cout << "File failed to be opened" << endl;
   }
  else
   {
    while(!fin.eof())  // As long as there is something in file it will cont to fin
     {
      fin >> cmd;       // Gets command from file

      if(cmd == "AddHusband")
       {
        cout << "************* AddHusband **************" << endl;
        fin >> id >> Fn >> Ln;
        AddHusband(id, Fn, Ln);
       }
      else if(cmd == "RemoveHusband")
       {
        cout << "************ RemoveHusband ***********" << endl;
        fin >> id;
        RemoveHusband(id);
       }
      else if(cmd == "AddWife")
       {
        cout << "*********** AddWife ***************" << endl;
        fin >> id >> Fn >> Ln >> husbandId;
        AddWife(id, Fn, Ln, husbandId);
       }
      else if(cmd == "RemoveWife")
       {
        cout << "*********** RemoveWife ************" << endl;
        fin >> husbandId;
        RemoveWife(husbandId);
       }
      else if(cmd == "AddAchild")
       {
        cout << "*********** AddAchild **************" << endl;
        fin >> id >> Fn >> Ln >> fatherId;
        AddAChild(id, Fn, Ln, fatherId);
       }
      else if(cmd == "RemoveAchild")
       {
        cout << "************ RemoveAchild ***********" << endl;
        fin >> fatherId >> childId;
        RemoveAChild(fatherId, childId);
       }
      else if(cmd == "PrintAFamily")
       {
        cout << "*********** PrintAFamily *************" << endl;
        fin >> fatherId;
        PrintAFamily(fatherId);
       }
      else if(cmd == "PrintAllFamilies")
       {
        cout << "************ PrintAllFamilies *********" << endl;
        PrintAllFamilies();
       }
      else
       cout << "Invalid Input" << endl; // cmd not equal any of these inputs
     }

    fin >> cmd; // Next command from file
   }
 fin.close();
}
