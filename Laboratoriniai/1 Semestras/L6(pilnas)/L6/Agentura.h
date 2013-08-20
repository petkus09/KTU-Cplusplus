#pragma once
#include <string>
#include <fstream>
#include "Agentas.h"
#include "Leidinys.h"
#include <iomanip>

class Agentura
{
private:
	int AgentuKiekis;
	Agentas A[10];
public:
	Agentura() {}
	~Agentura() {}
	//-----------------------------------------------
	void DetiAgenta(string a, string b, string c, string d, string e) {
	    A[AgentuKiekis].DetiAkoda(a);
        A[AgentuKiekis].DetiApavarde(b);
	    A[AgentuKiekis].DetiAvarda(c);
	    A[AgentuKiekis].DetiAadresa(d);
	    A[AgentuKiekis].DetiTelefona(e);
		A[AgentuKiekis].DetiAkieki(0);
		AgentuKiekis++; 
	}
	//----------------------------------------------
	void NuskaitymasA(string DuomFailas)
	{
		ifstream duom(DuomFailas.c_str());
		string kod = "", pavard = "", vard = "", adres = "", telef = "";
		AgentuKiekis = 0;
		while (!duom.eof()){
			duom >> kod;
		    getline(duom, pavard, ',');
			getline(duom, vard, ',');
			getline(duom, adres, ',');
			duom >> telef;
			duom.ignore();
			DetiAgenta(kod, pavard, vard, adres, telef);
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
			for (int i = 0; i < AgentuKiekis; i++)
				if (Akod == A[i].ImtiAkoda())
					A[i].DetiLeidini(pavard, adres, kod, pradz, ilg, kiek);
		}
        duom.close();
	}
	//------------------------------------------------
	void SpausdinimasIfaila(string RezFailas) {
		ofstream rez (RezFailas.c_str());
		for(int i = 0; i < AgentuKiekis; i++) 
			A[i].Spausdinimas(RezFailas); 
	}
	//------------------------------------------------
	void Rikiavimas()
	{
		Agentas C;
		for (int i = 0; i < AgentuKiekis; i++) A[i].LeidiniuRikiavimas();
		for (int i = 0; i < AgentuKiekis - 1; i++)
			for (int j = i + 1; j < AgentuKiekis; j++)
				if (A[i].ImtiAadresa() < A[j].ImtiAadresa() || (A[i].ImtiAadresa() == A[j].ImtiAadresa() && A[i].ImtiApavarde() < A[j].ImtiApavarde())){
					C = A[i];
					A[i] = A[j];
					A[j] = C;
				}
	}
	//------------------------------------------------
	void RikiavimoSpausdinimas(string RezFailas)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		for (int i = 0; i < AgentuKiekis; i++)
		{
			A[i].KruvioApskaiciavimasMenesiui();
			rez << A[i].ImtiVardoDuom() << endl;
			rez << "-----------Leidiniai--------" << endl;
			for (int j = 0; j < A[i].ImtiAkieki(); j++)
				rez <<"     " << A[i].ImtiLeidinioDuom(j) << endl;
			rez << "-----------Kruviai----------" << endl;
			for (int j = 0; j < 12; j++)
			   rez << "     " << A[i].ImtiMenesioDuom(j) << endl;
			rez << "-------------------------------------------------------" << endl;
		}
		rez.close();
	}
    //------------------------------------------------
	void MazaiDirbantysAgentai(string RezFailas)
	{
		Agentas M[10];
		int Mkiekis = 0;
		double vidurkiai[12];
		for (int i = 0; i < 12; i++){
			vidurkiai[i] = 0.0;
			for (int j = 0; j < AgentuKiekis; j++)
                vidurkiai[i] += A[j].ImtiMenesioKruvi(i);
			vidurkiai[i] /= AgentuKiekis;
		}
		for (int i = 0; i < 12; i++){
			Mkiekis = 0;
			for (int j = 0; j < AgentuKiekis; j++)
				if (A[j].ImtiMenesioKruvi(i) < vidurkiai[i]){
					M[Mkiekis] = A[j];
					Mkiekis++;
				}
			VidurkinisSpausdinimas(M, Mkiekis, vidurkiai[i], RezFailas, i);
		}
	}
	//------------------------------------------------
	void VidurkinisSpausdinimas(Agentas M[], int Mkiekis, double vidurkis, string RezFailas, int r)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		rez << r + 1 << "-as menesis. Menesio vidurkis: " << vidurkis << endl;
		for (int i = 0; i < Mkiekis; i++)
			rez << M[i].ImtiAgentoDuom() << '|' << right << setw(4) << M[i].ImtiMenesioKruvi(r) << " leid. " << endl;
		rez << "-----------------------------------------------------" << endl;
		rez.close();
	}
	};
