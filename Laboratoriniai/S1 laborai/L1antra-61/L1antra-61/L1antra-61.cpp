#include <iostream>
#include <cmath> 
using namespace std;
int main() 
{
  setlocale(LC_ALL, "Lithuanian");
  double fx;
  double x;      
  cout << "Áveskite x reikðmæ:" << endl;
  cin >> x;
  if (x <= 0 && x >= - 1)
     fx = cos (x * x);
  else
    if (x < 1 && x > 0)
      fx = 4 * x * x + 3;
    else
      fx = pow(x * x + x + 4, 0.5);
  cout << ", reikðmë x = " << x << ", fx = " << fx << endl;
  return 0;
}
