#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx;
	int x, y;
	cout << "�veskite x reik�m�: " << endl;
	cin >> x;
	cout << "�veskite y reik�m�: " << endl;
	cin >> y;
	if ( x * x * x - y != 0 ){
		fx = (y * y - 2 * x * y + x * x) / (x * x * x - y);
		cout << "Funkcijos reik�m� yra " << fx << endl;
	}
	else 
		cout << "Funkcija neegzistuoja " << endl;
	return 0;
}