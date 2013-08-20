#pragma once
#include <string>
#include <fstream>
#include "Agentas.h"
#include "Leidinys.h"

class Agentura
{
private:
	int AgentuKiekis;
	Agentas A[256];
public:
	Agentura(int AgentuKiekisReiksme = 0) : AgentuKiekis(AgentuKiekisReiksme);
	~Agentura();
	void DetiAgenta(Agentas p) {
		A[AgentuKiekis] = p;
		AgentuKiekis++; 
	}
	//----------------------------------------------
	void NuskaitymasA(string DuomFailas)
	{
		ifstream duom(DuomFailas.c_str());
		string kod = "", pavard = "", vard = "", adres = "", telef = "";
		while (!duom.eof()){
			duom >> kod;
		    getline(duom, pavard, ',');
			getline(duom, vard, ',');
			getline(duom, adres, ',');
			duom >> telef;
			duom.ignore();
			Agentas U[kod, pavard, vard, adres, telef];
			DetiAgenta(U);
		}
    duom.close();
	}
	//-----------------------------------------------
	void NuskaitymasB(string DuomFailas)
	{
		ifstream duom(DuomFailas.c_str());
		string pavard = "", adres = "", kod = "", Akod = "";
		int pradz = 0, ilg = 0, kiek = 0;
		while (!duom.eof()){
			getline(duom, pavard, ',');
			getline(duom, adres, ',');
			duom >> pradz >> ilg >> kod >> kiek >> Akod;
			duom.ignore();
			Leidinys U[pavard, adres, pradz, ilg, kod, kiek];
			for (int i = 0; i < AgentuKiekis; i++)
				if (Akod == A[i].ImtiAkoda())
					A[i].DetiLeidini(U);
		}
        duom.close();
	}
	//------------------------------------------------
	void SpausdinimasIfaila(string RezFailas) { for(int i = 0; i < AgentuKiekis; i++) A[i].Spausdinimas(RezFailas); }
};
