#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Studentas.h"
using namespace std;

class Fakultetas
{
  public:
    static  const int CMax = 100;
  private:
    Studentas St[CMax]; 
    int n;         
  public:
     Fakultetas(): n(0) {}
     int Kiek() { return n; }
     Studentas Imti(int i)   { return St[i];}
     void  Deti(Studentas p) { if (n < CMax) St[n++] = p; }
};

