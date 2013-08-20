#pragma once
#include <string>
#include <iostream>
#include "Leidinys.h"
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class Agentas
{
private:
	string Akodas, Apavarde, Avardas, Aadresas, telefonas;
	int menesinis[12];
	int Akiekis;
    Leidinys L[256];
public:
	Agentas(string AkodasReiksme = "", string ApavardeReiksme = "", string AvardasReiksme = "", string AadresasReiksme = "", 
		string telefonasReiksme = "",int AkiekisReiksme = 0 )
		: Akodas(AkodasReiksme), Apavarde(ApavardeReiksme), Avardas(AvardasReiksme),
		Aadresas(AadresasReiksme), telefonas(telefonasReiksme), Akiekis(AkiekisReiksme);
	~Agentas();
	//---------------------------
	void DetiLeidini(Leidinys a) {
		L[Akiekis] = a;
		Akiekis++; 
	}
	//-----------------------------
	Leidinys ImtiLeidini(int a) {return L[a]; }
	int ImtiAkieki() {return Akiekis; }
	string ImtiAkoda() {return Akodas; }
	//-------------------------------------
	string ImtiAgentoDuom()
	{
		stringstream ss;
		ss << left << setw(20) << Akodas <<'|' << setw(20) << Apavarde << '|' << setw(20) << Avardas << '|' << setw(30) << Aadresas << '|'
			<< right << setw(15) << telefonas;
		return ss.str();
	}
	//-------------------------------------------
    string ImtiLeidinioDuom(int a)
	{
		stringstream ss;
		ss << "     " << left << setw(20) << L[a].ImtiPavarde() << '|' << setw(20) << L[a].ImtiVarda() << '|' << right << setw(20)
			<< L[a].ImtiKoda() << '|' << setw(10) << L[a].ImtiPradzia << '|' << setw(10) << L[a].ImtiIlgi() << '|' << setw(10) << L[a].ImtiKieki();
		return ss.str();
	}
	//-------------------------------------------
	void Spausdinimas(string RezFailas)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		rez << ImtiAgentoDuom()<< endl;
		for (int i = 0; i < Akiekis; i++)
			rez << ImtiLeidinioDuom(i) << endl;
		rez.close();
	}
	//-------------------------------------------
	int KruvioApskaiciavimasMenesiui()
	{
		for (int i = 0; i < Akiekis; i++)
			for (int j = L[i].ImtiPradzia(); j <= (L[i].ImtiPradzia() + L[i].ImtiIlgi()); j++)
				menesinis[(j - 1) % 12] += L[i].ImtiKieki();
	}
	//-------------------------------------------
	int ImtiMenesioKruvi(int a) {return menesinis[a]; }
};
