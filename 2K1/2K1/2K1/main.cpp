/*
Sukurkite klas� Miestas, skirt� vieno miesto duomenims saugoti.+
Sukurkite konteinerin� klas� DaugMiest�, kurioje b�t� objekt� dinaminis masyvas M(n) miest� duomenims saugoti.+
Pagrindin�je funkcijoje main() apra�ykite DaugMiest� tipo konteiner� A, kuriame saugokite i� failo nuskaitytus duomenis.+
Klaviat�ra nurodomas valstyb�s pavadinimas. Atrinkite �ios valstyb�s miest� duomenis �DaugMiest� tipo konteiner� B.+
Surikiuokite �io konteinerio masyv� pagal plotus (ma��jimo kryptimi) ir miest� pavadinimus alfabeto tvarka �minmaks� b�du.+
Spausdinkite lentel�mis tekstiniame faileRezultatai.txt duomenis ir rezultatus (prie� ir po rikiavimo).+

1.	Klas�s Miestas apra�as, konstruktorius, destruktorius, s�sajos metodai, palyginimo operatorius	1.5 t�k.+
2.	Klas�s DaugMiest� apra�as, konstruktorius, destruktorius, s�sajos metodai	1.5 t�k.+
3.	Duomen� failo pavyzdys (3 eilut�s)	0.5 t�k.+(6 eilutes)
4.	Duomen� failo eilu�i� kiekio skai�iavimo funkcija	0.5 t�k.+
5.	Duomen� skaitymo i� failo funkcija	1.0 t�k.+
6.	Spausdinimo lentele � fail� funkcija	1.0 t�k.+
7.	Rezultat� masyvo dyd�io skai�iavimo funkcija	1.0 t�k.+
8.	Konteinerio formavimo funkcija	1.0 t�k.+(Atrinkti)
9.	Klas�s DaugMiest� masyvo M(n) rikiavimo metodas	1.0 t�k.+
10.	main() funkcija	1.0 t�k.+

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

class DaugMiest�{
private:
  Miestas * M;
  int n;
public:
  DaugMiest�(): n(0), M(NULL){}
  ~DaugMiest�(){ /*delete [] M;*/}

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
void Skaityti(DaugMiest� & M);
void Spausdinti(DaugMiest� M);
void Atrinkti(string mPav, DaugMiest� A, DaugMiest� & B);
int KiekRezSarDuomenu(string mPav, DaugMiest� A, DaugMiest� B);

//==============================
int main(){
  ofstream fr(Rez);
  fr.close();

  DaugMiest� A, B;

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
  fr << "Prie� rikiavim�:\n";
  fr.close();
  
  //Formuoja nauj� s�ra��
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
  string eilut�;
  int kiek = 0;
  while (!fd.eof()) {
    getline(fd, eilut�);
    kiek++;
  }
  fd.close();
  return kiek;
}

void Skaityti(DaugMiest� & M){
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

void Spausdinti(DaugMiest� M)
{
  ofstream fr(Rez, ios::app);
   fr << "Miestai:\n";
   fr << "____________________________________________________________\n";
   fr << " Nr. Miestas   Valstybe  Gyv. Skai�ius Plotas(kv. km)      \n";
   fr << "============================================================\n";
   for (int i = 0;  i < M.Kiek(); i++)
     fr << right << setw(3) << i+1 << ". " << M.ImtiMiesta(i).Spausdinti() << endl;
   fr << "------------------------------------------------------------\n\n";
  fr.close();
}

int KiekRezSarDuomenu(string mPav, DaugMiest� A, DaugMiest� B){
  int kiek = 0;
  for (int i = 0; i < A.Kiek(); i++){
	Miestas Am = A.ImtiMiesta(i);
	if (Am.ImtiValstybe() == mPav)
	  kiek++;
  }
  return kiek;
}

void Atrinkti(string mPav, DaugMiest� A, DaugMiest� & B){
  B.SkirtiAtminti(KiekRezSarDuomenu(mPav, A, B));
  for (int i = 0; i < A.Kiek(); i++){
	Miestas Am = A.ImtiMiesta(i);
    if (Am.ImtiValstybe() == mPav)
	  B.DetiMiesta(Miestas(Am.ImtiMiestoPav(), Am.ImtiValstybe(), Am.ImtiGyventojuSk(), Am.ImtiPlota()));
  }
}