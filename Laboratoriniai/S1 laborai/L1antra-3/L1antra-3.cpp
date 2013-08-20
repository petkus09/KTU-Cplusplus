#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	int a, b;
	cout << "Áveskite pirmàjá rëþiø skaièiø (pradþia):" << endl;
	cin >> a;
	cout << "Áveskite antràjá rëþiø skaièiø (pabaiga):" << endl;
	cin >> b;
	cout << "Skaièiai nuo 1 iki 10 ir jø kvadratai:" << endl;
	for (int i = a; i < (b + 1) ; i++)
		cout << i << ' ' << i * i * i << endl;
	cout << "Buvo skaièiuojami " << (b - a + 1) << " skaièiai" << endl;
	cout << endl;
	return 0;
}
