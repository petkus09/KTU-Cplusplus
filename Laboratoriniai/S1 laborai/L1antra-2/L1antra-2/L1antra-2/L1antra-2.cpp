#include <iostream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "Lithuanian");
	int a;
	int b;
	int suma;
	cout << "�veskite a, b reik�mes:" << endl;
	cin >> a >> b;
	suma = a + b;
	cout << "a + b = " << suma << endl;
	return 0;
}