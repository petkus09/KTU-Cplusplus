#pragma once
#include <string>
using namespace std;

class Leidinys
{
private:
	string pavarde, adresas, kodas;
	int pradzia, ilgis, kiekis;
public:
	Leidinys() {}
	~Leidinys() {}
	string ImtiPavarde() {return pavarde; }
	string ImtiAdresa()  {return adresas; }
	string ImtiKoda()    {return kodas; }
	int ImtiPradzia()    {return pradzia; }
	int ImtiIlgi()       {return ilgis; }
	int ImtiKieki()      {return kiekis; }
	void DetiPavarde(string a) {pavarde = a; }
	void DetiAdresa(string a)  {adresas = a; }
	void DetiKoda(string a)    {kodas = a; }
	void DetiPradzia(int a)    {pradzia = a; }
	void DetiIlgi(int a)       {ilgis = a; }
	void DetiKieki(int a)      {kiekis = a; }
};
