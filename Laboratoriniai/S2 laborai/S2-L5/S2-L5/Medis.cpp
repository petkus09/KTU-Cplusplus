#include "StdAfx.h"
#include "Medis.h"

Medis::Medis() : p(NULL), d(NULL) {}
Medis::~Medis()  
{
	NaikintiMedi(); 
}
//----------------------------------------------
void Medis::Pradzia()
{
	d = p;
}
//----------------------------------------------
void Medis::Kitas()
{
	d = d->ImtiPirmyn();
}
//----------------------------------------------
bool Medis::Yra()
{
	return (d != NULL);
}
//----------------------------------------------
void Medis::DetiFakulteta(Fakultetas * F)
{
	Pradzia();
	Fakultetas * t = new Fakultetas;
	t = F;
	t->DetiPirmyn(NULL);
	if (p == NULL)
		  p = t;
	else {
		Fakultetas *v = new Fakultetas;
	    for (v = p; v->ImtiPirmyn() != NULL; v = v->ImtiPirmyn());
		v->DetiPirmyn(t);
	}
}
//-----------------------------------------------------
void Medis::Isvesti(string Crez)
{
	ofstream rez(Crez.c_str());
	Pradzia();
	rez << "/------------------------------------------------------------------------------------------------/" << endl;
	rez << left << setw(15) << "Pavard�" << left << setw(15) << "Vardas" << setw(10) << "Grup�" << setw(12) << "Metai" << setw(10) << "Lytis" << setw(16) << "Pa�ymiai" << setw(9) << "Vidurkis" << endl;
	rez << "/------------------------------------------------------------------------------------------------/" << endl;
	rez.close();
	while (Yra())
	{
		d->SpausdintiFakulteta(Crez);
		Kitas();
	}
	rez.close();
}
//----------------------------------------------
void Medis::NaikintiMedi()
{
	while (p != NULL){
      d = p;
	  p = p->ImtiPirmyn();
    delete d;
	}
}
//----------------------------------------------
void Medis::DuomenuPapildymas(SarasuGrupe * x)
{
	Pradzia();
	while (Yra()){
		d->Papildymas(x);
		Kitas();
	}
}
//----------------------------------------------
string Medis::SkaiciuotiLyti()
{
	double Vyrai = 0;
	double Moterys = 0;
	int VyraiN = 0;
	int MoterysN = 0;
	d = p;
	while (Yra())
	{
		double a = 0.0;
		int b = 0;
		double c = 0.0;
		int e = 0;
		d->Lytis(a, b, c, e);
		Vyrai += a; VyraiN += b; Moterys += c; MoterysN += e;
		Kitas();
	}
	if (Vyrai / VyraiN > Moterys / MoterysN)
		return "Vyr� vidurkis yra auk�tesnis";
	else 
		if (Vyrai / VyraiN < Moterys / MoterysN)
			return "Moter� vidurkis yra auk�tesnis";
		else
			return "Vyr� ir Moter� vidurkiai yra vienodi";
}
//-----------------------------------------------------
double Medis::VyruVidurkis()
{
	double Vyrai = 0;
	int VyraiN = 0;
	d = p;
	while (Yra())
	{
		double a = 0.0;
		int b = 0;
		double c = 0.0;
		int e = 0;
		d->Lytis(a, b, c, e);
		Vyrai += a; VyraiN += b;
		Kitas();
	}
	return Vyrai / VyraiN;
}
//-------------------------------------------------------
void Medis::VaikinuAtrinkimas(SarasuGrupe *S, double v)
{
	Pradzia();
	while (Yra())
	{
		d->Isarasa(S, v);
		Kitas();
	}
}