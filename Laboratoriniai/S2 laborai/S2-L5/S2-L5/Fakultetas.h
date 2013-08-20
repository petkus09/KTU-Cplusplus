#pragma once
#include "Elementas.h"
#include "SarasuGrupe.h"
using namespace std;

class Fakultetas
{
private:
	Fakultetas * kitas;
	string info;
	Elementas *p;
	Elementas *d;
public:
	Fakultetas();
	~Fakultetas();
	string ImtiInfo();
	void DetiInfo(string x);
	void DetiDuomenis(Studentas x);
	void SpausdintiFakulteta(string Crez);
	bool YraElementas();
	void FakultetoPradzia();
	void SekantisElementas();
	Fakultetas * ImtiPirmyn();
	void DetiIPabaiga(Studentas x);
	void Rikiavimas();
	void Papildymas(SarasuGrupe * x);
	void Naikinti();
	void DetiPirmyn(Fakultetas * r);
	void Lytis(double & a, int & b, double & c, int & e);
	void Isarasa(SarasuGrupe *S, double v);
};
