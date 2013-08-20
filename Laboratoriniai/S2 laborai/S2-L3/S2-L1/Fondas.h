#pragma once
#include "Mokslininkai.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Fondas
{
public:
 static const int Cpremijos=4;
private:
	struct Mazgas{
	Mokslininkai duom;
	Mazgas *pirmyn;
	Mazgas *atgal;
};
	double Premija[Cpremijos];
	Mazgas *pradzia;
	Mazgas *pabaiga;
	Mazgas *d;
public:
	Fondas();
	~Fondas();
    void Pradzia();
    void Pabaiga();
    void Sekantis();
    void Ankstesnis();
	bool Yra();
	Mokslininkai ImtiDuomenis();
	void DetiDuomenis(Mokslininkai x);
	void DetiIPradzia(Mokslininkai x);
	void DetiIPabaiga(Mokslininkai x);
	void DetiP(double p, int i);
	double ImtiP (int i);
	void Paskirstymas();
	void Rikiavimas();
};
