#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Prenumeratorius.h"
#include "Leidinys.h"
#include "Pajamos.h"

using namespace std;

//---------------------------------------------------
const string Cduom1 = "U1.txt";
const string Cduom2 = "U2.txt";
//---------------------------------------------------
void Nuskaitymas(Leidinys L[], Pajamos Pj[], int & nl, string duomVardas);
void Nuskaitymas(Prenumeratorius P[], int & np, string duomVardas);
//---------------------------------------------------
int main
{
	Leidinys L[256];
	Pajamos P[256];
	Prenumeratorius P[256];
	int nl = 0, np = 0;
	Nuskaitymas(L, nl, Cduom1);
	Nuskaitymas(P, np, Cduom2);
	return 0;
}
//---------------------------------------------------
void Nuskaitymas(Leidinys L[], Pajamos Pj[], int & nl, string duomVardas)
{
	ifstream duom(duomVardas.c_str());
	string code, name;
	nl = 0;
	double price = 0.0, pajam = 0.0;
	while (!duom.eof()){
		duom >> code;
		getline(duom, name, ',');
		duom >> price;
		L[nl](code, name, price);
		Pj[nl]