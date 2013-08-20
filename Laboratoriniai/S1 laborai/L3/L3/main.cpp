#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

//--------------------------------------------------------------
const string Cduom = "U2.txt";
const int CmaxVaikas = 20;
const int CmaxSkaiciuote = 50;
//--------------------------------------------------------------
class Vaikas
{
private:
	string pavarde;
	string vardas;
	bool iskritimas;        //Nurodys, ar vaikas jau iskrites is skaiciuotes ar ne
public:
	Vaikas();
	Vaikas(string pavardeReiksme, string vardasReiksme, bool iskritimasReiksme);
	~Vaikas();
	string ImtiPavarde();
    string ImtiVarda();
	bool ImtiIskritima();
	void DetiIskritima(bool a);
};
//--------------------------------------------------------------
void Nuskaitymas(string failoVardas, Vaikas V[], int & Svaikas, int & Sskaiciuote, int VaikasMax, int SkaiciuoteMax);
void Skaiciavimas(Vaikas V[], int Svaikas, int Sskaiciuote);
//=============================================================================
int main()
{
	Vaikas V[CmaxVaikas];
	int d = 0, m = 0;
	Nuskaitymas(Cduom, V, d, m, CmaxVaikas, CmaxSkaiciuote);
	Skaiciavimas(V, d, m);
	return 0;
}
//=============================================================================
Vaikas::Vaikas(string pavardeReiksme, string vardasReiksme, bool iskritimasReiksme): pavarde(pavardeReiksme), vardas(vardasReiksme), iskritimas(iskritimasReiksme) { }
Vaikas::Vaikas(): pavarde(), vardas(), iskritimas(0) { }
Vaikas::~Vaikas() { }
//-----------------------------------------------------------------------------
string Vaikas::ImtiPavarde()
{
	return pavarde;
}
//-----------------------------------------------------------------------------
string Vaikas::ImtiVarda()
{
	return vardas;
}
//-----------------------------------------------------------------------------
bool Vaikas::ImtiIskritima()
{
	return iskritimas;
}
//-----------------------------------------------------------------------------
void Vaikas::DetiIskritima(bool a)
{
	iskritimas = a;
}
//-----------------------------------------------------------------------------
void Nuskaitymas(string failoVardas, Vaikas V[], int & Svaikas, int & Sskaiciuote, int VaikasMax, int SkaiciuoteMax)
{
	string pavard, vard;
	ifstream duom(failoVardas.c_str());
	duom >> Svaikas;
	if (Svaikas > VaikasMax)
		Svaikas = VaikasMax;
    duom >> Sskaiciuote;
	if (Sskaiciuote > SkaiciuoteMax)
		Sskaiciuote = SkaiciuoteMax;
	for (int i = 0; i<= Svaikas - 1; i++){
		duom >> pavard;
		getline (duom, vard);
		//vardas nuskaitomas char masyvu ir konvertuojamas i string kintamaji
		V[i] = Vaikas(pavard, vard, 0);       //Galutinis duomenu priskyrimas
	}
	duom.close();
}
//----------------------------------------------------------------------------
void Skaiciavimas(Vaikas V[], int Svaikas, int Sskaiciuote)
{
	srand(time(NULL));
	int s, k;
	bool check;                   //Sis kintamasis bus naudojamas nutraukiant while cikla, kurio metu bus praleidziami iskrite vaikai is rato
	s = rand() % Svaikas; //Sugeneruojamas atsitiktinis vaiko, nuo kurio bus pradedama skaiciuoti numeris
	int u = s;     
	for (int i = 1; i <= Svaikas; i++){
		for (int k = 1; k <= Sskaiciuote; k++){  
			check = 0;
			while (check != 1){
				if (V[u%Svaikas].ImtiIskritima() == 0)
					check = 1;           //Jei Vaikas neiskrites, vaikas yra iskaitomas, einama prie sekancio skaiciuotes zodzio
				else                  //Vaikas yra iskrites, kartojamas ciklas, einama prie sekancio vaiko, zodis tas pats
					u++;
			}
				u++;
		}
		u--; //Kadangi paskutini zodi pavartojus, ciklas pereina prie sekancio vaiko, o mums reikia vaiko, kuris buvo ties paskutiniu zodziu
        V[u%Svaikas].DetiIskritima(1);  //Nurodoma, jog vaikas iskrites
		cout << V[u%Svaikas].ImtiPavarde() << V[u%Svaikas].ImtiVarda() << endl;
	}
}