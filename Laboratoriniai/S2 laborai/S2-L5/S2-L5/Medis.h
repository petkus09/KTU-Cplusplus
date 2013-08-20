#pragma once
#include "Fakultetas.h"
#include "SarasuGrupe.h"
//#include <strsafe.h> 
//#include <vcclr.h>
using namespace std;

class Medis
{
private:
	Fakultetas *p;
	Fakultetas *d;
public:
	Medis();
	~Medis();
	void Pradzia();
	void Kitas();
	bool Yra();
	void DetiFakulteta(Fakultetas * F);
	void Isvesti(string Crez);
	void NaikintiMedi();
	void DuomenuPapildymas(SarasuGrupe * x);
	string SkaiciuotiLyti();
	double VyruVidurkis();
	void VaikinuAtrinkimas(SarasuGrupe *S, double v);
};
