#include <string>
#include "Leidinys.h"

using namespace std;

class Prenumeratorius: public Leidinys
{
private:
	string pavarde, adresas;
	int pradzia, ilgis, kiekis;
public:
	Leidinys(void): Leidinys(), pavarde(""), adresas(""), pradzia(), ilgis(), kiekis(0) {}
	Leidinys(string pav, string ad, int pr, int ilg, string kod, int kiek);
	~Leidinys(void) {}
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