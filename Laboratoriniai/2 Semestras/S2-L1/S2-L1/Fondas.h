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
 static const int  Cmoksl = 32;
private:
	double Premija[Cpremijos];
	Mokslininkai *M;
	int n;
public:
	Fondas();
	~Fondas();
	void DetiKiek(int a);
	int Kiek();
    Mokslininkai Imti(int i);
	void DetiP(double p, int i);
    void  Deti(Mokslininkai p);
	double ImtiP (int i);
	void Paskirstymas();
	void Rikiavimas();
};
