#include "StdAfx.h"
#include "Sarasas.h"

Sarasas::Sarasas() {}
Sarasas::Sarasas(string a,string  b, int d[], int e) : pavarde(a), vardas(b), Npaz(e)
{
	for (int i = 0; i < Npaz; i++)
		paz[i] = d[i];
}
Sarasas::~Sarasas() {}
string Sarasas::ImtiVarda() {return vardas;}
string Sarasas::ImtiPavarde() {return pavarde;}
int Sarasas::ImtiPazymiuKieki() {return Npaz;}
int Sarasas::ImtiPazymi(int i) {return paz[i];}
//-----------------------------------------------------
string Sarasas::SpausdintiEilute()
{
	stringstream ss;
	ss << left << setw(12) << pavarde << setw(10) << vardas;
	for (int i = 0; i < Npaz; i++)
		ss << right << setw(3) << paz[i];
	return ss.str();
}