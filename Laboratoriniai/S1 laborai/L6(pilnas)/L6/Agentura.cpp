#include <string>
#include <fstream>
#include "Agentas.h" 
#include <iomanip>
#include "Leidinys.h"
#include "Agentura.h"

    void Agentura::DetiAgenta(string a, string b, string c, string d, string e) {
		if (AgentuKiekis < 10){
	    A[AgentuKiekis].DetiAkoda(a);
        A[AgentuKiekis].DetiApavarde(b);
	    A[AgentuKiekis].DetiAvarda(c);
	    A[AgentuKiekis].DetiAadresa(d);
	    A[AgentuKiekis].DetiTelefona(e);
		A[AgentuKiekis].DetiAkieki(0);
		AgentuKiekis++; 
		}
	}
	//----------------------------------------------
	void Agentura::NuskaitymasA(string DuomFailas)
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
	void Agentura::NuskaitymasB(string DuomFailas)
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
	void Agentura::SpausdinimasIfaila(string RezFailas) {
		ofstream rez (RezFailas.c_str());
		for(int i = 0; i < AgentuKiekis; i++) 
			A[i].Spausdinimas(RezFailas); 
	}
	//------------------------------------------------
	void Agentura::Rikiavimas()
	{
		Agentas C;
		for (int i = 0; i < AgentuKiekis; i++) A[i].LeidiniuRikiavimas();
		for (int i = 0; i < AgentuKiekis - 1; i++)
			for (int j = i + 1; j < AgentuKiekis; j++)
				if (A[i] < A[j]){
					C = A[i];
					A[i] = A[j];
					A[j] = C;
				}
	}
	//------------------------------------------------
	void Agentura::RikiavimoSpausdinimas(string RezFailas)
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
			int n = A[i].ImtiMenesiuKieki() / 12;
			for (int j1 = 0; j1 <= n; j1++){
              rez << "========================" << j1 + 1 << "-i metai=========================="<< endl;
			  for (int j2 = 0; j2 < 12; j2++)
			   rez << "     " << A[i].ImtiMenesioDuom(j2 + j1 * 12) << endl;
			rez << "-------------------------------------------------------" << endl;
			}
		}
		rez.close();
	}
    //------------------------------------------------
	void Agentura::MazaiDirbantysAgentai(string RezFailas)
	{
		Agentas M[10];
		int Mkiekis = 0;
		double vidurkiai[36];
		for (int i = 0; i < 36; i++){
			vidurkiai[i] = 0.0;
			for (int j = 0; j < AgentuKiekis; j++)
                vidurkiai[i] += A[j].ImtiMenesioKruvi(i);
			vidurkiai[i] /= AgentuKiekis;
		}
		for (int i = 0; i < 36; i++){
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
	void Agentura::VidurkinisSpausdinimas(Agentas M[], int Mkiekis, double vidurkis, string RezFailas, int r)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		if (vidurkis != 0.0){
		rez << r + 1 << "-as menesis. Menesio vidurkis: " << vidurkis << endl;
		  for (int i = 0; i < Mkiekis; i++)
			rez << M[i].ImtiAgentoDuom() << '|' << right << setw(4) << M[i].ImtiMenesioKruvi(r) << " leid. " << endl;
		rez << "-----------------------------------------------------" << endl;
		}
		rez.close();
	}