#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void Insert(vector<string>&, string, int);
void Delete(vector<string>&, int);
void Print(const vector<string>&);


int main()
{
 vector<string>V;
 string cmd;
 string wd;
 int index;

 ifstream fin;
 fin.open("data.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return -1;
   }
  else
   {
    fin >> cmd;

    while(fin)
     {
      if(cmd == "Insert")
       {
        fin >> wd;
        fin >> index;
        Insert(V, wd, index);
       }
      if(cmd == "Delete")
       {
        fin >> index;
        Delete(V, index);
       }
      if(cmd == "Print")
       {
        Print(V);
       }

      fin >> cmd;
     }
   }

 return 0;
}


void Insert(vector<string>& V, string wd, int index)
{
 //cout << "INDEX " << index << endl; //

 if(V.size()+1 <= index)
  cout << "ERROR CAN'T INSERT \"" << wd 
       << "\" AT INDEX " << index << endl;
 else
  V.insert(V.begin() + index, wd);
}


void Delete(vector<string>& V, int index)
{
 if(V.size() <= index)
  cout << "ERROR CANT DELETE AT INDEX " << index << endl;
 else
  V.erase(V.begin() + index);
}


void Print(const vector<string>& V)
{
 for(int i = 0; i < V.size(); i++)
  {
   cout << V[i] << " ";
  }

 cout << endl;
}
