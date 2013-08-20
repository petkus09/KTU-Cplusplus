#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Leidinys.h"
#include "Agentas.h"
#include "Agentura.h"
using namespace std;
//-----------------------------------
const string Cduom1 = "U1.txt";
const string Cduom2 = "U2.txt";
const string Crez = "Rezultatai.txt";
//-----------------------------------
int main()
{
	Agentura I;
	I.NuskaitymasA(Cduom1);
	I.NuskaitymasB(Cduom2);
    I.SpausdinimasIfaila(Crez);
}