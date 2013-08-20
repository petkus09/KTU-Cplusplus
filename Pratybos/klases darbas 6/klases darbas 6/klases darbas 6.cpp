#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//---------------------------------------------------------------------
class obelis
{
private:
	int kiek, priaug;
	int desnis(double a, int b, double z);
public:
    obelis() : kiek(0), priaug(16) { };
	obelis(int kiek, int prieaug): kiek(kiek), priaug(priaug) { };
	~obelis(void) { }
	void obuoliai (int n, int a, int b, char tekstas[]);
};
//-------------------------------------------------------------------------
int obelis::desnis(double a, int b, double z)
{
  if (sin(a*z) >= 0.1){
	double t = pow(sin(a*z) - 0.1 , 0.5);
	int y = (int) floor (a - b*t + z*t * t);
	return y;
  }
  else 
	  return 0;
}
//-------------------------------------------------------------------
void obelis::obuoliai(int n, int a, int b, char tekstas[])
{
	cout << tekstas << endl;
	int z = kiek;
	int y;
	for (int i = 0; i < n; i++) {
		if ((y = desnis(a, b, z)) > 0)
			cout << i + 1 << setw(10) << y << endl;
		else
			cout << i + 1 << setw(16) << "nera obuoliu" << endl;
		z = z + priaug;
	}
}
//-------------------------------------------------------------------------
int main()
{
	int n, a, b;
	cout << "Iveskite kiek metu " << endl;
	cin >> n;
	cout << "Iveskite du prieaugio koficientus " << endl;
	cin >> a >> b;
	obelis o1;
	o1.obuoliai(n, a, b, "Pirma obelis");
	int kiek, did;
	cout << "Iveskite pirmu metu obuoliu kieki " << endl;
	cin >> kiek;
	cout << "Iveskite obuoliu padidejimo kieki " << endl;
	cin >> did;
	obelis o2(kiek, did);
	o2.obuoliai(n, a, b, "Antra obelis");
	return 0;
}