#include<iostream>
using namespace std;

int Fib(int);
bool FibChk(int);

int main()
{
 int num;

 cout << "This will test to see if a number is a fibonacci number" << endl
      << "Enter a number(negative number to quit): ";
  cin >> num;

 while(num >= 0)
  {
   if(FibChk(num))
     cout << "Yes, " << num << " is a fibobacci number" << endl;
   else
     cout << "No, " << num << " is not a fibonacci number" << endl;

   cout << "Enter a number(negative number to quit): ";
   cin >> num;
  }

 cout << "You have exited, Thank You" << endl;

 return 0;
}


bool FibChk(int num)
{
 int pos = 0;
 int fib = 0;

 while(fib < num)
  {
   fib = Fib(pos);

   if(fib == num)
     return true;
   else if(fib > num)
     return false;
   else if(fib < num)
     pos++;
  }
}


int Fib(int n)
{
 if(n == 0)
   return 0;
 else if(n == 1)
   return 1;
 else
   return Fib(n - 1)+ Fib(n - 2);
}
