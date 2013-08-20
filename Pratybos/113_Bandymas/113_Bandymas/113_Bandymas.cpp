#include <iostream>
using namespace std;

int main ()
{
	int a, b, s;
	double c;
	cout << "Iveskite staciojo trikampio krastines a ir b"<< endl;
	cin >> a, b;
	c = ( (a * a) + (b* b));
	s = (a * b) / 2;
	cout << "Trikampio izambine yra " << c <<", plotas yra " << s << endl;
	return 0;
}
