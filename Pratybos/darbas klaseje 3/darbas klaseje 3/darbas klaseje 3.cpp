#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int x;
	cout << "Iveskite x : " << endl;
	cin >> x;
	if (x < -9)
		cout << "Atsakymas yra " << pow( 3 * x * x * x * x - 6 * x * x *x + 15 * x * x - 1 , 0.5) << endl;
	else 
		if (x >= -9 && x < 0)
			if (x != -8 && x * x * x >= -15)
				cout << "Atsakymas yra " << pow( x * x * x + 15 , 0.5) / (x + 8) << endl;
			else cout << "Atsakymas negalimas del netinkamo kintamojo " << endl;
		else 
			if (x != 1)
			  cout << "Atsakymas yra " << (x + 1) / ((x - 1) * pow ( x + 1, 0.5)) << endl;
			else cout << "Atsakymas negalimas del netinkamo kintamojo" << endl;
     return 0;
}