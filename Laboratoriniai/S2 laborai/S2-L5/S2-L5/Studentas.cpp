#include "StdAfx.h"
#include "Studentas.h"
//--------------------------------------------------------------------------------------
Studentas::Studentas(): pavarde(""), vardas(""), grupe(""), metai(""), lytis(""), Npaz(0), vidurkis(0), fakultetas("") 
{
	for (int i = 0; i < 5; i++)
		paz[i] = 0;
}
//--------------------------------------------------------------------------------------
Studentas::Studentas(string a, string b, string c, string d, string e, int f, int h[], string i): 
  pavarde(a), vardas(b), grupe(c), metai(d), lytis(e), Npaz(f), fakultetas(i) 
  {
	  for (int i = 0; i < Npaz; i++)
		  paz[i] = h[i];
	  vidurkis = 0;
  }
//--------------------------------------------------------------------------------------
  Studentas::~Studentas() {}
//--------------------------------------------------------------------------------------
void Studentas::VidurkioApskaiciavimas()
{
	double s = 0;
	ofstream rez("Rezultatai3.txt", ios::app);
	for (int i = 0; i < Npaz; i++)
	{
		rez << paz[i] << endl;
		s += paz[i];
	}
	vidurkis = s / Npaz;
	rez.close();
}
//--------------------------------------------------------------------------------------
string Studentas::SpausdintiEilute()
{
	stringstream ss;
	ss << left << setw(15) << pavarde << left << setw(15) << vardas << setw(10) << grupe << setw(12) << metai << setw(10) << lytis;
	for (int i = 0; i < Npaz; i++)
		ss << right << setw(3) << paz[i];
	ss<< ' ';
	if (vidurkis != 0.0)
		ss << right << setw(7) << vidurkis;
	return ss.str();
}
//--------------------------------------------------------------------------------------
bool Studentas::operator < (const Studentas & R)
{
	return fakultetas < R.fakultetas || (fakultetas == R.fakultetas && pavarde < R.pavarde);
}
//--------------------------------------------------------------------------------------
double Studentas::ImtiVidurki()
{
	return vidurkis;
}
//--------------------------------------------------------------------------------------
string Studentas::ImtiVarda()
{
	return vardas;
}
string Studentas::ImtiPavarde()
{
	return pavarde;
}
//--------------------------------------------------------------------------------------
string Studentas::ImtiGrupe()
{
	return grupe;
}
string Studentas::ImtiMetus()
{
	return metai;
}
string Studentas::ImtiLyti()
{
	return lytis;
}
string Studentas::ImtiFakulteta()
{
	return fakultetas;
}
//------------------------------------------
int Studentas::ImtiPazymi (int i)
{
	return paz[i];
}
	