#include<iostream>
using namespace std;

int gcd(int, int);

int main()
{
 int x, y;

 cout << "Enter x: ";
  cin >> x;

 cout << "Enter y: ";
  cin >> y; 

 cout << "GCD is " << gcd(x, y) << endl;

 return 0;
}

int gcd(int x, int y)
{
 if(y == 0)
   return x;
 else
   return gcd(y, x % y);
}
