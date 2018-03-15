#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr;
class LL;


class Node 
{
	friend class LL;
private:
      int stId;
	  string stName;
	  string stEmail;
	  int stAge;
      NodePtr nextStudent;
public:
      Node(int id, string name, string email, int age);
};


class LL
{
private:
	NodePtr  top;
	void destroy (NodePtr&);
public:
	LL();
	LL(const LL& source);
	~LL();
	void insertDataFromFile();
	void print();
	bool search (int);
	void insertAfterFirst (int id, string name, string email, int age);
	void insertBeforeFirst (int id, string name, string email, int age);
	void insertAfterLast (int id, string name, string email, int age);
	void insertBeforeLast (int id, string name, string email, int age);
	void remove (int);
        //void copy(NodePtr atop, NodePtr& btop);
	void copy (NodePtr top1, NodePtr& top2);
};


Node::Node(int id, string name, string email, int age)
{
 stId = id;
 stName = name;
 stEmail = email;
 stAge = age;
 nextStudent = NULL;
}


// the default constructor
LL::LL()
{
 top = NULL;
}


// the copy constructor
LL::LL(const LL& source)
{
 top = NULL;
 copy(source.top,top);
}


// the destructor
LL::~LL()
{
 destroy(top);
}


// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
	76543	Mary	mary@csusm.edu		19
	98765	Kathy	kathy@csusm.edu		30
	16438	Flora	flora@csusm.edu		25
	43260	Peter	peter@csusm.edu		29
	87590	kim		kim@csusm.edu		31
*/
void LL::insertDataFromFile()
{
 ifstream fin;
 string fileName;
 int id, age;
 string name, email;

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
    while(!fin.eof())
     {
      fin >> id >> name >> email >> age;
      insertAfterLast(id, name, email, age);
     }

    string cmd;

    cout << "Type (IAF)InsertAfterFirst, (IBF)InsertBeforeFirst," << endl
         << "(IAL)InsertAfterLast, (IBL)InsertBeforeLast" << endl
         << "or \"quit\" to exit: ";
     cin >> cmd;

    while(cmd != "quit")
     {
    if(cmd == "IAF")
      {
       fin >> id >> name >> email >> age;

       insertAfterFirst(id, name, email, age);
      }
    if(cmd == "IBF")
      {
       fin >> id >> name >> email >> age;

       insertBeforeFirst(id, name, email, age);
      }
    if(cmd == "IAL")
      {
       fin >> id >> name >> email >> age;

       insertAfterLast(id, name, email, age);
      }
    if(cmd == "IBL")
      {
       fin >> id >> name >> email >> age;

       insertBeforeLast(id, name, email, age);
      }
     
      cout << "Type (IAF)InsertAfterFirst, (IBF)InsertBeforeFirst," << endl
           << "(IAL)InsertAfterLast, (IBL)InsertBeforeLast" << endl
           << "or \"quit\" to exit: "; 
       cin >> cmd;
     }

    cout << "\nYou have exited the program, Thank You" << endl;
   }

 fin.close();

}


// print the linked list
void LL::print()
{

 NodePtr p = top;

 while(p != NULL)
  {
   cout << "ID: " << p -> stId << endl
        << "Name: " << p -> stName << endl
        << "Email: " << p -> stEmail << endl
        << "Age: " << p -> stAge << endl
        << endl;

   p = p -> nextStudent;
  }

}


// search for a particular student id in the list
bool LL::search(int id)
{
 NodePtr p = top;

 while(p != NULL)
  {
   if(p -> stId == id)
     return true;
   else
     p = p -> nextStudent;
  }

  return false;
}

// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6
void LL::insertAfterFirst(int id, string name, string email, int age)
{
 if(top == NULL)
  {
   NodePtr p = new Node(id, name, email, age);
   p -> nextStudent = top;
   top = p;
  }
 else
  { 
   NodePtr curr = top -> nextStudent;

   NodePtr p = new Node(id, name, email, age);
   p -> nextStudent = curr;
   top -> nextStudent = p;
  }
}


// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6
void LL::insertBeforeFirst(int id, string name, string email, int age)
{
/*
 if(search(id))
  {
   cout << "Already in list" << endl;
   return false;
  }
*/
 NodePtr p = new Node(id, name, email, age);
 p -> nextStudent = top; 
 top = p;
}


// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10
void LL::insertAfterLast(int id, string name, string email, int age)
{
 if(top == NULL)
  {
   NodePtr p = new Node(id, name, email, age);
   p -> nextStudent = top;
   top = p;
  }
 else
  {
   NodePtr curr = top;

   NodePtr p = new Node(id, name, email, age);

   while(curr -> nextStudent != NULL)
     curr = curr -> nextStudent;

   curr -> nextStudent = p;
  }
}


// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6
void LL::insertBeforeLast(int id, string name, string email, int age)
{
 if(top == NULL)
  {
   NodePtr p = new Node(id, name, email, age);
   p -> nextStudent = top;
   top = p;
  }
 else
  {
   NodePtr p = new Node(id, name, email, age);
   NodePtr AfPtr, BfPtr;

   AfPtr = BfPtr = top;

   while(AfPtr -> nextStudent != NULL)
    {
     BfPtr = AfPtr;
     AfPtr = AfPtr -> nextStudent;
    }

   p -> nextStudent = AfPtr;
   BfPtr -> nextStudent = p;
  }
}


// removes a node from the list based on the given student id 
void LL::remove(int id)
{
 if(top == NULL)
   cout << "There is nothing to delete" << endl;
 if((top -> nextStudent == NULL)&&(top -> stId == id))
  {
   delete top;
   top = NULL;
   cout << "Student " << id << " was deleted" << endl;
  }

 NodePtr AfPtr = top;
 NodePtr BfPtr = top;
 NodePtr Holder = NULL;

 while(AfPtr != NULL)
  {
   if(AfPtr -> stId == id)
    {
     Holder = AfPtr -> nextStudent;
     BfPtr -> nextStudent = Holder;
     delete AfPtr;

     cout << "Student " << id << " was deleted" << endl;
    }
   else
    {
     BfPtr = AfPtr;
     AfPtr = AfPtr -> nextStudent;
    }
  }
}


// copies one list into another
void LL::copy(NodePtr atop, NodePtr& btop)
{
 NodePtr acurr, bcurr;
 int id, age;
 string name, email;

   destroy (btop); // deleted previous nodes in the list if there is any
   if(atop != NULL)
    {
      btop = new Node(id, name, email, age);
      btop -> stId = atop -> stId;
      btop -> stName = atop -> stName;
      btop -> stEmail = atop -> stEmail;
      btop -> stAge = atop -> stAge; 
      acurr = atop;
      bcurr = btop;
      while(acurr -> nextStudent != NULL)
       {
        bcurr -> nextStudent = new Node(id, name, email, age);
        acurr = acurr -> nextStudent;
        bcurr = bcurr -> nextStudent;
        bcurr -> stId = acurr -> stId;
        bcurr -> stName = acurr -> stName;
        bcurr -> stEmail = acurr -> stEmail;
        bcurr -> stAge = acurr -> stAge;
       }
      bcurr -> nextStudent = NULL;
    } 
}       


// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
 NodePtr p = top;

 while(top != NULL)
  {
   top = top -> nextStudent;
   delete p;
   p = top;
  }

 top = NULL;
}


int main () 
{
   LL list1;
   list1.insertDataFromFile();
   list1.print();
   cout << "------------------------------------------------" << endl;
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   bool  found = list1.search (12321);
   if (found)
	   cout << "the record was found" << endl;
   else	   
           cout << "the record was not found" << endl;
   cout << "------------------------------------------------" << endl;
   list1.remove (54321);
   list1.print();
   cout << "------------------------------------------------" << endl;
   LL list2(list1);
   list2.print();

   return 0;
}
