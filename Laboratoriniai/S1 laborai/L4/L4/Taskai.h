#include <iostream>
using namespace std;

struct koordinates{
	int x;
	int y;
};

class Taskai
{
private:
	string spalva;
    int kiekis;
    koordinates k[256];
public:
	Taskai();
	Taskai(string spalvaReiksme, int kiekisReiksme);
	~Taskai();
	string ImtiSpalva()        {return spalva; }
	void DetiSpalva(string a)  {spalva = a; }
    int ImtiKieki()            {return kiekis; }
	void DetiKieki(int a)      {kiekis = a;} 
	int ImtiXk(int a)          {return k[a].x; }
	void DetiXk(int a, int  u) {k[a].x = u; }
	int ImtiYk(int a)          {return k[a].y; }
    void DetiYk( int a, int  u) {k[a].y = u; }
};