#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int x;
	cout << "Iveskite skaiciu :" << endl;
	cin >> x;
	if (x < -10)
		cout << x << endl;
	else 
		if (x >= - 10 && x < -1) 
			if (x * x * x != -8 )
				cout << 1 / (x * x * x + 8) << endl;
			else cout << "negalimas atsakymas, nes skaicius yra -2 " << endl;
		else 
			if (x >= -1)
				cout << (x - 1) / pow( x + 1 , 0.5) << endl;
			else cout << " Negalima nes x < -1" << endl;
	return 0;
}



