#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	char veiksmas;
	double s, a, b;
	veiksmas = '0';
	cout << "Iveskite a:" << endl;
	cin >> a;
	cout << "Iveskite veiksma: " << endl;
	cin >> veiksmas;
	cout << "Iveskite b: " << endl;
	cin >> b;
	if (veiksmas == '+')
		s = a + b;
	else 
		if (veiksmas == '-') 
			s = a - b;
		else 
			if (veiksmas == '*') 
				s = a * b;
			else 
				if (veiksmas == '/')
					s = a / b;
				else cout << "Neteisingas veiksmas" << endl;
				cout << "Ats.: " << s << endl;  
    return 0;
}

	