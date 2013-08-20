#include <iostream>
using namespace std;

class Kambarys {
private:
	double ilgis, plotis;
public:
	Kambarys (): ilgis(0), plotis(0) {}
	~Kambarys() {}
	void Deti(double ilg, double plot)
	{ilgis = ilg; plotis = plot;}
	double Plotas() {return ilgis * plotis;};
}
int main ()
{
	Kambarys kamb[4];
	double ilgis, plotis, plotas = 0;
	for (int i = 0; i < 4; i++){
		cout << "Iveskite "<< i << "-iojo kambario ilgi "<<endl;
		cin >> ilgis;
		cout << "Iveskite "<< i << "-iojo kambario ploti "<<endl;
		cin >> plotis;
		kamb[i].Deti(ilgis, plotis);
	}
	for (int i = 0; i < 4; i++)
		plotas += kamb[i].Plotas();
	cout << "Buto plotas: " << plotas << endl;
	return 0;
}