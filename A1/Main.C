/*
  Jeff Ibarra
  02/16/16
  ibarr021@cougars.csusm.edu
  Cs 211
  A1
  Program that ciphers and deciphers files through rot and cyptogram method
*/


#include"JeffIbarra_A1.h"


/*
  Purpose: Driver Program
  Date: 02/28/16
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

