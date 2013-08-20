#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Studentas
{
private:
	string pavarde, vardas, grupe, metai, lytis, fakultetas;
	int Npaz, paz[5];
	double vidurkis;
public:
	Studentas();
	Studentas(string a, string b, string c, string d, string e, int f, int h[], string i);
	~Studentas();
	void VidurkioApskaiciavimas();
	string SpausdintiEilute();
	string ImtiVarda();
	string ImtiPavarde();
	string ImtiGrupe();
	string ImtiMetus();
	string ImtiLyti();
	string ImtiFakulteta();
	bool operator < (const Studentas & R);
	double ImtiVidurki();
	int ImtiPazymi (int i);
};
