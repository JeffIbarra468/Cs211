/*
  Jeff Ibarra
  03/15/16
  Cs 211
  A2

  Purpose: Dictionary that adds, deletes, prints, and spellchecks from file
*/

#include"Dictionary.h"


bool Dictionary::failure = false;
bool Dictionary::success = true;


/*
  Date: 03/15/16
  Purpose: Default Constructor
  Local Var: totalWordsInDict - # of words in dictionary
*/
Dictionary::Dictionary(): maxWordsInDict(10000), maxWordsPerFile(100)
{
 totalWordsInDict = 0;

 for(int i = 0; i < 26; i++)
   numOfWordsInFile[i] = 0;
}


/*
  Date: 03/15/16
  Purpose: Constructor with variables
  Locak Var: totalWordsInDict - # of words in dictionary
*/
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):
  maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
 totalWordsInDict = 0;

 for(int i = 0; i < 26; i++)
   numOfWordsInFile[i] = 0;
}


/*
  Date: 03/15/16
  Purpose: Checks if the word doesn't have Latin characters
  Parameter: word - from transaction file
*/
bool Dictionary::valid(string word)
{
 word = toLower(word);

 for(int i = 0; i < word.size(); i++)
   if((word[i] < 'a')||(word[i] > 'z'))
     return failure;

 return success;
}


/*
  Date: 03/15/16
  Purpose: Puts a valid word into "dictionary" file
  Parameter: word - word from transaction file
  Local Var: fileName - name of file to be replaced
             ch - first letter of word
             fout - outputs to file
*/
bool Dictionary::putValidWdIntoDic(string word)
{
 // NOTE: At this stage we already know that the word getting
 // passed to function is valid and not in the dictionary

 word = toLower(word);
 string fileName = "?.txt";
 ofstream fout;
 char ch = word[0];
 fileName[0] = ch;
 int check = ch - 'a';  // Char - 'a' will be between 0 to 26

  if(numOfWordsInFile[check] >= maxWordsPerFile) // # of words in file shouldn't exceed max
    return failure;

 fout.open(fileName.data(), ios::app);
  fout << word << endl;

 numOfWordsInFile[check]++;

 return success; 
}


/*
  Date: 03/15/16
  Purpose: Adds a word from file calling other functions for job
  Parameter: word - word from transaction file
*/
bool Dictionary::AddAWord(string word)
{
 if(totalWordsInDict >= maxWordsInDict) // number of words shouldn't exceed max
    return failure;

 if(!valid(word))
  {
   cout << "Word: " << word << " is not valid" << endl;
   return failure;
  }

 if(SearchForWord(word) != failure)
  {
   //cout << "Word: " << word << " is already in dictionary" << endl;
   return failure;
  }

 putValidWdIntoDic(word);

 totalWordsInDict++;

 return success;
}


/*
  Date: 03/28/16
  Purpose: Deletes a word from a "dictionary" file
  Parameters: word - word from transaction file
  Local Var: fileName - i.e) a.txt,..,z.txt
             Holder - vector for file
             Holdwd - particular word from Holder vector
*/
bool Dictionary::DeleteAWord(string word)
{
 if(SearchForWord(word) == success)
  {
   word = toLower(word);
   string fileName = "?.txt";
   ifstream fin;
   char ch = word[0];
   fileName[0] = ch;
   int check = ch - 'a';  // Char - 'a' will be between 0 to 26

   fin.open(fileName.data());

   if(fin.fail())  //File checker
     {
      cout << "\nFile not created or failed to open " << endl
           << "Word " << word << " also isn't in file " << endl;

      return failure;
     }
   else
     {
      vector<string>Holder; // Holds words from file
      string Holdwd;

      fin >> Holdwd;

      while(fin)
       {
        Holder.push_back(Holdwd); // inputs all words from file to vector
        fin >> Holdwd; // loop
       }

      fin.close();

      for(int i = 0; i < Holder.size(); i++)
       {
        if(Holder[i] == word)
          Holder.erase(Holder.begin()+i); // Erases word from vector
       }

      ofstream fout; // opening file
      fout.open(fileName.data());

      for(int i = 0; i < Holder.size(); i++) // Replacing vector without delete word
        fout << Holder[i] << endl;

      fout.close();

      numOfWordsInFile[check]--;
      totalWordsInDict--;

      return success;
     }
  }

 return failure;
}


/*
  Purpose: To change any uppercase to lowercase
  Date: 03/15/16
  Parameters: word - word(s) from transaction file
  Local Var.: lowerNum - Lowers upper to lowercase
*/
string Dictionary::toLower(string word)
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
  Date: 03/15/16
  Purpose: To search for word in "dictionary" file
  Local Var: fileName - name of file
             ch - characater for first letter of word
             wd - word from file 
  Parameter: word - word passed originally getting checked
*/
bool Dictionary::SearchForWord(string word)
{
 word = toLower(word);
 string fileName = "?.txt";
 ifstream fin;
 char ch = word[0];
 fileName[0] = ch;
 
 fin.open(fileName.data());

 if(fin.fail())  //File checker
   {
    //cout << "File failed to open or doesn't exist, "
    //     << "if not exist file will be created" << endl;
    return failure;
   }
  else
   {
    string wd;

    while(fin >> wd)
      if(word == wd)
        return success;

    return failure;
   }
}


/*
  Date: 03/28/16
  Purpose: Prints from file ?.txt
  Parameter: fileName - ?.txt
  Local Var: SPACE - width of string
             fileWd - word from file
             Lim - limit of words per line
*/
bool Dictionary::PrintAFileInDict(string fileName)
{
 const int SPACE = 15;
 ifstream fin;
 string fileWd;

 fin.open(fileName.data());

 if(fin.fail())  //File checker
   {
    cout << "File failed to open" << endl;
    return failure;
   }
 else
   {
    int Lim = 0;

    fin >> fileWd;

    while(!fin.eof())  // input until end of file
     {
      if(Lim == 5) // Limit at 5 words per line
       {
        cout << endl;
        Lim = 0;  // Makes it loop back
       }

      cout << left << setw(SPACE) << fileWd << "\t";

      fin >> fileWd;

      Lim++; // Increments limit
     }

    cout << endl;
   }

 fin.close();

 return success;
}


/*
  Date: 03/28/16
  Purpose: Spell checks the file
  Parameters: fileName - name for file that is getting checked
  Local Var: FileWd - word that comes from file, i.e) a.txt
*/
bool Dictionary::SpellChecking(string fileName)
{

 ifstream fin;

 fin.open(fileName.data());

  if(fin.fail())  //File checker
   {
    cout << "File failed to be opened" << endl;
    return failure;
   }
  else
   {
    string FileWd;

    while(fin >> FileWd) // Continues as long as there is a word in file
     {
      if(!SearchForWord(FileWd))
        cout << "Misspelled word: " << FileWd << endl;
     }
   }

  fin.close();

 return success;
}


/*
  Date: 03/28/16
  Purpose: Insert all words into respective dictionary files
  Parameter: fileName - ?.txt files
  Local Var: fileWd - word that will be input to file
*/
bool Dictionary::InsertWordsIntoDict(string fileName)
{
 ifstream fin;
 string fileWd;

 fin >> fileWd;

 if(SearchForWord(fileWd))
  return failure; // If it finds word it should return failure
 else
  {
   fin.open(fileName.data());

   if(fin.fail())  //File checker
    {
     cout << "File failed to be opened" << endl;
     return failure;
    }
   else
    {
     while(fin >> fileWd) // inputs all words from file
       AddAWord(fileWd);
    }
  }

  fin.close(); 

 return success;
}


/*
  Date: 03/28/16
  Purpose: Interface of the computer program
  Local Var: cmd - command for functions
             parameter - variable that gets passed as parameter
             MAX_LET - comestic purposes
*/
void Dictionary::ProcessTransactionFile()
{
 string cmd;
 string parameter;
 ifstream fin;
 string fileName;  // FileName for transactionaction file
 const int MAX_LET = 15;  // Limit of max letters for cout

 cout << "Enter a transaction file: ";
  cin >> fileName;                       // Enters filename
 cout << endl;

 fin.open(fileName.data());

  if(fin.fail())  //File checker
   {
    cout << "File failed to be opened" << endl;
   }
  else
   {
    cout << setw(MAX_LET);

    while(!fin.eof())  // As long as there is something in file it will cont to fin
     {
      fin >> cmd;       // Gets command from file
      fin >> parameter; // Gets parameter from file

      if(cmd == "AddW")
       {
        cout << "------------------- AddW " << parameter << " -----------" << endl;

        if(AddAWord(parameter)) // Calls & prints which words get added or not
                                // Returns success
         cout << "Word " << parameter << " got added" << endl;
        else                    // Returns failure
         cout << "Word " << parameter << " didn't get added" << endl;

       }
      else if(cmd == "DeleteW")
       {
        cout << "---------------- DeleteW " << parameter << " ------------" << endl;

        if(DeleteAWord(parameter))  // Calls & prints words that get deleted or not
                                    // Returns success
          cout << "Word " << parameter << " got deleted" << endl;
        else                       // Returns failure
          cout << "Word " << parameter << " didn't get deleted" << endl;

       }
      else if(cmd == "SearchW")
       {
        cout << "---------------- SearchW " << parameter << " ------------" << endl;

        if(SearchForWord(parameter)) // Calls & prints which words exists or not
                                     // Returns success
          cout << "Word " << parameter << " exists" << endl;
        else                         // return failure
          cout << "Word " << parameter << " doesn't exist" << endl;

       }
      else if(cmd == "PrintF")
       {
        cout << "----------------- PrintF " << parameter << " ------------" << endl;
        PrintAFileInDict(parameter);
       }
      else if(cmd == "SpellCheck")
       {
        cout << "------------- SpellCheck " << parameter << " ------------" << endl;
        SpellChecking(parameter);
       }
      else if(cmd == "InsertF")
       {
        cout << "---------------- InsertF " << parameter << " ------------" << endl;
        InsertWordsIntoDict(parameter);
       }
      else
        cout << "Invalid Input" << endl; // cmd not equal any of these inputs
     }

    fin >> cmd;         // Next command from file
    fin >> parameter;   // Next parameter from file
   }

 fin.close();
}
