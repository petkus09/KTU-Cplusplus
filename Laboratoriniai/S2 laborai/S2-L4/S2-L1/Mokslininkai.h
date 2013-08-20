#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Mokslininkai
{
public:
 static const int Cpremijos=4;
private:
	string kodas, vardas, pavarde;
	double ind[Cpremijos], pin[Cpremijos] , S;
public:
	Mokslininkai() {}
	~Mokslininkai() {}
	Mokslininkai(string kodasR, string vardasR, string pavardeR, double indR[]);
	string Spausdinti();
	string SpausdintiPapildomai();
	void ApskaiciuotiS();
	void DetiUzdirbius(double a, int b);
	double ImtiS();
	double ImtiIndelius(int i);
	bool operator > (const Mokslininkai & C);
};
