#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx, x;
	int a;
	cout << "Áveskite a reikðmæ: " << endl;
	cin >> a;
	cout << "Áveskite x reikðmæ: " << endl;
	cin >> x;
	if (x <= 0)
		fx = a * exp( - x);
	else 
		if (x < 1)
			fx = 5 * a * x - 7;
		else 
			fx = pow (x + 1, 0.5);
	cout << "Reikðmë a = " << a << ", reikðmë x = " << x << ", fx = " << fx << endl;
	return 0;
}


