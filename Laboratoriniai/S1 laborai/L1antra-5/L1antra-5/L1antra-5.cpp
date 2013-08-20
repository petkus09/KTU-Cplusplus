#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx;
	int z;
	cout << "Áveskite z reikðmæ: " << endl;
	cin >> z;
	if ( z - 1 >= 0 ){
		fx = pow( z - 1, 0.5);
		cout << "reikðmë z " << z << " fx = " << fx << endl;
	}
	else 
		cout << "reikðmë z " << z << " f-ja neegzistuoja " << endl;
	return 0;
}
