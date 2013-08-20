/*
Sukurkite klasæ Miestas, skirtà vieno miesto duomenims saugoti.+
Sukurkite konteinerinæ klasæ DaugMiestø, kurioje bûtø objektø dinaminis masyvas M(n) miestø duomenims saugoti.+
Pagrindinëje funkcijoje main() apraðykite DaugMiestø tipo konteinerá A, kuriame saugokite ið failo nuskaitytus duomenis.+
Klaviatûra nurodomas valstybës pavadinimas. Atrinkite ðios valstybës miestø duomenis áDaugMiestø tipo konteinerá B.+
Surikiuokite ðio konteinerio masyvà pagal plotus (maþëjimo kryptimi) ir miestø pavadinimus alfabeto tvarka „minmaks” bûdu.+
Spausdinkite lentelëmis tekstiniame faileRezultatai.txt duomenis ir rezultatus (prieð ir po rikiavimo).+

1.	Klasës Miestas apraðas, konstruktorius, destruktorius, sàsajos metodai, palyginimo operatorius	1.5 tðk.+
2.	Klasës DaugMiestø apraðas, konstruktorius, destruktorius, sàsajos metodai	1.5 tðk.+
3.	Duomenø failo pavyzdys (3 eilutës)	0.5 tðk.+(6 eilutes)
4.	Duomenø failo eiluèiø kiekio skaièiavimo funkcija	0.5 tðk.+
5.	Duomenø skaitymo ið failo funkcija	1.0 tðk.+
6.	Spausdinimo lentele á failà funkcija	1.0 tðk.+
7.	Rezultatø masyvo dydþio skaièiavimo funkcija	1.0 tðk.+
8.	Konteinerio formavimo funkcija	1.0 tðk.+(Atrinkti)
9.	Klasës DaugMiestø masyvo M(n) rikiavimo metodas	1.0 tðk.+
10.	main() funkcija	1.0 tðk.+

*/
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

//Konstantos
const char Duom[] = "Duomenys.txt";
const char Rez[] = "Rezultatai.txt";

//klases
class Miestas{
private:
  string miestas,
	     valstybe;
  int gyvSkaicius;
  double plotas;
public:
  Miestas(): miestas(""), valstybe(""), gyvSkaicius(0), plotas(0.0){}
  Miestas(string m, string valst, int gyvSk, double pl):
    miestas(m), valstybe(valst), gyvSkaicius(gyvSk), plotas(pl){}
  ~Miestas(){}

  string ImtiMiestoPav(){ return miestas; }
  string ImtiValstybe() { return valstybe; }
  int ImtiGyventojuSk() { return gyvSkaicius; }
  double ImtiPlota()    { return plotas; }

  string Spausdinti(){
    stringstream ss;
	ss << left << setw(10) << miestas
	   << setw(10) << valstybe
	   << setw(14) << gyvSkaicius
	   << fixed << setprecision(2) << plotas;
	return ss.str();
  }
  //uzklotas operatorius
  bool operator > (Miestas & kitas){
	return plotas > kitas.plotas || (plotas == kitas.plotas && miestas < kitas.miestas);
  }
};

class DaugMiestø{
private:
  Miestas * M;
  int n;
public:
  DaugMiestø(): n(0), M(NULL){}
  ~DaugMiestø(){ /*delete [] M;*/}

  void SkirtiAtminti(int n){ M = new Miestas[n]; }
  int Kiek() { return n; }

  Miestas ImtiMiesta(int i) {return M[i];}
  void DetiMiesta(Miestas m) { M[n++] = m;}

  void Rikiuoti(){
	  for (int i = 0; i < n-1; i++){
	    int mind = i;
	    for (int j = i+1; j < n; j++)
		  if (M[j] > M[mind])
		    mind = j;
            Miestas m = M[mind];
            M[mind] = M[i];
            M[i]    = m;
	  }
	}

};

//Metodu aprasai
int KiekDuomenuFaile(const char FV[]);
void Skaityti(DaugMiestø & M);
void Spausdinti(DaugMiestø M);
void Atrinkti(string mPav, DaugMiestø A, DaugMiestø & B);
int KiekRezSarDuomenu(string mPav, DaugMiestø A, DaugMiestø B);

//==============================
int main(){
  ofstream fr(Rez);
  fr.close();

  DaugMiestø A, B;

  Skaityti(A);  
 
  //Spausdinami pradiniai duomynys
  fr.open(Rez, ios::app);
  fr << "Pradiniai duomenys:\n";
  fr << "*******************\n";
  fr.close();

  Spausdinti(A);

  //Spausdinami rezultai
  fr.open(Rez, ios::app);
  fr << "Rezultatai:\n";
  fr << "**********\n";
  fr << "Prieð rikiavimà:\n";
  fr.close();
  
  //Formuoja naujà sàraðà
  string valstybe;
  cout << "Iveskite sali:\n";
  cin >> valstybe;

  Atrinkti(valstybe, A, B);

  //pries rikiavima
  Spausdinti(B);

  //po rikiavimo
  fr.open(Rez, ios::app);
  fr << "Po rikiavimo:\n";
  fr.close();

  B.Rikiuoti();

  Spausdinti(B);	
  
  return 0;
}
//==============================
//metodu realizacijos
int KiekDuomenuFaile(const char FV[])
{
  ifstream fd(FV);
  string eilutë;
  int kiek = 0;
  while (!fd.eof()) {
    getline(fd, eilutë);
    kiek++;
  }
  fd.close();
  return kiek;
}

void Skaityti(DaugMiestø & M){
  ifstream fd(Duom);
  string mies, vals;
  int gSk;
  double pl;

  int n = KiekDuomenuFaile(Duom);
  M.SkirtiAtminti(n);

  for (int i = 0; i < n; i++){

    getline(fd, mies, ',');
    fd >> ws;
    getline(fd, vals, ',');
	fd >> gSk >> pl;

	fd.ignore();

    M.DetiMiesta(Miestas(mies, vals, gSk, pl));
  }
  fd.close();
}

void Spausdinti(DaugMiestø M)
{
  ofstream fr(Rez, ios::app);
   fr << "Miestai:\n";
   fr << "____________________________________________________________\n";
   fr << " Nr. Miestas   Valstybe  Gyv. Skaièius Plotas(kv. km)      \n";
   fr << "============================================================\n";
   for (int i = 0;  i < M.Kiek(); i++)
     fr << right << setw(3) << i+1 << ". " << M.ImtiMiesta(i).Spausdinti() << endl;
   fr << "------------------------------------------------------------\n\n";
  fr.close();
}

int KiekRezSarDuomenu(string mPav, DaugMiestø A, DaugMiestø B){
  int kiek = 0;
  for (int i = 0; i < A.Kiek(); i++){
	Miestas Am = A.ImtiMiesta(i);
	if (Am.ImtiValstybe() == mPav)
	  kiek++;
  }
  return kiek;
}

void Atrinkti(string mPav, DaugMiestø A, DaugMiestø & B){
  B.SkirtiAtminti(KiekRezSarDuomenu(mPav, A, B));
  for (int i = 0; i < A.Kiek(); i++){
	Miestas Am = A.ImtiMiesta(i);
    if (Am.ImtiValstybe() == mPav)
	  B.DetiMiesta(Miestas(Am.ImtiMiestoPav(), Am.ImtiValstybe(), Am.ImtiGyventojuSk(), Am.ImtiPlota()));
  }
}