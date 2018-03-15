#ifndef TENURETRACKPROF
#define TENURETRACKPROF

#include"CompSciProf.h"


class TenureTrackProf: public CompSciProf
{
 protected:
  char rank; // 'A' Assistant, 'S' Associate, 'F' Full 
  int YearOfExp;
 public:
  TenureTrackProf(){rank = '?'; YearOfExp = 0;}
  TenureTrackProf(string Name, string Email, long FacId, char Rank,
    int YrOfExp):CompSciProf(Name, Email, FacId)
   {rank = Rank; YearOfExp = YrOfExp;}
  void print() const;
  float findSalary() const;
};


#endif
