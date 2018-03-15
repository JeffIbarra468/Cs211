#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


class Course
{
 public:
  long CourseNum;
  string CourseName;
};


class Student
{
 public:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
};


class Person
{
 public:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender; // (.M. for Male and .F. for Female)
};


class StudentProf
{
 public:
  Person PrsnInfo;
  Student StdInfo;
};


void GetInfo(vector<StudentProf>&);
void PrintInfo(const vector<StudentProf>&);


int main()
{
 vector<StudentProf> StColl;

 GetInfo(StColl);
 PrintInfo(StColl);

 return 0;
}


void GetInfo(vector<StudentProf>& StColl)
{
 StudentProf StuProf;
 ifstream fin;

 fin.open("Lab3_data.txt");

 if(fin.fail())  //File checker
   {
    cout << "\nThe file was not succesfully opened" << endl;
    return;
   }
  else
   {
    while(!fin.eof())
     {
      fin >> StuProf.PrsnInfo.Fname
          >> StuProf.PrsnInfo.Lname
          >> StuProf.PrsnInfo.SSN
          >> StuProf.PrsnInfo.Age
          >> StuProf.PrsnInfo.Gender
          >> StuProf.StdInfo.StNo
          >> StuProf.StdInfo.Course1.CourseName
          >> StuProf.StdInfo.Course1.CourseNum
          >> StuProf.StdInfo.Course2.CourseName
          >> StuProf.StdInfo.Course2.CourseNum
          >> StuProf.StdInfo.Course3.CourseName
          >> StuProf.StdInfo.Course3.CourseNum;

      StColl.push_back(StuProf);
     }

    fin.close();
   }
}


void PrintInfo(const vector<StudentProf>& StColl)
{
 for(int i = 0; i < StColl.size(); i++)
  {
   cout << "\nName: " << StColl[i].PrsnInfo.Fname 
        << " " << StColl[i].PrsnInfo.Lname << endl
        << "SSN: " << StColl[i].PrsnInfo.SSN << endl
        << "Age: " << StColl[i].PrsnInfo.Age << endl
        << "Gender: " << StColl[i].PrsnInfo.Gender << endl
        << "Student ID: " << StColl[i].StdInfo.StNo << endl
        << "CourseName: " << StColl[i].StdInfo.Course1.CourseName << endl
        << "CourseNum: " << StColl[i].StdInfo.Course1.CourseNum << endl
        << "CourseName: " << StColl[i].StdInfo.Course2.CourseName << endl
        << "CourseNum: " << StColl[i].StdInfo.Course2.CourseNum << endl
        << "CourseName: " << StColl[i].StdInfo.Course3.CourseName << endl
        << "CourseNum: " << StColl[i].StdInfo.Course3.CourseNum << endl;
  }
}
