#include <iostream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "Lithuanian");
	double pi = 3.1415;
	double H;
	double R, r;
	double V;
	cout << "Áveskite kûgio aukðtinës reikðmæ:" << endl;
	cin >> H;
	cout << "Áveskite kûgio pagrindø spinduliø reikðmes:" << endl;
	cin >> R >> r;
	V = (1.0 / 3) * pi * H * (R * R + R * r + r * r);
	cout << "Kûgio tûris = " << V << endl;
	return 0;
}