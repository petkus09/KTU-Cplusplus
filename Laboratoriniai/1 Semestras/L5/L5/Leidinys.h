#include <string>

using namespace std;

class Leidinys
{
private:
	string kodas, pavadinimas;
	double kaina;
public:
	Leidinys(void): kodas(""), pavadinimas(""), kaina(0,0) {}
	Leidinys(string KodasReiksme, string PavadinimasReiksme, double KainaReiksme): kodas(KodasReiksme), pavadinimas(PavadinimasReiksme), kaina(KainaReiksme) {}
	~Leidinys(void) {}
	void DetiKoda(string a)       { kodas = a; }
	void DetiPavadinima(string a) { pavadinimas = a; }
	void DetiKaina(double a)      { kaina = a; }
	string ImtiKoda()             { return kodas; }
	string ImtiPavadinima()       { return pavadinimas; }
	double ImtiKaina()            { return kaina; }
};