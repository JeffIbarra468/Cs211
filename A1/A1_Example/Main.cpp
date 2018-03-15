#include"A1.h"


/*
  Purpose: Driver Program
  Date:
  Local Variables: MainCom - Main menu command
                   CryptCom - Crypting choice command
                   RotNo - Rotation Num
                   RUN - Object to run program
*/
int main()
{
 char MainCom;
 char CryptCom;
 int RotNo;
 Security RUN;

 cout << "Do you want to Encrypt or Decrypt [E/D]: ";
  cin >> MainCom;

 if(MainCom == 'E')
  {
   cout << "By rotation or cryptogram [R/C]: ";
    cin >> CryptCom;

   if(CryptCom == 'R')
    {
     cout << "Choose Rotation Num: ";
      cin >> RotNo;

     RUN.placeOrigIntoVec();
     RUN.EncrypUsingRot(RotNo);
     RUN.placeEncrypUsingRotIntoFile();

    }
   else if(CryptCom == 'C')
    {
     cout << "Crpt Enc NOT FINISHED" << endl;
    }
  }
 else if(MainCom == 'D')
  {
   cout << "By rotation or cryptogram [R/C]: ";
    cin >> CryptCom;

   if(CryptCom == 'R')
    {
     cout << "Choose Rotation Num: ";
      cin >> RotNo;

     RUN.placeOrigIntoVec();
     RUN.EncrypUsingRot(RotNo);
     RUN.placeEncrypUsingRotIntoFile();
     RUN.DecrypUsingRot(RotNo);
     RUN.placeDecUsingRotIntoFile();

    }
   else if(CryptCom == 'C')
    {
     cout << "Crpt Dec NOT FINISHED" << endl;
    }
  }
 else
  cout << "You have exited out of the program." << endl;

 return 0;
}

