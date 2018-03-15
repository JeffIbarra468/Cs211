/*
  Jeff Ibarra
  05/19/16
  Cs211-Lab11
  Purpose: Program of a tree with many different types print functions
           with structures of queue and stack implemented
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class TreeStruct;
class Tree;
class Stack;
class Queue;

typedef TreeStruct* TreeStructPtr;
typedef Tree* TreePtr;


class Stack
{
private:
	vector<TreeStructPtr> s;
public:
	void push(TreeStructPtr ptr) {s.insert(s.begin(), ptr);}
	TreeStructPtr pop(){ TreeStructPtr ptr = s[0]; s.erase(s.begin()); return ptr;}
	bool empty(){return (s.size()==0);}
};

class Queue
{
private:
	vector<TreeStructPtr> q;
public:
	void push(TreeStructPtr ptr) {q.push_back(ptr);}
	TreeStructPtr pop(){ TreeStructPtr ptr = q[0]; q.erase(q.begin()); return ptr;}
	bool empty(){return (q.size()==0);}
};


class TreeStruct
{
 public:
    int Number;
    TreeStructPtr Left;
    TreeStructPtr Right;
};


class Tree
{
 public:

  TreeStructPtr TreeRoot;

  Tree();
  void InsertIntoTree(TreeStructPtr& Root, int num); 
  int  FindMaxLen(TreeStructPtr Root); 
  int  FindMinLen(TreeStructPtr Root); 
  int  CountNodes(TreeStructPtr Root);
  void Copy(TreeStructPtr Root1, TreeStructPtr& Root2); //copies one tree into another
  bool Search(TreeStructPtr Root, int n);
  void PrintInOrderTree(TreeStructPtr Root);
  void PrintPreOrderTree(TreeStructPtr Root);
  void PrintPostOrderTree(TreeStructPtr Root);
 
  void PrintPreOrderTreeWithStack(TreeStructPtr Root);
  void PrintBreadthFirstWithQueue(TreeStructPtr Root);

};


// tree constructor
Tree::Tree()
{
 TreeRoot = NULL;
}


void Copy(TreeStructPtr Root1, TreeStructPtr& Root2) //copies one tree into another
{ 
 if(Root1 == NULL)
  {
   Root2 = NULL;
   return;
  }

 Root2 = new TreeStruct; // Makes a New Node
 Root2 -> Number = Root1 -> Number; // Copies variables into new tree
 Copy(Root1 -> Left, Root2 -> Left);  // Recursion towards left side of tree
 Copy(Root1 -> Right, Root2 -> Right); // Recursion towards right side of tree
}


// Inserting into the tree using recursion
void Tree::InsertIntoTree(TreeStructPtr& Root, int x)
{
 if(Root  == NULL)
  {
  Root = new TreeStruct;
  Root -> Number = x;
  Root -> Left = NULL;
  Root -> Right = NULL;
  return;
  }
 if(Root -> Number > x)
  InsertIntoTree(Root -> Left, x);
 else if(Root -> Number < x)
  InsertIntoTree(Root -> Right, x);
 else
  cout << "\n" << x << "is in the tree already!" << endl;
}


int Tree::FindMaxLen(TreeStructPtr Root)
{
 if(Root == NULL)
  return 0;
 if(Root -> Left == NULL) // No nodes on left side of tree
  return (1 + FindMaxLen(Root -> Right)); // Add Node from upper then and below node
 if(Root -> Right == NULL) // No nodes on right side of tree
  return (1 + FindMaxLen(Root -> Left)); // Add Node from upper then and below node

 int L = 1 + FindMaxLen(Root -> Left); // Adds Node from upper then next level below
 int R = 1 + FindMaxLen(Root -> Right); // Adds Node from upper then next level below

 if(L > R) // If left list is longer than right
   return L;
 return R;

}


int Tree::FindMinLen(TreeStructPtr Root)
{
 if (Root==NULL)
   return(0);
 else if (Root->Right==NULL)
   return(1+FindMinLen(Root->Left));
 else if (Root->Left==NULL)
   return(1+FindMinLen(Root->Right));
 else
 {
	 int CountLeft =  1 + FindMinLen(Root->Left);
	 int CountRight = 1 + FindMinLen(Root->Right);
	 if (CountLeft < CountRight)
		 return(CountLeft);
	 else
		 return(CountRight);
 }
}


int Tree::CountNodes(TreeStructPtr Root)
{
 if(Root == NULL)
   return 0;
 if(Root -> Left == NULL)
   return(1 + CountNodes(Root -> Right)); // Chexks other side
 if(Root -> Right == NULL)
   return(1 + CountNodes(Root -> Left)); // Checks other side

 int L = CountNodes(Root -> Left);
 int R = CountNodes(Root -> Right);

 return(L + R + 1);
}


bool Tree::Search(TreeStructPtr Root, int n)
{
 if(Root == NULL) // Condition if no tree or tree reaches NULL
   return false;
 if(Root -> Number == n)
  {
   //cout << "1ROOT NUM: " << Root -> Number << " vs n: " << n << endl; //
   return true;
  }
 if(Root -> Number > n)
  {
   //cout << "2ROOT NUM: " << Root -> Number << " vs n: " << n << endl; //
   return (Search(Root -> Left, n)); // Return needed to return every condition
  }
 else if(Root -> Number < n)
  {
   //cout << "3ROOT NUM: " << Root -> Number << " vs n: " << n << endl; //
   return (Search(Root -> Right, n)); // Return needed to return every condition
  }

//	return " ";

}


void Tree::PrintInOrderTree(TreeStructPtr Root)
{
 TreeStructPtr p = Root;

 if(p == NULL)
   return;
  PrintInOrderTree(p -> Left);
  cout << p -> Number << "-->"; // Prints before greater and after less term
  PrintInOrderTree(p -> Right);
}


void Tree::PrintPreOrderTree(TreeStructPtr Root)
{
 TreeStructPtr p = Root;

 if(p == NULL)
   return;
 cout << p -> Number << "-->"; // Prints as least term 
 PrintPreOrderTree(p -> Left); // Checks left until NULL
 PrintPreOrderTree(p -> Right); // Checks right until NULL
}


void Tree::PrintPostOrderTree(TreeStructPtr Root)
{
 TreeStructPtr p = Root;

 if(p == NULL)
   return;
 PrintPreOrderTree(p -> Left); // Checks left until NULL
 PrintPreOrderTree(p -> Right); // Checks right until NULL
 cout << p -> Number << "-->"; // Print as largest number in respect to least most list
}


void Tree::PrintPreOrderTreeWithStack(TreeStructPtr Root)
{
	Stack stk;
	TreeStructPtr p = Root;
	if (p != NULL)
	{
		stk.push(p);
		while (!stk.empty())
		{		
			p = stk.pop(); // Pops top of stack
			cout << p->Number << "-->";
			if (p->Right != NULL)
				stk.push(p->Right); // Pushes right below first
			if (p->Left != NULL)
				stk.push(p->Left); // Pushes left last so it outputs first
		}
	}
}


void Tree::PrintBreadthFirstWithQueue(TreeStructPtr Root)
{
 Queue Que;
 TreeStructPtr p = Root;

 if(p != NULL)
  {
   Que.push(p);

   while(!Que.empty())
    {
     p = Que.pop();

     cout << p -> Number << "-->";
     if(p -> Left != NULL)
       Que.push(p -> Left);
     if(p -> Right != NULL)
       Que.push(p -> Right);
    }
  }
}


int main()
{
 Tree t;
 t.InsertIntoTree(t.TreeRoot, 15);
 t.InsertIntoTree(t.TreeRoot, 20);
 t.InsertIntoTree(t.TreeRoot, 10);
 t.InsertIntoTree(t.TreeRoot, 8);
 t.InsertIntoTree(t.TreeRoot, 9);
 t.InsertIntoTree(t.TreeRoot, 17);
 t.InsertIntoTree(t.TreeRoot, 21);
 t.InsertIntoTree(t.TreeRoot, 22);
 t.InsertIntoTree(t.TreeRoot, 23);
 t.InsertIntoTree(t.TreeRoot, 24);
 t.InsertIntoTree(t.TreeRoot, 25);
 t.InsertIntoTree(t.TreeRoot, 26);
 t.InsertIntoTree(t.TreeRoot, 11);

 cout << "\nPrinting Pre Order " << endl;
 t.PrintPreOrderTree(t.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;
// getchar();

 cout << "Printing Post Order " << endl;
 t.PrintPostOrderTree(t.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;
 //getchar();

 cout << "Printing In Order " << endl;
 t.PrintInOrderTree(t.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;
 //getchar();

 cout << boolalpha << endl << endl;
 cout << "\nSearching 30: " << t.Search(t.TreeRoot, 30) << endl;
 cout << "\nSearching 8: " << t.Search(t.TreeRoot, 8) << endl;
 cout << "\nSearching 10: " << t.Search(t.TreeRoot, 10) << endl;
 cout << "-------------------------------------------" << endl;
 //getchar();

 cout << "Printing Pre Order with Stack " << endl;
 t.PrintPreOrderTreeWithStack(t.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;
 //getchar();

 cout << "Printing level by level BreathFirst Traversal " << endl;
 t.PrintBreadthFirstWithQueue(t.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;
 //getchar();

 cout << endl;


 int MaxLen = t.FindMaxLen(t.TreeRoot);
 int MinLen = t.FindMinLen(t.TreeRoot);
 int TotalNodes = t.CountNodes(t.TreeRoot);
 cout << "Max is " << MaxLen << endl;
 cout << "Min is " << MinLen << endl;
 cout << "Num of Nodes is " << TotalNodes << endl;
 cout << "-----------------------------------------------" << endl;
 //getchar();

 Tree t2;
 Copy(t.TreeRoot, t2.TreeRoot);
 cout << "Printing In Order the copy of the tree" << endl;
 t2.PrintInOrderTree(t2.TreeRoot);
 cout << "\n-----------------------------------------------" << endl;

 return 0;
}
