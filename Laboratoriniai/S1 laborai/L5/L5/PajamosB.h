#pragma once
#include <string>
#include "LeidinysB.h"

using namespace std;

class Pajamos: public Leidinys
{
private:
	double uzdirbis;
	double menesinis[12];
public:
	Pajamos(double uzdirbisR = 0.0)
		: Leidinys(), uzdirbis(uzdirbisR)  {}
	~Pajamos() {}
	void DetiUzdirbi(double c) {uzdirbis = c; }
	double ImtiUzdirbi()       {return uzdirbis; }
	void DetiMenesini(int i, double c){ menesinis[i] = c; }
	double ImtiMenesini(int i) { return menesinis[i]; }
};