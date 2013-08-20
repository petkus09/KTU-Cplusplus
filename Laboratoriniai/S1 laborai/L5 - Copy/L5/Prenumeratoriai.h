#pragma once
#include "leidinysB.h"
#include <string>
using namespace std;

class Prenumeratoriai :
	public Leidinys
{
private:
	string pavarde, adresas, Pkodas;
	int pradzia, ilgis, kiekis;
public:
	Prenumeratoriai() : Leidinys(), pavarde(""), adresas(""), pradzia(0), ilgis(0), kiekis(0){}
	Prenumeratoriai(string pavardeR, string adresasR, int pradziaR, int ilgisR, int kiekisR)
		: Leidinys(), pavarde(pavardeR), adresas(adresasR), pradzia(pradziaR), ilgis(ilgisR), kiekis(kiekisR) {}
	~Prenumeratoriai() {}
	void DetiPavarde(string b) {pavarde = b; }
	void DetiAdresa(string b)  {adresas = b; }
	void DetiPradzia(int b)    {pradzia = b; }
	void DetiIlgi(int b)       {ilgis = b; }
	void DetiKieki(int b)      {kiekis = b; }
	string ImtiPavarde()       {return pavarde; }
	string ImtiAdresa()        {return adresas; }
	int ImtiPradzia()          {return pradzia; }
	int ImtiIlgi()             {return ilgis; }
	int ImtiKieki()            {return kiekis; }
};