#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
//----------------------------------
const int Ck = 64;
const string Cduom = "Duomenys.txt";
const string Crez = "Rezultatai.txt";
const string Canaliz = "Analize.txt";
const int CmaxEil = 35;                         //Nusako, kiek maximum gali buti simboliu eiluteje
//----------------------------------
void Nuskaitymas(string  M[][Ck], string DuomFailas, int & n, int  K[], string Z[][Ck]);   //Nuskaitomi duomenys
void Paskirstymas(int n, string eilute, string  M[][Ck], int  K[], string Z[][Ck]);        //Suskirsto eilute i zodzius ir skyriklius
void Rezultatai(string M[][Ck], string RezFailas, int  n, int  K[], string Z[][Ck]);       //Isveda teksta i rezultatu faila
void Simetriskumas(int n, string M[][Ck], int K[], string Z[][Ck]);                        //bazine simetriskumo ir darbo su juo procedura
bool SimetriskumoPatikra(string zodis);                                                    //Patikrina, ar zodis simetriskas
void AnalizesIrasymas(string zodis, int i, int kuris, string RezFailas);                   //Isveda zodzio duomenis i analizes faila
void ZodisIpradzia(int i, int j, string M[][Ck], int K[], string Z[][Ck]);                 //Perkelia simetriska zodi su skyrikliu i teksto pradzia
void Tvarkymas(string M[][Ck], int & n, int K[], string Z[][Ck], int Max);                 //Tvarko eilutes, kad jos nevirsytu nustatyto limito
void Kelimas(string M[][Ck], int r1, int r2, string Z[][Ck], int K[], int  & n);           //Kelia likusius eilutes zodzius i sekancia eilute
//----------------------------------
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	string M[Ck][Ck];
	string Z[Ck][Ck];
	int n = 1;
	int K[Ck]; for (int i = 0; i < Ck - 1; i++) K[i] = 0;
	Nuskaitymas(M, Cduom, n, K, Z);
	Simetriskumas(n, M, K, Z);
	Tvarkymas(M, n, K, Z, CmaxEil);
	Rezultatai(M, Crez, n, K, Z);
	return 0;
}
//---------------------------------------------------
void Nuskaitymas(string  M[][Ck], string DuomFailas, int & n, int  K[], string Z[][Ck])
{
	string eilute;
	ifstream duom(DuomFailas.c_str());
	while (!duom.eof()){
        getline (duom, eilute);
		Paskirstymas (n, eilute, M, K, Z); 
		n++;
	}
	duom.close();
}
//---------------------------------------------------
void Paskirstymas(int n, string eilute, string  M[][Ck], int  K[], string Z[][Ck])
{
	string Skirt = " .,!?:;()\t";
	string zodis;
	string zenklas = "";
	int i = 0;
	int j = 0;
	while ((i = eilute.find_first_not_of(Skirt, j)) != string::npos) {
		j = eilute.find_first_of(Skirt, i);
		int r = eilute.find_first_not_of(Skirt, j);
		if (r != -1 && j != -1)
			zenklas = eilute.substr(j, r - j);
		  else
		    if (j!= -1)
				zenklas = eilute.substr(j);
		zodis = eilute.substr(i, j - i);
		M[n][K[n]] = zodis;
		Z[n][K[n]] = zenklas;
		K[n]++;
	}
}
//----------------------------------------------------
void Simetriskumas(int n, string M[][Ck], int K[], string Z[][Ck])
{
	ofstream rez(Canaliz.c_str());
	rez << left << setw(15) << "-----Zodis-----" << '|' << right << setw(3) << "Eil" << '|' << setw(3) << "Poz" << endl;
	rez << "------------------------------------" << endl;
	rez.close();
	for (int i = 1; i < n; i++)
		for (int j = 0; j < K[i]; j++)
			if (SimetriskumoPatikra(M[i][j])){
				AnalizesIrasymas(M[i][j], i, j, Canaliz);
				ZodisIpradzia(i, j, M, K, Z);
			}
}
//----------------------------------------------------
bool SimetriskumoPatikra(string zodis)
{
	bool T = 1;
	int r = zodis.length();
	int r2 = r / 2;
	for (int i = 0; i <= r2; i++)
		if (zodis[i] != zodis[r - 1 - i])
			T = 0;
	return T;
}
//----------------------------------------------------
void Rezultatai(string M[][Ck], string RezFailas, int  n, int  K[], string Z[][Ck])
{
	ofstream rez(RezFailas.c_str());
	for (int i = 0; i < n; i++){
		for (int j = 0; j < K[i]; j++)
			rez << M[i][j] << Z[i][j];
		rez << endl;
	}
	rez.close();
}
//----------------------------------------------------
void AnalizesIrasymas(string zodis, int i, int kuris, string RezFailas)
{
	ofstream rez(RezFailas.c_str(), ios::app);
	rez << left << setw(15) << zodis << '|' << right << setw(3) << i << '|' << setw(3) << kuris + 1 << endl;
	rez.close();
}
//----------------------------------------------------
void ZodisIpradzia(int i, int j, string M[][Ck], int K[], string Z[][Ck])
{
	M[0][K[0]] = M[i][j];
	Z[0][K[0]] = Z[i][j];
	for (int m = j; m < K[i] - 1; m++){
		M[i][m] = M[i][m + 1];
		Z[i][m] = Z[i][m + 1];
	}
	M[i][K[i] - 1] = "";
	Z[i][K[i] - 1] = "";
	K[0]++;
	K[i]--;
}
//-----------------------------------------------------
void Tvarkymas(string M[][Ck], int & n, int K[], string Z[][Ck], int Max)
{
	for (int i = 0; i <n; i++){
		string Sak = "";
		for (int j = 0; j < K[i]; j++){
			  string r = Sak + M[i][j] + Z[i][j];
			  int r1 = r.length();
			  if (r1 > Max){
				  Kelimas(M, i, j, Z, K, n);
				  break;
			      }
			  else 
				  Sak  += M[i][j] + Z[i][j];
		      }
	}
}
//------------------------------------------------------------------
void Kelimas(string M[][Ck], int r1, int r2, string Z[][Ck], int K[], int  & n)
{
	if (r1 == n - 1){
		n++;
		K[n - 1] = 0;
	}
	int m2 = 0; //Sis kintamasis nusako, kuris zodis yra keliamas i sekancia eilute
	for (int i = r2; i < K[r1]; i++){
		K[r1 + 1]++;
		for (int j = K[r1 + 1] - 1; j > m2; j--){
			M[r1 + 1][j] = M[r1 + 1][j - 1];
			Z[r1 + 1][j] = Z[r1 + 1][j - 1];
		}
		M[r1 + 1][m2] = M[r1][i];
		Z[r1 + 1][m2] = Z[r1][i];
		m2++;
	}
	K[r1] = K[r1] - m2;
}