#include "StdAfx.h"
#include "Fondas.h"
using namespace std;
Fondas::Fondas() : p(NULL), d(NULL) {}
Fondas::~Fondas()
{
	delete [] p;
	delete [] d;
}
//-----------------Baziniai saraso veiksmai---------------------
void Fondas::Pradzia() { d = p; }
void Fondas::Sekantis() {d = d->sek;}
bool Fondas::Yra() {return d != NULL; }
Mokslininkai Fondas::ImtiDuomenis() {return d->duom; }
void Fondas::DetiDuomenis(Mokslininkai x) { d->duom = x;}
//-----------------Naujas elementas dedamas i pradzia----------
void Fondas::DetiIPradzia(Mokslininkai x) 
{
	Mazgas *t = new Mazgas;
	t->duom = x;
	t->sek = p;
	p = t;
}
//----------------Naujas elementas dedamas i pabaiga-----------
void Fondas::DetiIPabaiga(Mokslininkai x)
{
	Mazgas *t = new Mazgas;
	t->duom = x;
	t->sek = NULL;
	if (p != NULL){
		Mazgas *v = new Mazgas;
		for (v = p; v->sek != NULL; v = v->sek);
		v->sek = t;
	}
	else 
		p = t;
}
/*	void Fondas::DetiKiek(int a) { n = a; }
	//--------------------------------------------------------
    int Fondas::Kiek() 
	  { return n; }
	//--------------------------------------------------------
	Mokslininkai Fondas::Imti(int i)
	  { return M[i];}
	//--------------------------------------------------------
    void  Fondas::Deti(Mokslininkai p) { 
		if (n < Cmoksl) 
			M[n] = p;
	  }
	//--------------------------------------------------------*/
	void Fondas::DetiP(double p, int i)
	{
		Premija[i] = p;
	}
	//--------------------------------------------------------
	double Fondas::ImtiP(int i)
	{
		return Premija[i];
	}
/*	//--------------------------------------------------------
	void Fondas::Paskirstymas() {
		double indS = 0;
		double pinigai;
		for (int i = 0; i < Cpremijos; i++){
			indS = 0;
			for (int j = 0; j < n; j++)
				indS+= M[j].ImtiIndelius(i);
			for (int j = 0; j < n; j++){
				pinigai = (M[j].ImtiIndelius(i) / indS) * Premija[i];
				M[j].DetiUzdirbius(pinigai, i);
			}
		}
		for (int i = 0; i < n; i++)
			M[i].ApskaiciuotiS();
	}
	//-------------------------------------------------------
	void Fondas::Rikiavimas()
	{
		Mokslininkai CC;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (M[i] > M[j])
				{
					CC = M[i];
					M[i] = M[j];
					M[j] = CC;
				}
	}*/