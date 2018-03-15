#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include"StudentProfile.h"
#include<vector>


class StdCol
{
 private:
  vector<StudentProf> StCol;
 public:
  void GetInfo();
  void PrintCollections();
};

#endif
