#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Lithuanian");
	char simbolis;
	int n, k;
	cout << "Áveskite simbolá:" << endl;
	cin >> simbolis;
	cout << "Áveskite, kiek norite simboliø (ið viso):"<< endl;
	cin >> n;
    cout << "Áveskite, kiek norite simboliø vienoje eilutëje :"<< endl;
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