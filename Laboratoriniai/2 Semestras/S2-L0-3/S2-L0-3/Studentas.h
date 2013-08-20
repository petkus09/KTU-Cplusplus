#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Studentas
{
public:
 static const int Cpaz=10;
private:
    string pavarde, vardas, grupe;
    int np, paz[Cpaz];
public:
    Studentas():np(0), pavarde(""), vardas(""), grupe("")
	{ }
    Studentas(string pav, string vard, string grup, int np, int pz[]);
    bool operator ! ();
    string Spausdinti();
};
bool Studentas::operator ! ()
{
        for (int i=0; i<np; i++)
          if(paz[i] < 9)
	return true;
        return false;
}
Studentas::Studentas(string pav, string vard, string grup, int np, int pz[]):
        pavarde(pav), vardas(vard), grupe(grup), np(np) 
{
	   for (int i=0; i<np; i++)
  	    paz[i] = pz[i];
}
string Studentas::Spausdinti()
{
       stringstream eil;
       eil << left << setw(12) << pavarde << setw(10) << vardas
		   << setw(8) << grupe << right;
	   for (int i=0; i<np; i++)
	    eil << setw(3) << paz[i];
	   eil<< endl;
      return eil.str();
}
