#include "StdAfx.h"
#include "Mokslininkai.h"
using namespace std;

  Mokslininkai::Mokslininkai(string kodasR, string vardasR, string pavardeR, double indR[]) : 
    kodas(kodasR), vardas(vardasR), pavarde(pavardeR), S(0)
    {
   	  for (int i = 0; i < Cpremijos; i++){
		ind[i] = indR[i];
		pin[i] = 0;
	  }
    }
  string Mokslininkai::Spausdinti()
    {
	  stringstream ss;
	  ss << left << setw(15) << kodas << setw(15) << vardas << setw(15) << pavarde;
	  for (int i = 0; i < Cpremijos; i++)
		  ss << right << setw(4) << ind[i];
	  return ss.str(); 
    }
  string Mokslininkai::SpausdintiPapildomai()
  {
	  stringstream ss;
	  ss << left << setw(15) << kodas << setw(15) << vardas << setw(15) << pavarde;
	  for (int i = 0; i < Cpremijos; i++)
		  ss << right << setw(4) << ind[i];
	  for (int i = 0; i < Cpremijos; i++)
		  ss <<' '<< right << setw(6) << ((int)pin[i]);
	  ss << right << setw(10) << ((int)S);
	  return ss.str();
  }
  //----------------------------------
  double Mokslininkai::ImtiS() { return S; }
  //----------------------------------
  double Mokslininkai::ImtiIndelius(int i)
  {
	  return ind[i];
  }
  //----------------------------------
  void Mokslininkai::ApskaiciuotiS(){
	  for (int i = 0; i < Cpremijos; i++)
		  S+= pin[i];
  }
  //----------------------------------
  void Mokslininkai::DetiUzdirbius(double a, int b)
  { 
	  pin[b] = a;
  }
  //------------------------------------
  bool Mokslininkai::operator > (const Mokslininkai & C)
	{
	  return pavarde < C.pavarde || ((pavarde == C.pavarde) && (vardas < C.vardas));
    }