#include <iostream>
#include <fstream>
using namespace std;
struct girlianda{
	int laikas;
	int kiekis;
	bool lemp[1000];
};
void Svietimas(int j, bool d[1000], int m, int t);
//-----------------------------------------------
int main ()
{
  int n;
  ifstream duom("Duomenys.txt");
  girlianda g[100];
  duom >> n;
  for (int i = 1; i <=n ; i++){
	  duom >> g[i].laikas;
	  duom >> g[i].kiekis;
	  for (int j = 0; j <= (g[i].kiekis - 1); j++)
		  duom >> g[i].lemp[j];
  }
  duom.close();
  for (int i = 1; i <= n ; i++)
	  Svietimas(i, g[i].lemp, g[i].kiekis, g[i].laikas);
  ofstream rez("Rezultatai.txt");
  for (int i = 1; i <= n ; i++){
	  for (int j = 0; j <= g[i].kiekis - 1; j++)
		  rez <<" " << g[i].lemp[j];
	  rez << endl;
  } 
  rez.close();
  return 0;
}
//---------------------------------------------------------------
void Svietimas( int j, bool d[], int m, int t)
{
	int s = 0;
	for (int u = 1; u <= t; u++)
		s += u;
	for (int u = 0; u <= (s - 1); u++)
		d[u % m] = !d[u % m];
}