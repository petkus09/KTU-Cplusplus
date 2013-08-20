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
	string ImtiPavarde();
	string ImtiAdresa();
	string ImtiKoda();
	int ImtiPradzia();
	int ImtiIlgi();
	int ImtiKieki();
	void DetiPavarde(string a);
	void DetiAdresa(string a);
	void DetiKoda(string a);
	void DetiPradzia(int a);
	void DetiIlgi(int a);
	void DetiKieki(int a);
	bool operator < (const Leidinys & R);
};
