#pragma once
#include <string>
#include <iostream>
#include "Leidinys.h"

using namespace std;

class Agentas
{
private:
	string Akodas, Apavarde, Avardas, Aadresas, telefonas;
	int menesinis[36];
	int menesiuKiekis;
	int Akiekis;
    Leidinys L[10];
public:
	Agentas() {}
	~Agentas() {}
	//---------------------------
	void DetiAkoda(string a);
    void DetiApavarde(string b);
	void DetiAvarda(string c);
	void DetiAadresa(string d);
	void DetiTelefona(string e);
	void DetiAkieki(int a);
	void DetiLeidini(string a, string b, string c, int d, int e, int f);
	Leidinys ImtiLeidini(int a);
	int ImtiAkieki();
	string ImtiAadresa();
	string ImtiApavarde();
	string ImtiAkoda();
	string ImtiAgentoDuom();
    string ImtiLeidinioDuom(int a);
	string ImtiVardoDuom();
	string ImtiMenesioDuom(int a);
	void Spausdinimas(string RezFailas);
	void KruvioApskaiciavimasMenesiui();
	int ImtiMenesioKruvi(int a);
	void LeidiniuRikiavimas();
	int ImtiMenesiuKieki();
	bool operator < (const Agentas & R);
};
