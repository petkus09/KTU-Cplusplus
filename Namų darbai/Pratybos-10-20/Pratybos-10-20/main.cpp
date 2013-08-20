#include <iostream>
#include <fstream>
#include <sstring>
#include <string>
using namespace std;
//----------------------------------------------------
class Sklypas
{
private:
	int plotas;
	double plotas;
public:
	Sklypas(): adresas(""), plotas(0) { }
	Sklypas(string adres, int pl) : adresas(adres), plotas(pl) { }
	int ImtiPlota() { return plotas; }
	string ImtiAdresas() {return adresas; }

};
//----------------------------------------------------
const char u1[]="U1.txt";
const char Ur[]="Rezultatai.txt";
const int MaxKiek = 100;
const int CDydis = 6;
void Ivesti(Sklypas S[], int & n);
void Spausdinti(Sklypas S[], int n);
int Maxi(Sklypas S[], int n);
int Suma(Sklypas S[], int n);
int Kiek(Sklypas S[], int n);
//---------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	int n;
	ofstream fr(Ur);
	fr.close();
	Sklypas S[MaxKiek];
	Ivesti (S, n);
	Spausdinti (S, n);
	fr.open(Ur, ios::app);
	fr << "Didziausio sklypo plotas " << Maxi(S, n) << endl;
	fr << "Sklypu plotu suma " << Suma (S, n) << endl;
	fr << "Sklypu, kuriu plotas > nei " << CDydis << " yra " << Kiek(S, n) << endl;
	fr.close();
	return 0;
}
//----------------------------------------------------------------------------
void Ivesti(Sklypas S[], int & n)
{
	ifstream fd(u1);
	fd >> n;
	int pl;
	for (int i = 0; i < n; i++) {
		fd >> pl;
		S[i] = Sklypas(pl);
	}
	fd.close();
}
//----------------------------------------------------------------------------
void Spausdinti(Sklypas S[], int n)
{
	ofstream fr(Ur, ios::app);
	fr << "Sklypu plotai " << endl;
	for (int i=0; i < n; i++)
		fr << S[i].ImtiPlota() <<  " ";
	fr << endl;
	fr.close();
}
//----------------------------------------------------------------------------
int Maxi(Sklypas S[], int n)
{
	int max = S[0].ImtiPlota();
	for (int i = 0; i < n ; i++)
		if (S[i].ImtiPlota() > max)
			max = S[i].ImtiPlota();
	return max;
}
//----------------------------------------------------------------------------
int Suma (Sklypas S[], int n)
{
	int s = 0;
	for (int i = 0; i < n ; i++)
		s+= S[i].ImtiPlota();
	return s;
}
//----------------------------------------------------------------------------
int Kiek(Sklypas S[], int n)
{
	int kiek = 0;
	for(int i = 0; i < n; i++)
		if (S[i].ImtiPlota() > CDydis)
			kiek++;
	return kiek;
}
//------------------------------------------------------------------------------
