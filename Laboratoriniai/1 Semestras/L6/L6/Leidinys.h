#pragma once
#include <string>
using namespace std;

class Leidinys
{
private:
	string pavarde, adresas, kodas;
	int pradzia, ilgis, kiekis;
public:
	Leidinys(string pavardeR = "", string adresasR= "", string kodasR = "", int pradziaR = 0, int ilgisR = 0, int kiekisR = 0)
		: pavarde(pavardeR), adresas(adresasR), pradzia(pradziaR), ilgis(ilgisR), kodas(kodasR), kiekis(kiekisR);
	~Leidinys();
	string ImtiPavarde() {return pavarde; }
	string ImtiAdresa()  {return adresas; }
	string ImtiKoda()    {return kodas; }
	int ImtiPradzia()    {return pradzia; }
	int ImtiIlgi()       {return ilgis; }
	int ImtiKieki()      {return kiekis; }
};
