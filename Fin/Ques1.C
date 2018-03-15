#include<iostream>
#include<string>
using namespace std;


class Professor
{
 protected:
  long id;
  string name;
  int age;
  float salary;
 public:
  Professor();
};


class TenureTrackFaculty: public Professor
{
 protected:
  string rank;
  int yearOfExperience;
 public:
  void FindTenureSalary();
};


class AdjunctProfessor: public Professor
{
 protected:
  int numOfCourses;
 public:
  void FindAdjunctSalary();
};

void TenureTrackFaculty::FindTenureSalary()
{
 if(rank == "AssistantProf")
  salary = 50000.00;
 else if(rank == "AssociatedProf")
  salary = 60000.00;
 else
  salary = 60000.00 + (2 * yearOfExperience);
}

void AdjunctProfessor::FindAdjunctSalary()
{
 salary = numOfCourses * 3500.00;
}
