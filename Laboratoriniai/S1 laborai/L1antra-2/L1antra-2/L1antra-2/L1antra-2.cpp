#include <iostream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "Lithuanian");
	int a;
	int b;
	int suma;
	cout << "Áveskite a, b reikðmes:" << endl;
	cin >> a >> b;
	suma = a + b;
	cout << "a + b = " << suma << endl;
	return 0;
}