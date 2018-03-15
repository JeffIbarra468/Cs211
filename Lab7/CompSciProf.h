#ifndef COMPSCIPROF
#define COMPSCIPROF

#include<string>
using namespace std;


class CompSciProf
{
 protected:
  string name, email;
  long facultyId;
 public:
  CompSciProf(){name = "?"; email = "?"; facultyId = 0;};
  CompSciProf(string Name, string Email, long FacId)
   {name = Name; email = Email; facultyId = FacId;};
  void print() const;
};


#endif
