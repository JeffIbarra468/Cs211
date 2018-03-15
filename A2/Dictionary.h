/*
  Jeff Ibarra
  03/15/16
  Cs 211
  A2

  Purpose: Dictionary that adds, deletes, prints, and spellchecks from file
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;


/*
  Date: 03/15/16
  Purpose: Class of Dictionary
*/
class Dictionary
{
        private:
                const   int maxWordsInDict;
                const   int maxWordsPerFile;
                        int totalWordsInDict;
                        int numOfWordsInFile[26];
                static  bool failure;
                static  bool success;

        public:
                Dictionary();
                Dictionary(int dictMaxWords, int fileMaxWords);
                bool AddAWord(string word);
                bool DeleteAWord(string word);
                bool SearchForWord(string word);
                bool PrintAFileInDict(string filename);
                bool SpellChecking(string fileName);
                bool InsertWordsIntoDict(string fileName);
                void ProcessTransactionFile();
                bool valid(string word);
                bool putValidWdIntoDic(string word);
                string toLower(string word);
};

#endif
