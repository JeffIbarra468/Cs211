#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr;
class CircularDLL;


class Node 
{
	friend class CircularDLL;
private:
      int stId;
	  string stName;
	  string stEmail;
	  int stAge;
      NodePtr next;
      NodePtr prev;
public:
      Node(int id, string name, string email, int age);
};


class CircularDLL
{
private:
	NodePtr  top;
	void destroy (NodePtr&);

public:
	CircularDLL();
	CircularDLL(const CircularDLL& source);
	~CircularDLL();
	void insertDataFromFile();
	void print ();
	bool search (int);
	void insertAfterFirst (int id, string name, string email, int age);
	void insertBeforeFirst (int id, string name, string email, int age);
	void insertAfterLast (int id, string name, string email, int age);
	void insertBeforeLast (int id, string name, string email, int age);
	void remove (int);
	void copy (NodePtr top1, NodePtr& top2);
};


Node::Node(int id, string name, string email, int age)
{
 stId = id;
 stName = name;
 stEmail = email;
 stAge = age;

 next = NULL;
 prev = NULL;
}


// the default constructor
CircularDLL::CircularDLL()
{
 top = NULL;
}


// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
 top = NULL;
 copy(source.top, top);
}


// the destructor
CircularDLL::~CircularDLL()
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
void CircularDLL::insertDataFromFile()
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
         << "(IAL)InsertAfterLast, (IBL)InsertBeforeLast or quit to exit: ";
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
         << "(IAL)InsertAfterLast, (IBL)InsertBeforeLast or quit to exit: ";
       cin >> cmd;
     }

    //cout << "\nYou have exited the program, Thank You" << endl;
   }

 fin.close();
}


// print the linked list
void CircularDLL::print ()
{
 NodePtr p = top;

 if(top == NULL)
  cout << "Nothing in Link List" << endl;
 else
  {
   do
    {
     cout << "ID: " << p -> stId << endl
          << "Name: " << p -> stName << endl
          << "Email: " << p -> stEmail << endl
          << "Age: " << p -> stAge << endl
          << endl;
     p = p -> next;
    }while(p != top);
  }
}


// search for a particular student id in the list
bool CircularDLL::search (int id)
{
 NodePtr Sch = top;

 while(Sch != top)
  {
   if(Sch -> stId == id) // Compares field of SSN w/ id
     return true; // returns address of Family
   else if(Sch != NULL)
     Sch = Sch -> next;
  }

  return false;
}


// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
 if(top == NULL)
  {
   top = new Node(id, name, email, age);
   top -> next = top;
   top -> prev = top;
  }
 else
  {
   NodePtr p = new Node(id, name, email, age);

   p -> next = top -> next;
   p -> prev = top;
   p -> next -> prev = p;
   top -> next = p;
  }
}


// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)
void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{
 if(top == NULL)
  {
   top = new Node(id, name, email, age);
   top -> next = top;
   top -> prev = top;
  }
 else
  {
   NodePtr p = new Node(id, name, email, age);

   p -> next = top;
   p -> prev = top -> prev;
   top -> prev -> next = p;
   top -> prev = p;
   top = p;
  }
}


// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)
void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
 if(top == NULL)
  {
   top = new Node(id, name, email, age);
   top -> next = top;
   top -> prev = top;
  }
 else
  {
   NodePtr p = new Node(id, name, email, age);

   p -> next = top;
   p -> prev = top -> prev;
   top -> prev -> next = p;
   top -> prev = p;
  }
}


// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)
void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
 if(top == NULL)
  {
   top = new Node(id, name, email, age);
   top -> next = top;
   top -> prev = top;
  }
 else if(top -> next == top)
  {
   insertBeforeFirst(id, name, email, age);
  }
 else
  {
   NodePtr p = new Node(id, name, email, age);

   p -> next = top -> prev;
   p -> prev = p -> next -> prev;
   p -> next -> prev = p;
   p -> prev -> next = p;
  }
}


// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
 NodePtr p = top;
 NodePtr q = top -> next;

 while(q != top)
  {
   if(p -> stId == id) // id matches node
    {
     NodePtr Last = p -> prev;
     Last -> next = p -> next;
     q -> prev = Last;
     delete p;
     return;
    }
   p = q;
   q = q -> next;
  }
}


// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{
 NodePtr acurr = atop;
 NodePtr bcurr = btop;

   destroy (btop);   // Free any storage used by target linked list

   if (atop != NULL) 
    {
      btop = new Node(atop -> stId, atop -> stName, atop -> stEmail, atop -> stAge);
      btop -> next = btop;
      btop -> prev = btop;
      acurr = acurr -> next;

     while(acurr != atop)
      {
       NodePtr p = new Node(acurr -> stId, acurr-> stName, acurr -> stEmail, acurr -> stAge);

       p -> next = btop;
       p -> prev = btop -> prev;
       btop -> prev -> next = p;
       btop -> prev = p;

       acurr = acurr -> next;
      }
   }
}

      
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{
 NodePtr p = top;

 if(top == NULL)
  return;

 top = top -> next;

 while(p != top)
  {
   p -> prev -> next = top;
   top -> prev = p -> prev;
   delete p;
   p = top;
   top = top -> next;
  }
 delete p;
 top = NULL;
}


int main () 
{
   CircularDLL list1;
   list1.insertDataFromFile();
   list1.print();
   cout << "----------------------------------------------" << endl;
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   cout << "----------------------------------------------" << endl;
   bool  found = list1.search (12321);
   if (found)
	   cout << "the record was found" << endl;
   else
	   cout << "the record was not found" << endl;
   cout << "----------------------------------------------" << endl;
   list1.remove (54321);
   list1.print();
   cout << "----------------------------------------------" << endl; 
   CircularDLL list2(list1);
   list2.print();
   return 0;
}
