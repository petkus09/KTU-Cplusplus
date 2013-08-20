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
const int CmaxEil = 35;
//----------------------------------
void Nuskaitymas(string  M[][Ck], string DuomFailas, int & n, int  K[], string Z[][Ck]);
void Paskirstymas(int n, string eilute, string  M[][Ck], int  K[], string Z[][Ck]);
void Rezultatai(string M[][Ck], string RezFailas, int  n, int  K[], string Z[][Ck]);
void Simetriskumas(int n, string M[][Ck], int K[], string Z[][Ck]);
bool SimetriskumoPatikra(string zodis);
void AnalizesIrasymas(string zodis, int i, int kuris, string RezFailas);
void ZodisIpradzia(int i, int j, string M[][Ck], int K[], string Z[][Ck]);
void Tvarkymas(string M[][Ck], int n, int K[], string Z[][Ck], int Max);
void Kelimas(string M[][Ck], int i, int j, string Z[][Ck], int K[], int  & n);
//----------------------------------
int main()
{
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
void Tvarkymas(string M[][Ck], int n, int K[], string Z[][Ck], int Max)
{
	for (int i = 0; i <n; i++){
		int r = 0;
		string Sak = "";
		for (int j = 0; j < K[i]; j++){
			r = (Sak + M[i][j] + Z[i][j]).length();
			if (r > Max)
				Kelimas(M, i, j, Z, K, n);
			else 
				Sak  = Sak + M[i][j] + Z[i][j];
			
		}
	}
}
//------------------------------------------------------------------
void Kelimas(string M[][Ck], int i, int j, string Z[][Ck], int K[], int  & n)
{
	if (i = n - 1){
		n++;
		K[n - 1] = 0;
	}
	K[i + 1]++;
	for (int u1 = K[i + 1] - 1; u1 > 0; u1++){
		M[i + 1][u1] = M[i + 1][u1 - 1];
		Z[i + 1][u1] = Z[i + 1][u1 - 1];
	}
    M[i + 1][0] = M[i][j];
	for (int u1 = j; u1 < K[i] - 1; u1++){
		M[i][u1] = M[i][u1 + 1];
		Z[i][u1] = Z[i][u1 + 1];
	}
	M[i][K[i]] = "";
	Z[i][K[i]] = "";
	K[i]--;	
}
	