#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	int a, b;
	cout << "�veskite pirm�j� r��i� skai�i� (prad�ia):" << endl;
	cin >> a;
	cout << "�veskite antr�j� r��i� skai�i� (pabaiga):" << endl;
	cin >> b;
	cout << "Skai�iai nuo 1 iki 10 ir j� kvadratai:" << endl;
	for (int i = a; i < (b + 1) ; i++)
		cout << i << ' ' << i * i * i << endl;
	cout << "Buvo skai�iuojami " << (b - a + 1) << " skai�iai" << endl;
	cout << endl;
	return 0;
}
