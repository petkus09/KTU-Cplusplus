#pragma once
#include "Elementas.h"
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
	double Premija[Cpremijos];
	Elementas *pradzia;
	Elementas *pabaiga;
	Elementas *d;
public:
	Fondas();
	~Fondas();
    void Pradzia();
    void Pabaiga();
    void Sekantis();
    void Ankstesnis();
	bool Yra();
	Mokslininkai ImtiDuomenis();
	void DetiDuomenis(const Mokslininkai & x);
	void DetiIPradzia(const Mokslininkai & x);
	void DetiIPabaiga(const Mokslininkai & x);
	void DetiP(double p, int i);
	double ImtiP (int i);
	void Paskirstymas();
	void Rikiavimas();
};
