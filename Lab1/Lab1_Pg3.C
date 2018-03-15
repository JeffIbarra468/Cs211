#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

const int SIZE = 10;
void ReadFile(int[]);
void copyRev(const int[], int[]);
void print(const int[], const int[]);
int findInBetwn(const int[]);
int CountDivByFive(const int[]);
int printDivByFive(const int[]);
double findMean(const int[]);
int findMin(const int[], int);
bool searchKey(const int[], int);

int main()
{
 int Arr[SIZE];
 int RevArr[SIZE];
 int Min = 9999999;
 int key;

 ReadFile(Arr);
 copyRev(Arr, RevArr);
 print(Arr, RevArr);

 cout << "Index between 80 to 100: " << findInBetwn(Arr) << endl;
 cout << "Index divisble by 5: " << CountDivByFive(Arr) << endl;

 printDivByFive(Arr);
 
 cout << fixed << setprecision(1) << "Avg = " << findMean(Arr) << endl;

 cout << "Min num of array: " << findMin(Arr, Min) << endl;

 cout << "Enter key to search in array: ";
  cin >> key;

 cout << "If found 1 shall show up if not 0: " 
      << searchKey(Arr, key) << endl;
  
 return 0;
}


void ReadFile(int Arr[])
{
 ifstream fin;
 fin.open("Lab1.3_data.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    for(int i = 0; i < SIZE; i++)
      fin >> Arr[i];
   }
}


void copyRev(const int Arr[], int RevArr[])
{
 for(int i = 0, j = SIZE - 1; i < SIZE, j >=  0; i++, j--)
   RevArr[j] = Arr[i];
}

void print(const int Arr[], const int RevArr[])
{
 cout << "Arr A: ";
 for(int i = 0; i < SIZE; i++)
   cout << Arr[i] << " ";
 cout << endl;

 cout << "Arr B: ";
 for(int i = 0; i < SIZE; i++)
   cout << RevArr[i] << " ";
 cout << endl;
}


int findInBetwn(const int Arr[])
{
 int count = 0;

 for(int i = 0; i < SIZE; i++)
  {
   if(Arr[i] >= 80 && Arr[i] <= 100)
     count++;
  }

 return count;
}


int CountDivByFive(const int Arr[])
{
 int DivCount = 0;

 for(int i = 0; i < SIZE; i++)
  {
   if(Arr[i] % 5 == 0)
     DivCount++;
  }

 return DivCount;
}


int printDivByFive(const int Arr[])
{
 cout << "Num divisble by 5: ";

 for(int i = 0; i < SIZE; i++)
  {
   if(Arr[i] % 5 == 0)
     cout << Arr[i] << " ";
  }
 cout << endl;
}


double findMean(const int Arr[])
{
 int sum = 0;
 double Avg;

 for(int i = 0; i < SIZE; i++)
   sum += Arr[i];

 Avg = sum/10.0;

 return Avg;
}


int findMin(const int Arr[], int Min)
{
 for(int i = 0; i < SIZE; i++)
  {
   if(Arr[i] < Min)
    Min = Arr[i];
  }

 return Min;
}


bool searchKey(const int Arr[], int key)
{
 for(int i = 0; i < SIZE; i++)
  {
   if(Arr[i] == key)
    return true;
  }

 return false;
}
