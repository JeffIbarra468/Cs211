#ifndef ADJUNCTPROF
#define ADJUNCTPROF

#include"CompSciProf.h"


class AdjunctProf: public CompSciProf
{
 protected:
  char degree; // 'B' Bachelor, 'M' Master, 'P' Ph.D
  int NoOfTA, NoOfCourses;
 public:
  AdjunctProf(){degree = '?'; NoOfTA = 0; NoOfCourses = 0;}
  AdjunctProf(string Name, string Email, long FacId, char Deg, int NumOfTA,
    int NumOfCourses):CompSciProf(Name, Email, FacId)
   {degree = Deg; NoOfTA = NumOfTA; NoOfCourses = NumOfCourses;}
  void print() const;
  float findSalary() const;
};


#endif
