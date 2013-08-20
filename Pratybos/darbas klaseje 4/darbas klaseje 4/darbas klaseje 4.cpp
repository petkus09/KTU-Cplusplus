#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	double x;
	cout << "Iveskite x" << endl;
	cin >> x;
	if (x >= -3 && x <= 0)
		cout << "Atsakymas yra " << 1 / (x - 5) << endl;
	else 
		if (x > 0 && x < 5)
		  cout << pow( sin( x + 3) , 2) << endl;
		else 
			if (x >= -5)
				cout << pow( x + 5, 0.5);
			else cout << "Atsakymas negalimas " << endl;
    return 0;
}