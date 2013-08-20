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
	Mazgas *sek;
};
	double Premija[Cpremijos];
	Mazgas *p;
	Mazgas *d;
public:
	Fondas();
	~Fondas();
	void Pradzia();
	void Sekantis();
	bool Yra();
	Mokslininkai ImtiDuomenis();
	void DetiDuomenis(Mokslininkai x);
	void DetiIPradzia(Mokslininkai x);
	void DetiIPabaiga(Mokslininkai x);
	/*void DetiKiek(int a);
	int Kiek();
    Mokslininkai Imti(int i);*/
	void DetiP(double p, int i);
    //void  Deti(Mokslininkai p);
	double ImtiP (int i);
	/*void Paskirstymas();
	void Rikiavimas();*/
};
