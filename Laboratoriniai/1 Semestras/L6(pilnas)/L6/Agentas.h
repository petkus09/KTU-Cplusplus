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
    Leidinys L[10];
public:
	Agentas() {}
	~Agentas() {}
	//---------------------------
	void DetiAkoda(string a) {Akodas = a; }
    void DetiApavarde(string b) {Apavarde = b; }
	void DetiAvarda(string c) {Avardas = c; }
	void DetiAadresa(string d) {Aadresas = d; }
	void DetiTelefona(string e) {telefonas = e; }
	void DetiAkieki(int a) {Akiekis = a; }
	//---------------------------
	void DetiLeidini(string a, string b, string c, int d, int e, int f) 
	{
		L[Akiekis].DetiPavarde(a);
		L[Akiekis].DetiAdresa(b);
		L[Akiekis].DetiKoda(c);
		L[Akiekis].DetiPradzia(d);
		L[Akiekis].DetiIlgi(e);
		L[Akiekis].DetiKieki(f);
		Akiekis++; 
	}
	//-----------------------------
	Leidinys ImtiLeidini(int a) {return L[a]; }
	int ImtiAkieki() {return Akiekis; }
	string ImtiAadresa() {return Aadresas; }
	string ImtiApavarde() {return Apavarde; }
	string ImtiAkoda() {return Akodas; }
	//-------------------------------------
	string ImtiAgentoDuom()
	{
		stringstream ss;
		ss << left << setw(10) << Akodas <<'|' << setw(15) << Apavarde << '|' << setw(15) << Avardas << '|' << setw(20) << Aadresas << '|'
			<< right << setw(10) << telefonas;
		return ss.str();
	}
	//-------------------------------------------
    string ImtiLeidinioDuom(int a)
	{
		stringstream ss;
		ss << "     " << left << setw(15) << L[a].ImtiPavarde() << '|' << setw(20) << L[a].ImtiAdresa() << '|' << right << setw(9)
			<< L[a].ImtiKoda() << '|' << setw(3) << L[a].ImtiPradzia() << " mën." << '|' << setw(3) << L[a].ImtiIlgi() << " mën. trukmë" << '|' << setw(4) << L[a].ImtiKieki() << " vnt.";
		return ss.str();
	}
	//-------------------------------------------
	string ImtiVardoDuom()
	{
		stringstream ss;
		ss << Apavarde << " " << Avardas;
		return ss.str();
	}
	//-------------------------------------------
	string ImtiMenesioDuom(int a)
	{
		stringstream ss;
		ss << a + 1 << "-o mënesio krûvis yra " << menesinis[a] << " leid.";
		return ss.str();
	}
	//-------------------------------------------
	void Spausdinimas(string RezFailas)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		rez << ImtiAgentoDuom()<< endl;
		for (int i = 0; i < Akiekis; i++)
			rez << ImtiLeidinioDuom(i) << endl;
		rez << "-----------------------------------------------------------------------------"<< endl;
		rez.close();
	}
	//-------------------------------------------
	void KruvioApskaiciavimasMenesiui()
	{
		for (int i = 0; i < 12; i++)
			menesinis[i] = 0;
		for (int i = 0; i < Akiekis; i++)
			for (int j = L[i].ImtiPradzia(); j <= (L[i].ImtiPradzia() + L[i].ImtiIlgi()); j++)
				menesinis[(j - 1) % 12] += L[i].ImtiKieki();
	}
	//-------------------------------------------
	int ImtiMenesioKruvi(int a) {return menesinis[a]; }
	//-------------------------------------------
	void LeidiniuRikiavimas()
	{
		Leidinys C;
		for (int i = 0; i < Akiekis - 1; i++)
			for (int j = i + 1; j < Akiekis; j++)
				if (L[i].ImtiAdresa() < L[j].ImtiAdresa() || (L[i].ImtiAdresa() == L[j].ImtiAdresa() && L[i].ImtiPavarde() < L[j].ImtiPavarde())){
					C = L[i];
					L[i] = L[j];
					L[j] = C;
				}
	}
};
