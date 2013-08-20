#include <iostream>
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
  girlianda g[100];
  cout << "Iveskite Girliandu skaiciu" << endl;
  cin >> n;
  for (int i = 1; i <=n ; i++){
	  cout << "Iveskite " << i <<"-ios Girliandos svietimo trukme " << endl;
	  cin >> g[i].laikas;
	  cout << "Iveskite " << i <<"-ios Girliandos lempuciu skaiciu " << endl;
	  cin >> g[i].kiekis;
	  cout << "Veskite " << i <<"-ios Girliandos lempuciu padetis " << endl;
	  for (int j = 0; j <= (g[i].kiekis - 1); j++)
		  cin >> g[i].lemp[j];
  }
  for (int i = 1; i <= n ; i++)
	  Svietimas(i, g[i].lemp, g[i].kiekis, g[i].laikas);
  for (int i = 1; i <= n ; i++){
	  for (int j = 0; j <= g[i].kiekis - 1; j++)
		  cout <<" " << g[i].lemp[j];
	  cout << endl;
  } 
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