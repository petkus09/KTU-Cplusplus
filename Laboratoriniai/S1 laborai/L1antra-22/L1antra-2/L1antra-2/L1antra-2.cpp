#include <iostream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "Lithuanian");
	double pi = 3.1415;
	double H;
	double R, r;
	double V;
	cout << "�veskite k�gio auk�tin�s reik�m�:" << endl;
	cin >> H;
	cout << "�veskite k�gio pagrind� spinduli� reik�mes:" << endl;
	cin >> R >> r;
	V = (1.0 / 3) * pi * H * (R * R + R * r + r * r);
	cout << "K�gio t�ris = " << V << endl;
	return 0;
}