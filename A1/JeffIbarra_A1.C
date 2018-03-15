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
  Purpose: Places string from file into vector
  Date: 02/16/16
  Local Var.: word - Each word from file
*/
void Security::placeOrigIntoVec()
{
 ifstream fin;
 fin.open("TEST.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    string word;

    while(fin >> word)
     OriginalDataVec.push_back(word); // Puts word(s) into vector 
   }
}


/*
  Purpose: To change any uppercase to lowercase
  Date: 02/16/16
  Parameters: word - word(s) from vector
  Local Var.: lowerNum - Lowers upper to lowercase
*/
string Security::toLower(string word)
{
 int lowerNum = 32;

 for(int i = 0; i < word.size(); i++)
  {
   if(word[i] >= 'A' && word[i] <= 'Z') // Check if in bound
     word[i] = word[i] + lowerNum;
  }

 return word; // Return lowercase variant
}


/*
  Purpose: Encrypts vector using rot
  Date: 02/16/16
  Parameters: RotNo - Rotational Num
  Local Variables: word - From vector
                   EncWord - New Encrypted word
*/
void Security::EncrypUsingRot(int RotNo)
{
 for(int i = 0; i < OriginalDataVec.size(); i++)
  {
   string word = OriginalDataVec[i];
   string EncWord = EncAWordUsingRot(word, RotNo);
   EncUsingRotVec.push_back(EncWord);
  }
}


/*
  Purpose: Rot function
  Date: 02/16/16
  Parameters: word - word from vector
              RotNo - Rotational Num
  Local Var.: Alphabet - number of letter in alphabet
              EncWord - Encrypted word
              newChar - Encrypted character
*/
string Security::EncAWordUsingRot(string word, int RotNo)
{
 int Alphabet = 26;
 RotNo = RotNo % Alphabet;
 word = toLower(word);
 string EncWord = word;
 int newChar;

 for(int i = 0; i < word.size(); i++)
  {
   if(word[i] >= 'a' && word[i] <= 'z')
    {
     newChar = EncWord[i];

     newChar = int(word[i]) + RotNo;

     if(newChar > 'z')
       newChar -= Alphabet;

     EncWord[i] = char(newChar);
    }
  }

 return EncWord;
}


/*
  Purpose: Places encrpted vector to new file
  Date: 02/16/16
  Local Var.: fout - command to cout variable into file
*/
void Security::placeEncrypUsingRotIntoFile()
{
 ofstream fout;

 fout.open("EncryptRot.txt"); // Opens file

 if(fout.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    for(int i = 0; i < EncUsingRotVec.size(); i++) // Length of vector
      fout << EncUsingRotVec[i] << " "; // Puts vector into file
    fout << endl;
   }
}


/*
  Purpose: Decrypt vector using rot
  Date: 02/24/16
  Parameter: RotNo - Rotational Num
  Local Var.: Encword - Encrypted word from vector
              DecWord - Decrypted word from vector
*/
void Security::DecrypUsingRot(int RotNo)
{
 for(int i = 0; i < EncUsingRotVec.size(); i++)
  {
   string EncWord = EncUsingRotVec[i];
   string DecWord = DecAWordUsingRot(EncWord, RotNo); 
   DecryptUsingRotVec.push_back(DecWord);
  }
}


/*
  Purpose: Decrypts each word using Rot
  Date: 02/24/16
  Parameters: word - word fro vector
              RotNo - Rotational Num
  Local Var.: Alphabet - number of letter in alphabet
              EncWord - Encrypted word
              DecWord - Decrypted word
              newChar - Encrypted character
*/
string Security::DecAWordUsingRot(string EncWord, int RotNo)
{
 int Alphabet = 26;
 RotNo = RotNo % Alphabet;
 string word = EncWord;  // Reassign EncWord to word for same function
 EncWord = toLower(word);
 string DecWord = EncWord;
 int newChar;

 for(int i = 0; i < EncWord.size(); i++)
  {
   if(word[i] >= 'a' && word[i] <= 'z')
    {
     newChar = DecWord[i];

     newChar = int(DecWord[i]) - RotNo;

     if(newChar < 'a')
       newChar += Alphabet;

     DecWord[i] = char(newChar);
    }
  }

 return DecWord;
}


/*
  Purpose: Place decrypted vector into file
  Date: 02/24/16
  Local Var.: fout - open file to output
*/
void Security::placeDecUsingRotIntoFile()
{
 ofstream fout;

 fout.open("DecryptRot.txt"); // Opens file

 if(fout.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    for(int i = 0; i < DecryptUsingRotVec.size(); i++) // Length of vector
      fout << DecryptUsingRotVec[i] << " "; // Puts vector into file
    fout << endl;
   }
}


/*
  Purpose: Encrypt vector
  Date: 02/28/16
  Local Var.: word - string from vector
              EncWord - Encrypted word
*/
void Security::EncryptUsingCrypto()
{
 for(int i = 0; i < OriginalDataVec.size(); i++)
  {
   string word = OriginalDataVec[i];
   string EncWord = EncAWordUsingCrypto(word);
   EncUsingCryptoVec.push_back(EncWord);
  }   
}


/* ERROR ERROR
  Purpose: Encrypts a word by Cryptogram
  Date: 02/28/16
  Parameter: word - string from vector
*/
string Security::EncAWordUsingCrypto(string word)
{
/*
 word = toLower(word);
 string EncWord = word;

  for(int i = 0; i < word.size(); i++)
   {
    if(word[i] >= 'a' && word[i] <= 'z')
     {
      for(int i = 0; i < Key.size(); i++)
       {
        char ch = word[i];
        int index = int(word[i]) - 'a';
        EncWord.find(ch, index);
        EncWord[i] = char(Key[index]);
       }
     }

    cout << "Wd " << word << endl;
    cout << "EncWd " << EncWord << endl;
   }

 return EncWord;
*/
}


/*
  Purpose: Puts Cryptogram into vector
  Date: 02/28/16
  Local Var.: fin - inputs from file
              word - use to fill cryptogram 
*/
void Security::CryptoKey()
{
 ifstream fin;

 fin.open("CryptoKey.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    string word;

    while(fin >> word)
     Key.push_back(word); // Puts cryptogram into vector
   }
}


/*
  Purpose: Puts Encrypt vector into file
  Date: 02/28/16
  Local Var.: fout - outputs to file
*/
void Security::placeEncryptUsingCryptoIntoFile()
{
 ofstream fout;

 fout.open("EncryptCrypto.txt"); // Opens file

 if(fout.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    for(int i = 0; i < EncUsingCryptoVec.size(); i++) // Length of vector
      fout << EncUsingCryptoVec[i] << " "; // Puts vector into file
    fout << endl; 
   }
}


void Security::DecryptUsingCrypto()
{
 cout << "DecryptUsingCrypto() NOT FINISHED" << endl;
}


/*
  Purpose: Puts DecCrypt vector into file
  Date: 02/28/16
  Local Var.: fout - outputs to file
*/
void Security::placeDecryptUsingCryptoIntoFile()
{
 ofstream fout;

 fout.open("DecryptCrypto.txt"); // Opens file

 if(fout.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    for(int i = 0; i < DecUsingCryptoVec.size(); i++) // Length of vector
      fout << DecUsingCryptoVec[i] << " "; // Puts vector into file
    fout << endl;
   }
}
