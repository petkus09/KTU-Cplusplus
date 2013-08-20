#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx;
	int x, y;
	cout << "Áveskite x reikðmæ: " << endl;
	cin >> x;
	cout << "Áveskite y reikðmæ: " << endl;
	cin >> y;
	if ( x * x * x - y != 0 ){
		fx = (y * y - 2 * x * y + x * x) / (x * x * x - y);
		cout << "Funkcijos reikðmë yra " << fx << endl;
	}
	else 
		cout << "Funkcija neegzistuoja " << endl;
	return 0;
}