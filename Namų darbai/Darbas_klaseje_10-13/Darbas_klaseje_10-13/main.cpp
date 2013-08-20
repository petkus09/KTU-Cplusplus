#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Mgrybai
{
private:
	string pavadinimas;
	double mase;
public:
	Mgrybai () : pavadinimas(""), mase(0) { }
	Mgrybai(string pavadinimas, double mase): pavadinimas(pavadinimas), mase(mase) { }
	string ImtiPavadinima() {return pavadinimas;}
	string ImtiMase() {return mase;}
	string spausdinti()
};
//-------------------------------------------------------
string Mgrybai::spausdinti()
{
	stringstream srautas;
	srautas << left << setw(20) << pavadinimas << right << setw(5) << mase;
	return srautas.str();
}
//-------------------------------------------------------

class Igrybai
{
private:
	string pavadinimas;
	string tipas;
public:
	Igrybai () : pavadinimas (""), tipas("") { }
	Igrybai(string pavadinimas, string tipas): pavadinimas(pavadinimas), tipas(tipas) { }
	string ImtiPavadinima() {return pavadinimas;}
	string ImtiTipa() {return tipas;}
	string spausdinti();
};
//----------------------------------------------------------------
string Igrybai::spausdinti()
{
	stringstream srautas;
	srautas << left << setw(20) << pavadinimas << tipas;
	return srautas.str();
}
//-----------------------------------------------------------------
const char u1[]="U1.txt";
const char u2[]="U2.txt";
const int MaxKiek = 100;
void IvestiInterneta(Igrybai grybai[], int & n);
void IvestiMiska(Mgrybai gr[], int & n);
void IvestiInterneta(Igrybai grybai[], int n);
void IsvestiMiska(Mgrybai gr[], int n, string tipas);
void Atrin