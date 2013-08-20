#include "StdAfx.h"
#include "Fondas.h"
Fondas::Fondas() : n(0), M(NULL)
{
	M = new Mokslininkai[Cmoksl];
}
Fondas::~Fondas()
{
	delete [] M;
}
using namespace std;
	void Fondas::DetiKiek(int a) { n = a; }
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
	//--------------------------------------------------------
	void Fondas::DetiP(double p, int i)
	{
		Premija[i] = p;
	}
	//--------------------------------------------------------
	double Fondas::ImtiP(int i)
	{
		return Premija[i];
	}
	//--------------------------------------------------------
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
	}