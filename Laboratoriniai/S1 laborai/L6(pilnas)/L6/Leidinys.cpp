#include "Leidinys.h"
#include <string>

string Leidinys::ImtiPavarde() {return pavarde; }
string Leidinys::ImtiAdresa()  {return adresas; }
string Leidinys::ImtiKoda()    {return kodas; }
int Leidinys::ImtiPradzia()    {return pradzia; }
int Leidinys::ImtiIlgi()       {return ilgis; }
int Leidinys::ImtiKieki()      {return kiekis; }
void Leidinys::DetiPavarde(string a) {pavarde = a; }
void Leidinys::DetiAdresa(string a)  {adresas = a; }
void Leidinys::DetiKoda(string a)    {kodas = a; }
void Leidinys::DetiPradzia(int a)    {pradzia = a; }
void Leidinys::DetiIlgi(int a)       {ilgis = a; }
void Leidinys::DetiKieki(int a)      {kiekis = a; }
bool Leidinys::operator <(const Leidinys & R)
{
  return (adresas < R.adresas || (adresas == R.adresas && pavarde < R.pavarde));
}
