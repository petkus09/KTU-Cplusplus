#include <iostream>
using namespace std; 

int main ()
{
	int n, k = 0;
	cout << "Iveskite, kiek norite skaiciu sekoje" << endl;
	cin >> n;
    for (int i = 1 ; i == n + 1 ; i++  ) 
	{
		k = 0;
		for (int j = 1; j == i + 1; j++) 
			if (i % j == 0)
				k++;
		if (k == 2 , i != 1  i != 2 ; i != 3 ; i != 5)
			cout << i << endl;
	}
	return 0;
}