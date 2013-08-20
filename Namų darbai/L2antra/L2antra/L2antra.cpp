#include <iostream>
using namespace std;
#include <string>
#include <fstream>

//--------------------------------------------------------------------
class Laikrastis
{
private:
	int kaina;
	string pav;
	int kiekis;
public:
	Laikrastis () {}
	~Laikrastis () {}
	Laikrastis(string pavReiksme, int kainaReiksme, int kiekisReiksme);
	string ImtiPav();
	int ImtiKaina();
	int ImtiKieki();
	string DetiPav(string a);
	int DetiKaina(int a);
	int DetiKieki(int a);
};
//--------------------------------------------------------------------
class Pirkejas
{
private:
	string pavarde, vardas, pavadinimas;
	int pinigai;
public:
	Pirkejas () {}
	~Pirkejas () {}
	Pirkejas(string pavardeReiksme, string vardasReiksme, string pavadinimasReiksme, int pinigaiReiksme);
	string ImtiPavarde();
	string ImtiVarda();
	string ImtiPavadinima();
	int ImtiPinigus();
	string DetiPavarde(string a);
	string DetiVarda(string a);
    string DetiPavadinima(string a);
	int DetiPinigus(int a);
};
void Nuskaitymas(Laikrastis L[], Pirkejas P[]);
//====================================================================
int main()
{
   Laikrastis L[2];
   Pirkejas P[1];
   Nuskaitymas(Laikrastis L, Pirkejas P);
   
   return 0;
}
duom.close();
rez.close();
//================================================================
Laikrastis::Laikrastis(string pavReiksme, int kainaReiksme, int kiekisReiksme) : pav(pavReiksme), kaina(kainaReiksme), kiekis(kiekisReiksme)
	  {}
//------------------------------------------------------------
string Laikrastis::ImtiPav()
{
	return pav;
}
//------------------------------------------------------------------
int Laikrastis::ImtiKaina()
{
	return kaina;
}
//------------------------------------------------------------------
int Laikrastis::ImtiKieki()
{
	return kiekis;
}
//---------------------------------------------------------------------
int Laikrastis::DetiKieki(int a)
{
    kiekis = a;
}
//---------------------------------------------------------------------
string Laikrastis::DetiPav(string a)
{
	pav = a;
}
//---------------------------------------------------------------------
int Laikrastis::DetiKaina(int a);
{
	Kaina = a;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pirkejas::Pirkejas(string pavardeReiksme, string vardasReiksme, string PavadinimasReiksme, int pinigaiReiksme) : 
  pavarde(pavardeReiksme), vardas(vardasReiksme), pavadinimas(PavadinimasReiksme), pinigai(pinigaiReiksme)
  {}
//---------------------------------------------------------------------------
  string Pirkejas::ImtiPavarde()
  {
	  return pavarde;
  }
//---------------------------------------------------------------------------
string Pirkejas::ImtiVarda()
  {
	  return vardas;
  }
//---------------------------------------------------------------------------
string Pirkejas::ImtiPavadinima()
  {
	  return pavadinimas;
  }
//---------------------------------------------------------------------------
string Pirkejas::ImtiKieki()
  {
	  return kiekis;
  }
//----------------------------------------------------------------------------
int Pirkejas::DetiPinigus(int a)
  {
	  pinigai = a;
  }
//----------------------------------------------------------------------------
string DetiPavarde(string a)
{
	pavarde = a;
}
//----------------------------------------------------------------------------
string DetiVarda(string a)
{
	vardas = a;
}
//----------------------------------------------------------------------------
string DetiPavadinima(string a)
{
	pavadinimas = a;
}
//---------------------------------------------------------------------------
void Nuskaitymas(Laikrastis L[], Pirkejas P[]);
{
	ifstream duom ("Duomenys.txt");
	string Lpav, Ppavard, Pvard, Plaikrast;
	int Lkaina, Lkiekis, Ppinigai;
	for (i = 0, i <= 2, i++){
		duom >> Lpav, Lkaina, Lkiekis;
		L[i].DetiPav(Lpav);
		L[i].DetiKaina(Lkaina);
		L[i].DetiKieki(Lkiekis);
	}
	for (i = 0, i <= 1, i++){
		duom >> Ppavard, Pvard, Plaikrast, Ppinigai;.
		P[i].DetiPavarde(Ppavard);
	    P[i].DetiVarda(Pvard);
        P[i].DetiPavadinima(Plaikrast);
	    P[i].DetiPinigus(Ppinigai);
	}
}
//=============================================================================


		