/*
  Jeff Ibarra
  1/26/16
  Cs211
  Lab1 Pg1
*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


void ProcessARow(int A1, int A2, int A3, double& Avg, int& Min, int& Max)
{
 if(A1 > A2)
  Max = A1;
 else
  Max = A2;
 if(Max < A3)
  Max = A3;
 else
  Max = Max;

 if(A1 < A2)
  Min = A1;
 else
  Min = A2;
 if(Min > A3)
  Min = A3;
 else
  Min = Min;

 Avg = (A1 + A2 + A3)/3;
}


int main()
{
  long StuId;
  int A1, A2, A3;
  double Avg;
  int Min, Max;
  int line = 0;

  ifstream fin;
  fin.open("data_lab1.txt");

  if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return -1;
   }
  else
   {
    fin >> StuId >> A1 >> A2 >> A3;

    cout << "Std-Id  A1  A2  A3  Min  Max  Avg" << endl
         << "---------------------------------" << endl;

    while(line < 3)
     { 
      ProcessARow(A1, A2, A3, Avg, Min, Max);

      cout << setw(6) << StuId
           << setw(4) << A1 << setw(4) << A2
           << setw(4) << A3 << setw(5) << Min << setw(5) << Max;
      cout << fixed << setprecision(1) << setw(5) << Avg << endl;

      fin >> StuId >> A1 >> A2 >> A3;
      line++;
     }
   }

  fin.close();
  
  return 0;
}
