/*
  Jeff Ibarra
  02/16/16
  ibarr021@cougars.csusm.edu
  Cs 211
  A1
  Program that ciphers and deciphers files through rot and cyptogram method
*/


#ifndef JEFFIBARRA_A1_H
#define JEFFIBARRA_A1_H


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


/*
  Purpose: Class for program
  Date: 02/16/16
  Local Var.: OriginalDataVec - original string from file
              EncUsingRotVec - Encrypted vector
              DecryptUsingRotVec - Decyprted vector
*/
class Security
{
 private:
  vector <string> OriginalDataVec;
  vector <string> EncUsingRotVec;
  vector <string> DecryptUsingRotVec;
  vector <string> EncUsingCryptoVec;
  vector <string> DecUsingCryptoVec;
  vector <string> Key;

 public:
  Security(){};
  void placeOrigIntoVec();
  void EncrypUsingRot(int RotNo);
  string EncAWordUsingRot(string word, int RotNo);
  void placeEncrypUsingRotIntoFile();
  string toLower(string word);
  void DecrypUsingRot(int RotNo);
  string DecAWordUsingRot(string word, int RotNo);
  void placeDecUsingRotIntoFile();
  void EncryptUsingCrypto();
  string EncAWordUsingCrypto(string word);
  void placeEncryptUsingCryptoIntoFile();
  void DecryptUsingCrypto();
  void placeDecryptUsingCryptoIntoFile();
  void CryptoKey();
};


#endif
