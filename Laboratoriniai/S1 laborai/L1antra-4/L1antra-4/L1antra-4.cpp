#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	char simbolis;
	int n, k;
	cout << "�veskite simbol�:" << endl;
	cin >> simbolis;
	cout << "�veskite, kiek norite simboli� (i� viso):"<< endl;
	cin >> n;
    cout << "�veskite, kiek norite simboli� vienoje eilut�je :"<< endl;
	cin >> k;
	for (int i = 1; i < n + 1 ; i = i + k) 
	{ 
		for (int j = 1; j < k + 1; j++)
			cout << simbolis;
        cout << endl;
	}
	cout << endl;
	return 0;
}