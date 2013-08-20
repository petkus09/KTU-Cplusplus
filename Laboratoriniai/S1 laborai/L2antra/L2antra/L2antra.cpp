#include <iostream>
using namespace std;
#include <string>
#include <fstream>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Laikrastis
{
private:
	double kaina;
	string pav;
	int kiekis;
public:
	Laikrastis () {}
	~Laikrastis () {}
	Laikrastis(string pavReiksme, double kainaReiksme, int kiekisReiksme);
	string ImtiPav();
	double ImtiKaina();
	int ImtiKieki();
	void DetiPav(string a);
	void DetiKaina(double a);
	void DetiKieki(int a);
};
//--------------------------------------------------------------------
class Pirkejas
{
private:
	string pavarde, vardas, pavadinimas;
	double pinigai;
public:
	Pirkejas () {}
	~Pirkejas () {}
	Pirkejas(string pavardeReiksme, string vardasReiksme, string pavadinimasReiksme, double pinigaiReiksme);
	string ImtiPavarde();
	string ImtiVarda();
	string ImtiPavadinima();
	double ImtiPinigus();
	void DetiPavarde(string a);
	void DetiVarda(string a);
    void DetiPavadinima(string a);
	void DetiPinigus(double a);
};
//-----------------------------------------------------------------------
void Nuskaitymas(Laikrastis L[], Pirkejas P[]);
void Skaiciavimai(Laikrastis L[], Pirkejas P[]);
//=======================================================================
int main()
{
   Laikrastis L[3];
   Pirkejas P[2];
   Nuskaitymas(L, P);
   Skaiciavimai(L, P);
   return 0;
}
//=======================================================================
Laikrastis::Laikrastis(string pavReiksme, double kainaReiksme, int kiekisReiksme) : pav(pavReiksme), kaina(kainaReiksme), kiekis(kiekisReiksme)
	  {}
//------------------------------------------------------------
string Laikrastis::ImtiPav()
{
	return pav;
}
//------------------------------------------------------------------
double Laikrastis::ImtiKaina()
{
	return kaina;
}
//------------------------------------------------------------------
int Laikrastis::ImtiKieki()
{
	return kiekis;
}
//---------------------------------------------------------------------
void Laikrastis::DetiKieki(int a)
{
    kiekis = a;
}
//---------------------------------------------------------------------
void Laikrastis::DetiPav(string a)
{
	pav = a;
}
//---------------------------------------------------------------------
void Laikrastis::DetiKaina(double a)
{
  kaina = a;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pirkejas::Pirkejas(string pavardeReiksme, string vardasReiksme, string pavadinimasReiksme, double pinigaiReiksme) : 
  pavarde(pavardeReiksme), vardas(vardasReiksme), pavadinimas(pavadinimasReiksme), pinigai(pinigaiReiksme)
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
double Pirkejas::ImtiPinigus()
  {
	  return pinigai;
  }
//----------------------------------------------------------------------------
void Pirkejas::DetiPinigus(double a)
  {
	  pinigai = a;
  }
//----------------------------------------------------------------------------
void Pirkejas::DetiPavarde(string a)
{
	pavarde = a;
}
//----------------------------------------------------------------------------
void Pirkejas::DetiVarda(string a)
{
	vardas = a;
}
//----------------------------------------------------------------------------
void Pirkejas::DetiPavadinima(string a)
{
	pavadinimas = a;
}
//---------------------------------------------------------------------------
void Nuskaitymas(Laikrastis L[], Pirkejas P[])
{
	ifstream duom("Duomenys.txt");
	string Lpav, Ppavard, Pvard, Plaikrast;
	int Lkiekis= 0;
	double Lkaina =0.0, Ppinigai= 0.0;
	for (int i = 0; i <= 2; i++){
		duom >> Lpav >> Lkaina >> Lkiekis;
		L[i].DetiPav(Lpav);
		L[i].DetiKaina(Lkaina);
		L[i].DetiKieki(Lkiekis);
	}
	for (int i = 0; i <= 1; i++){
		duom >> Ppavard >> Pvard >> Plaikrast >> Ppinigai;
		P[i].DetiPavarde(Ppavard);
	    P[i].DetiVarda(Pvard);
        P[i].DetiPavadinima(Plaikrast);
	    P[i].DetiPinigus(Ppinigai);
	}
	duom.close();
}
//=============================================================================
void Skaiciavimai(Laikrastis L[], Pirkejas P[])
{
	ofstream rez("Rezultatai.txt");
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 2; j++)
			if (P[i].ImtiPavadinima() == L[j].ImtiPav())
				if (P[i].ImtiPinigus() >= L[j].ImtiKaina())
					if (L[j].ImtiKieki() >= 1){
						L[j].DetiKieki(L[j].ImtiKieki() - 1);
						P[i].DetiPinigus(P[i].ImtiPinigus() - L[j].ImtiKaina());
						rez << i + 1 <<"-am pirkejui pasiseks"<< endl;
					}
    rez.close();
}
//----------------------------------------------------------------------------
