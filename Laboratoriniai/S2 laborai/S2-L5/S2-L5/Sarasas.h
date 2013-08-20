#pragma once
#include "Elementas.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Sarasas
{
private:
	int paz[16], Npaz;
	string pavarde, vardas;
public:
	Sarasas();
	Sarasas(string a,string  b, int d[], int e);
	~Sarasas();
	string ImtiVarda();
	string ImtiPavarde();
	int ImtiPazymiuKieki();
	int ImtiPazymi(int i);
	string SpausdintiEilute();
};
