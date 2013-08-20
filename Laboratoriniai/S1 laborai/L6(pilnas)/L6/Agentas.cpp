#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Leidinys.h"
#include "Agentas.h"

//---------------------------
    void Agentas::DetiAkoda(string a) {Akodas = a; }
    void Agentas::DetiApavarde(string b) {Apavarde = b; }
	void Agentas::DetiAvarda(string c) {Avardas = c; }
	void Agentas::DetiAadresa(string d) {Aadresas = d; }
	void Agentas::DetiTelefona(string e) {telefonas = e; }
	void Agentas::DetiAkieki(int a) {Akiekis = a; }
	//---------------------------
	void Agentas::DetiLeidini(string a, string b, string c, int d, int e, int f) 
	{
		if (Akiekis < 100){
		L[Akiekis].DetiPavarde(a);
		L[Akiekis].DetiAdresa(b);
		L[Akiekis].DetiKoda(c);
		L[Akiekis].DetiPradzia(d);
		L[Akiekis].DetiIlgi(e);
		L[Akiekis].DetiKieki(f);
		Akiekis++; 
		menesiuKiekis = 0;
		}
	}
	//-----------------------------
	Leidinys Agentas::ImtiLeidini(int a) {return L[a]; }
	int Agentas::ImtiAkieki() {return Akiekis; }
	string Agentas::ImtiAadresa() {return Aadresas; }
	string Agentas::ImtiApavarde() {return Apavarde; }
	string Agentas::ImtiAkoda() {return Akodas; }
	int Agentas::ImtiMenesiuKieki() {return menesiuKiekis; }
	//-------------------------------------
	string Agentas::ImtiAgentoDuom()
	{
		stringstream ss;
		ss << left << setw(10) << Akodas <<'|' << setw(15) << Apavarde << '|' << setw(15) << Avardas << '|' << setw(20) << Aadresas << '|'
			<< right << setw(10) << telefonas;
		return ss.str();
	}
	//-------------------------------------------
    string Agentas::ImtiLeidinioDuom(int a)
	{
		stringstream ss;
		ss << "     " << left << setw(15) << L[a].ImtiPavarde() << '|' << setw(20) << L[a].ImtiAdresa() << '|' << right << setw(9)
			<< L[a].ImtiKoda() << '|' << setw(3) << L[a].ImtiPradzia() << " mën." << '|' << setw(3) << L[a].ImtiIlgi() << " mën. trukmë" << '|' << setw(4) << L[a].ImtiKieki() << " vnt.";
		return ss.str();
	}
	//-------------------------------------------
	string Agentas::ImtiVardoDuom()
	{
		stringstream ss;
		ss << Apavarde << " " << Avardas;
		return ss.str();
	}
	//-------------------------------------------
	string Agentas::ImtiMenesioDuom(int a)
	{
		stringstream ss;
		ss << a + 1 << "-o mënesio krûvis yra " << menesinis[a] << " leid.";
		return ss.str();
	}
	//-------------------------------------------
	void Agentas::Spausdinimas(string RezFailas)
	{
		ofstream rez(RezFailas.c_str(), ios::app);
		rez << ImtiAgentoDuom()<< endl;
		for (int i = 0; i < Akiekis; i++)
			rez << ImtiLeidinioDuom(i) << endl;
		rez << "-----------------------------------------------------------------------------"<< endl;
		rez.close();
	}
	//-------------------------------------------
	void Agentas::KruvioApskaiciavimasMenesiui()
	{
		for (int i = 0; i < 36; i++)
			menesinis[i] = 0;
		for (int i = 0; i < Akiekis; i++){
			int n = L[i].ImtiPradzia() + L[i].ImtiIlgi();
			if (n > 36)
				n = 36;
			for (int j = L[i].ImtiPradzia(); j < n; j++)
				menesinis[j - 1] += L[i].ImtiKieki(); 
		}
		for (int i = 0; i < Akiekis; i++)
		    if ((L[i].ImtiPradzia() + L[i].ImtiIlgi() < 36)  && (L[i].ImtiPradzia() + L[i].ImtiIlgi() > menesiuKiekis))
			    menesiuKiekis = L[i].ImtiPradzia() + L[i].ImtiIlgi();
		    else 
				if (L[i].ImtiPradzia() + L[i].ImtiIlgi() > 36)
			        menesiuKiekis = 36;
	}
	//-------------------------------------------
	int Agentas::ImtiMenesioKruvi(int a) {return menesinis[a]; }
	//-------------------------------------------
	void Agentas::LeidiniuRikiavimas()
	{
		Leidinys C;
		for (int i = 0; i < Akiekis - 1; i++)
			for (int j = i + 1; j < Akiekis; j++)
				if (L[i] < L[j]){
					C = L[i];
					L[i] = L[j];
					L[j] = C;
				}
	}
	bool Agentas::operator <(const Agentas & R)
    {
      return (Aadresas < R.Aadresas || (Aadresas == R.Aadresas && Apavarde < R.Apavarde));
    }
