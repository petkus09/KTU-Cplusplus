#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx, x;
	int a;
	cout << "�veskite a reik�m�: " << endl;
	cin >> a;
	cout << "�veskite x reik�m�: " << endl;
	cin >> x;
	if (x <= 0)
		fx = a * exp( - x);
	else 
		if (x < 1)
			fx = 5 * a * x - 7;
		else 
			fx = pow (x + 1, 0.5);
	cout << "Reik�m� a = " << a << ", reik�m� x = " << x << ", fx = " << fx << endl;
	return 0;
}


