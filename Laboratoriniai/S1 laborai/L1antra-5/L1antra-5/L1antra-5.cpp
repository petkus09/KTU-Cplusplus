#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	double fx;
	int z;
	cout << "�veskite z reik�m�: " << endl;
	cin >> z;
	if ( z - 1 >= 0 ){
		fx = pow( z - 1, 0.5);
		cout << "reik�m� z " << z << " fx = " << fx << endl;
	}
	else 
		cout << "reik�m� z " << z << " f-ja neegzistuoja " << endl;
	return 0;
}
