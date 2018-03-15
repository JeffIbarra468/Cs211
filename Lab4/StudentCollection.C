#include"StudentCollection.h"
#include<iostream>
#include<fstream>
using namespace std;


void StdCol::GetInfo()
{
 string Fn;
 string Ln;
 long ssn;
 int age;
 char gend;
 long StuNum;
 string C1Name;
 long C1Num;
 string C2Name;
 long C2Num;
 string C3Name;
 long C3Num;

 ifstream fin;

 fin.open("Lab4_data.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    fin >> Fn >> Ln >> ssn >> age >> gend >> StuNum >> C1Name >> C1Num >> C2Name >> C2Num >> C3Name >> C3Num;

    while(fin)
     {
      StudentProf NewProf;

      NewProf.SetAStudentProf(Fn, Ln, ssn, age, gend, StuNum, C1Name, C1Num, C2Name, C2Num, C3Name, C3Num);

      StCol.push_back(NewProf);

      fin >> Fn >> Ln >> ssn >> age >> gend >> StuNum >> C1Name >> C1Num >> C2Name >> C2Num >> C3Name >> C3Num;
     }

    fin.close();
   }
}


void StdCol::PrintCollections()
{
 for(int i = 0; i < StCol.size(); i++)
  {
   cout << "Student/Person: " << i + 1 << endl
        << "-------------------------" << endl;
   StCol[i].PrintAStudentProf();
   cout << endl << endl;
  }
}
