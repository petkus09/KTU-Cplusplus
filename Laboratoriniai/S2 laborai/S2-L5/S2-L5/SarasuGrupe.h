#pragma once
#include "Elementas.h"
using namespace std;

class SarasuGrupe
{
private:
	Elementas *p;
	Elementas *d;
public:
	SarasuGrupe();
	~SarasuGrupe();
	void Pradzia();
	void Kitas();
	void DetiIPabaiga(Studentas x);
	Studentas ImtiStudenta();
	void Naikinti();
	bool YraSarasas();
	void Rikiavimas();
	void Isvedimas(string Crez);
};