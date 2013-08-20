#include <iostream>
using namespace std;

int main ()
{
	cout << "Iveskite kieki skaiciu" << endl;
	int n, s = 0, a;
	cin >> n;
	for (int i = 1; i<=n; i++ ) 
	{
		cout << "Veskite skaiciu: " << endl;
		cin >> a;
		s = s + a;
	}
	cout << "suma yra : "<< s << endl;
	return 0;
}