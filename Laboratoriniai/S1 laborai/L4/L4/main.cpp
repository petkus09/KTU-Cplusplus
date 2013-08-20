#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include "Taskai.h"
#include "TaskaiB.h"

using namespace std;

//-----------------------------------------------------------------
const string Cduom1 = "U2a.txt";
const string Cduom2 = "U2b.txt";
const int Cspalva = 256;
const int Ctaskai = 100;

//---------------------------------------------------------------
void Nuskaitymas(string failoVardas, TaskaiB Tb[], int & Sspalvos, int SpalvaMax, Taskai T[]);
void Nuskaitymas(string failoVardas, Taskai T[], int Sspalvos, int TaskaiMax);
void Isvestis(Taskai T[], int Sspalvos, TaskaiB Tb[]);
void Trikampis(Taskai T[], int k);
//==============================================================
int main()
{
	Taskai T[Cspalva];
	TaskaiB Tb[Cspalva];
	int n;
	Nuskaitymas(Cduom2, Tb, n, Cspalva, T);
	Nuskaitymas(Cduom1, T, n, Ctaskai);
	Isvestis (T, n, Tb);
	return 0;
}
//=============================================================
Taskai::Taskai(string spalvaReiksme, int kiekisReiksme): spalva(spalvaReiksme), kiekis(kiekisReiksme) { }
Taskai::Taskai(): spalva(""), kiekis(0) { }
Taskai::~Taskai() { }
//-------------------------------------------------------------
TaskaiB::TaskaiB(string spalvaReiksme, bool dalyvisReiksme): spalva(spalvaReiksme), dalyvis(dalyvisReiksme){ }
TaskaiB::TaskaiB(): spalva(""), dalyvis(0) { }
TaskaiB::~TaskaiB() { }
//-------------------------------------------------------------
void Nuskaitymas(string failoVardas, TaskaiB Tb[], int & Sspalvos, int SpalvaMax, Taskai T[])
{
	ifstream duom(failoVardas.c_str());
	string spalv;
	string dalyv;
	int i = 0;
    while (!duom.eof() && i <= SpalvaMax - 1)              //U2b.txt nuskaitymas
	{
		getline (duom, spalv, ',');
		T[i].DetiSpalva(spalv);
		Tb[i].DetiSpalva(spalv);
		duom >> dalyv;
		if (dalyv == "taip")
			Tb[i].DetiDalyvi(1);
		else 
			if (dalyv == "ne")
				Tb[i].DetiDalyvi(0);
		T[i].DetiKieki(-1);
	    i++;
		duom.ignore();
	}
	i--;
	duom.close();
	Sspalvos = i;
}
//-------------------------------------------------------------
void Nuskaitymas(string failoVardas, Taskai T[], int Sspalvos, int TaskaiMax)
{
	ifstream duom(failoVardas.c_str());
	int x1, y1, m;
	string spalv;
	duom >> m;
	if (m > TaskaiMax)
		m = TaskaiMax;
	for (int i = 1 ; i <= m; i++)
	{
		getline (duom, spalv, ',');
		duom >> x1;
		duom >> y1;
        for (int j = 0 ; j <= Sspalvos; j++)
			if (T[j].ImtiSpalva() == spalv){
				T[j].DetiKieki(T[j].ImtiKieki()+1);
				T[j].DetiXk(T[j].ImtiKieki(), x1);
				T[j].DetiYk(T[j].ImtiKieki(), y1);
			}
      duom.ignore();
	}
   duom.close();
}
//-----------------------------------------------------------------
void Isvestis(Taskai T[], int Sspalvos, TaskaiB Tb[])
{
	for (int i = 0; i <= Sspalvos; i++)
		if (Tb[i].ImtiDalyvi() == 0)
			cout << Tb[i].ImtiSpalva() << " negalima" << endl;
		else
			if (T[i].ImtiKieki()  <= 1)   //Jeigu yra tik 2 arba maziau tasku, trikampio neimanoma sudaryti (kiekis skaiciuojamas nuo 0)
				cout << T[i].ImtiSpalva() << " Nera" << endl;
			else
			  Trikampis(T, i);
}
//------------------------------------------------------------------
void Trikampis(Taskai T[], int k)
{
	bool Egz = 0;                //Sis kintamasis nurodys, ar egzistuoja bent vienas lygiasonis trikampis
	double P, Pmax = 0;
	double r1, r2, r3;
	int taskas1, taskas2, taskas3;
	for (int j1 = 0; j1 <= T[k].ImtiKieki() - 2; j1++)
		for (int j2 = j1 + 1; j2 <= T[k].ImtiKieki() - 1; j2++)
			for (int j3 = j2 + 1; j3 <= T[k].ImtiKieki(); j3++){
				P = 0;          //Apskaiciuojamos kiekvienos trikampio krastines
				r1 = pow(pow(T[k].ImtiXk(j1) - T[k].ImtiXk(j2), 2.0) + pow(T[k].ImtiYk(j1) - T[k].ImtiYk(j2), 2.0), 0.5);
                r2 = pow(pow(T[k].ImtiXk(j2) - T[k].ImtiXk(j3), 2.0) + pow(T[k].ImtiYk(j2) - T[k].ImtiYk(j3), 2.0), 0.5);
				r3 = pow(pow(T[k].ImtiXk(j3) - T[k].ImtiXk(j1), 2.0) + pow(T[k].ImtiYk(j3) - T[k].ImtiYk(j1), 2.0), 0.5);
				if (r1 == r2 || r2 == r3 || r3 == r1){
					Egz = 1;
					P = r1 + r2 + r3;
					if (P > Pmax){
						Pmax = P;
						taskas1 = j1;
						taskas2 = j2;
						taskas3 = j3;
					}
				}
			}
	if (Egz == 1){
		cout << T[k].ImtiSpalva() << endl;
		cout << T[k].ImtiXk(taskas1) << ' ' << T[k].ImtiYk(taskas1) << endl;
		cout << T[k].ImtiXk(taskas2) << ' ' << T[k].ImtiYk(taskas2) << endl;
		cout << T[k].ImtiXk(taskas3) << ' ' << T[k].ImtiYk(taskas3) << endl;
		cout << Pmax << endl;
	}
	else cout << T[k].ImtiSpalva() << " Nera" << endl;
}