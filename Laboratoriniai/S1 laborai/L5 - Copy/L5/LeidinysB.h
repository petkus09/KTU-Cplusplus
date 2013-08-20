#pragma once
#include <string>

using namespace std;

class Leidinys
{
private:
	string kodas, pavadinimas;
	double kaina;
public:
	Leidinys() : kodas(""), pavadinimas(""), kaina(0.0) { }
	Leidinys(string kodasR, string pavadinimasR, double kainaR): kodas(kodasR), pavadinimas(pavadinimasR), kaina(kainaR) {}
	~Leidinys() {}
	void DetiKoda(string a)       { kodas = a; }
	void DetiPavadinima(string a) { pavadinimas = a; }
	void DetiKaina(double a)      { kaina = a; }
	string ImtiKoda()             { return kodas; }
	string ImtiPavadinima()       { return pavadinimas; }
	double ImtiKaina()            { return kaina; }
};