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
};
void Nuskaitymas(int & pavad, int & LT, int & kiekis);
//====================================================================
int main()
{
   int k1, k2;
   string p1, p2, p3;
   duom >> p1, k1, k2;
   k = 0;
   if (L1.ImtiKaina() != L2.ImtiKaina())
	    k++;
   if (L1.ImtiKaina() != L3.ImtiKaina())
	    k++;
   if (L2.ImtiKaina() != L3.ImtiKaina())
	    k++;
   ofstream rez("Rezultatai.txt");
   rez << "Yra " << k <<" skirtingos kainos" << endl;
   rez.close();
   return 0;
}
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
//---------------------------------------------------------------------------
void NuskaitymasL(string & pavad, int & LT, int & kiekybe)
{
     ifstream duom("Duomenys.txt");
	 duom >> pavad >> LT >> kiekybe;

	 duom.close()
}