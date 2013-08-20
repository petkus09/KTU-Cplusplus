#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Prenumeratoriai.h"
#include "LeidinysB.h"
#include "PajamosB.h"
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------
const string Cduom1 = "U1.txt";
const string Cduom2 = "U2.txt";
const string Crez = "Rezultatai.txt";
//-------------------------------------------------------------------

//-------------------------------------------------------------------
void Nuskaitymas(Pajamos J[], int & nj, string duomVardas);
void Nuskaitymas(Prenumeratoriai P[], int & np, string duomVardas, int nj, Pajamos J[]);
void PradDuomenys(Pajamos J[], Prenumeratoriai P[], int nj, int np, string rezVardas);
void PajamuApskaiciavimas(Pajamos J[], Prenumeratoriai P[], int nj, int np);
void PajamosMenesiui(Pajamos J[], int nj, string rezVardas);
void PajamosVidutine(Pajamos J[], int nj, string rezVardas);
//-------------------------------------------------------------------
int main()
{
	Pajamos J[256];
	Prenumeratoriai P[256];
	int nj = 0, np = 0;
	Nuskaitymas(J, nj, Cduom1);
	Nuskaitymas(P, np, Cduom2, nj, J);
    PradDuomenys(J, P, nj, np, Crez);
	PajamuApskaiciavimas(J, P, nj, np);
	PajamosMenesiui(J, nj, Crez);
	PajamosVidutine(J, nj, Crez);
	return 0;
}
//-----------------------------------------------------------------
void Nuskaitymas(Pajamos J[], int & nj, string duomVardas)
{
	ifstream duom(duomVardas.c_str());
	string code, name;
	nj = 0;
	double price = 0.0;
	while (!duom.eof()){
		duom >> code;
		getline(duom, name, ',');
		duom >> price;
		J[nj].DetiKoda(code);
		J[nj].DetiPavadinima(name);
		J[nj].DetiKaina(price);
		J[nj].DetiUzdirbi(0.0);
		nj++;
		duom.ignore();
	}
	//nj--;
}
//------------------------------------------------------------------
void Nuskaitymas(Prenumeratoriai P[], int & np, string duomVardas, int nj, Pajamos J[])
{
	ifstream duom(duomVardas.c_str());
	string pav, adr, code;
	int pradz, ilg, kiek;
	np = 0;
    while (!duom.eof()){
		duom >> pav;               P[np].DetiPavarde(pav);
		getline(duom, adr, ',');   P[np].DetiAdresa(adr);
		duom >> pradz;             P[np].DetiPradzia(pradz);
		duom >> ilg;               P[np].DetiIlgi(ilg);
		duom >> code;
		duom >> kiek;              P[np].DetiKieki(kiek);
		duom.ignore();
		for(int i = 0; i <= nj; i++)
			if (code == J[i].ImtiKoda()){
               P[np].DetiPavadinima(J[i].ImtiPavadinima());
               P[np].DetiKaina(J[i].ImtiKaina());
			   P[np].DetiKoda(J[i].ImtiKoda());
			}
		np++;
	}
	np--;
	duom.close();
}
//------------------------------------------------------------------
void PradDuomenys(Pajamos J[], Prenumeratoriai P[], int nj, int np, string rezVardas)
{
	ofstream rez(rezVardas.c_str());
	rez << "--------------------------Laikrasciai-------------------------" << endl;
	rez << right << setw(21) << "-----Kodas-----|" << setw(31) << "-----Pavadinimas-----|" << setw(10) << "-----kaina" << endl;
	for (int i = 0; i < nj; i++)
	  rez << right << setw(20) << J[i].ImtiKoda()<< '|' << setw(30) << J[i].ImtiPavadinima() << '|' << setw(10) << J[i].ImtiKaina() << " Lt" << endl;
	rez << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	rez << "---------------------------------------------Pirkejai-------------------------------------------------------------------------" << endl;
    rez << right << setw(21) << "-----Pavarde-----|" << setw(41) << "-----Adresas-----|" << setw(11) << "-Pradzia-|" <<
		setw(11) << "--Ilgis-|" << setw(21) << "-----Kodas-----|" << setw(10) << "--Kiekis--" << endl;
	for (int i = 0; i < np; i++)
	  rez << right << setw(20) << P[i].ImtiPavarde() << '|' << setw(40) << P[i].ImtiAdresa() << '|' << setw(10) << P[i].ImtiPradzia() << '|' <<
	  setw(10) << P[i].ImtiIlgi() << '|' << setw(20) << P[i].ImtiKoda() << '|' << setw(10) << P[i].ImtiKieki() << endl;
	rez << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	rez.close();
}
//--------------------------------------------------------------------
void PajamuApskaiciavimas(Pajamos J[], Prenumeratoriai P[], int nj, int np)
{
	double u = 0.0;
	double bendras = 0.0;
	for (int i = 0; i <= nj; i++)
		for (int j = 0; j <= 11; j++)
			J[i].DetiMenesini(j, 0.0);
	for (int i = 0; i <= np; i++)
		for (int j = 0; j <= nj; j++)
			if (P[i].ImtiKoda() == J[j].ImtiKoda()){
				u = P[i].ImtiKieki() * P[i].ImtiKaina();
			   for (int k = P[i].ImtiPradzia() - 1; k <= P[i].ImtiPradzia() + P[i].ImtiIlgi() - 1; k++){
			        J[j].DetiMenesini((k % 12), J[j].ImtiMenesini(k % 12) + u);
				    bendras += u;
				  }
			   J[j].DetiUzdirbi(J[j].ImtiUzdirbi() + bendras);
		 	   bendras = 0.0;
             }
}
//---------------------------------------------------------------------
void PajamosMenesiui(Pajamos J[], int nj, string rezVardas)
{
	string M[12]= {"Sausis", "Vasaris"};  M[2]  = "Kovas";  M[3]  = "Balandis"; M[4] = "Geguþë";
    M[5]  = "Birþelis";  M[6]  = "Liepa";  M[7]  = "Rugpjûtis";  M[8]  = "Rugsëjis";
    M[9]  = "Spalis";  M[10] = "Lapkritis";  M[11] = "Gruodis";
	int Max = 0;
	ofstream rez(rezVardas.c_str(), ios::app);
	rez << endl;
	rez << "------------------------------Menesio laikrasciai, gave daugiausiai pajamu ------------------------- " <<endl;
	rez << "---------------------------------------------------------------------------------------------------- " <<endl;
	for (int i = 0; i <= 11; i++){
		rez << right << setw(20) << M[i] << "|";
		for (int j = 0; j <= nj; j++)
			if (J[j].ImtiMenesini(i) > J[Max].ImtiMenesini(i))
				Max = j;
		rez << right << setw(30) << J[Max].ImtiPavadinima() << '|' << setw(10) << J[Max].ImtiMenesini(i)<< " Lt"<< endl;
	}
	rez.close();
}
//-----------------------------------------------------------------------
void PajamosVidutine(Pajamos J[], int nj, string rezVardas)
{
  ofstream rez(rezVardas.c_str(), ios::app);
  double vid = 0.0;
  int Nk = -1;
  Pajamos U[256];
  for (int i = 0; i <= nj; i++)
	  vid += J[i].ImtiUzdirbi();
  vid = (vid / (nj + 1));
  for (int i = 0; i <= nj; i++)
	  if (J[i].ImtiUzdirbi() < vid){
		  Nk++;
		  U[Nk] = J[i];
	  }
  for (int i = 0; i <= Nk - 1; i++)
	  for (int j = i + 1; j <= Nk; j++)
		  if (U[i].ImtiKaina() < U[j].ImtiKaina() || (U[i].ImtiKaina() == U[j].ImtiKaina() &&
				  U[i].ImtiPavadinima() > U[j].ImtiPavadinima())) {
			  Pajamos C;
			  C = U[i];
			  U[i] = U[j];
			  U[j] = C;
		  }
		  /*else
			  if (U[i].ImtiKaina() == U[j].ImtiKaina())
				  if (U[i].ImtiPavadinima() > U[j].ImtiPavadinima()){
					   Pajamos C;
			           C = U[i];
			           U[i] = U[j];
			           U[j] = C;
				  }*/
    rez << endl;
    rez << "---------------------------------------------------------------------------------------------------- " <<endl;
	rez << "------------------Laikraðèiai, kuriø pajamos maþesnës uþ vidutines---------------------------------- " <<endl;
	rez << "----------------------------vidurkis : " << vid << " Lt--------------------------------------------------- " <<endl;
	rez << right << setw(21) << "-----Kodas-----|" << setw(31) << "-----Pavadinimas-----|" << setw(14) <<
		"--------kaina|" << setw(16) << "---------pajamos" <<  endl;
	for (int i = 0; i <= Nk; i++)
         rez << right << setw(20) << U[i].ImtiKoda()<< '|' << setw(30) << U[i].ImtiPavadinima() << '|' <<
		 setw(10) << U[i].ImtiKaina() << " Lt|" << setw(15) << U[i].ImtiUzdirbi() << " Lt" << endl;
	rez.close();
}
