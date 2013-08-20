#include "StdAfx.h"
#include "Fakultetas.h"

Fakultetas::Fakultetas() : kitas(NULL), info(""), p(NULL) {}
Fakultetas::~Fakultetas() { Naikinti();}
//----------------------------------------------------------
void Fakultetas::DetiInfo(string x)
{
	info = x;
}
//----------------------------------------------------------
void Fakultetas::SpausdintiFakulteta(string Crez)
{
	FakultetoPradzia();
	ofstream rez(Crez.c_str(), ios::app);
	rez <<"------------------------------------------------------------------------" << endl;
	rez << info << endl;
	while (YraElementas()){
		rez << d->ImtiStudenta().SpausdintiEilute() << endl;
		d = d->ImtiPirmyn();
	}
	rez <<"------------------------------------------------------------------------" << endl;
	rez.close();
}
//----------------------------------------------------------
bool Fakultetas::YraElementas()
{
	return (d != NULL);
}
//----------------------------------------------------------
void Fakultetas::FakultetoPradzia()
{
	d = p;
}
//----------------------------------------------------------
void Fakultetas::SekantisElementas()
{
	d = d->ImtiPirmyn();
}
//----------------------------------------------------------
void Fakultetas::DetiIPabaiga(Studentas x)
{
	FakultetoPradzia();
	Elementas *t = new Elementas;
	t->DetiStudenta(x);
	t->DetiPirmyn(NULL);
	if (p == NULL)
      p = t;
	else
	{
	 Elementas *v = new Elementas;
	 for (v = p; v->ImtiPirmyn() != NULL; v = v->ImtiPirmyn());
	 v->DetiPirmyn(t);
	}
}
//----------------------------------------------------------
void Fakultetas::Rikiavimas()
{
	bool yra = true;  	
	   Elementas *d, *d1, *r;
       while (yra) {
         yra = false;                    
		 d = d1 = r = p;
	     while (d1 != NULL) {
			 if (d1->ImtiStudenta() < d->ImtiStudenta()) {
               yra = true;
               if (d == p) {      // pirmas elementas su kaimynu
                 p = p->ImtiPirmyn();            
			     d->DetiPirmyn(d1->ImtiPirmyn());       
			     d1->DetiPirmyn(d);
               }
               else {               // pora tolesniø elementø
                 d->DetiPirmyn(d1->ImtiPirmyn());          
			     d1->DetiPirmyn(d);           
			     r->DetiPirmyn(d1);
               }
            }  
        r = d; 
	    d = d1;  
	    d1 = d1->ImtiPirmyn();
        }
	   }
}
//----------------------------------------------------------
void Fakultetas::DetiDuomenis(Studentas x)
{
	d->DetiStudenta(x);
}
//----------------------------------------------------------
void Fakultetas::Papildymas(SarasuGrupe * x)
{
	x->Pradzia();
	while (x->YraSarasas())
	{
		string vardas = x->ImtiStudenta().ImtiVarda();
		string pavarde = x->ImtiStudenta().ImtiPavarde();
		FakultetoPradzia();
		while (YraElementas())
		{
			string vardas2 = d->ImtiStudenta().ImtiVarda();
			string pavarde2 = d->ImtiStudenta().ImtiPavarde();
			if (vardas == vardas2 && pavarde == pavarde2)
			{
				int paz[5];
				int N = 0;
				for (int j = 0; j < 5; j++)
					paz[j] = x->ImtiStudenta().ImtiPazymi(j);
				Studentas S = d->ImtiStudenta();
				Studentas T = Studentas(S.ImtiPavarde(), S.ImtiVarda(), S.ImtiGrupe(), S.ImtiMetus(), S.ImtiLyti(), 5, paz, S.ImtiFakulteta());
				T.VidurkioApskaiciavimas();
				d->DetiStudenta(T);
			}
			SekantisElementas();
		}
		x->Kitas();
	}
}
//----------------------------------------------------------
string Fakultetas::ImtiInfo()
{
	return info;
}
//----------------------------------------------------------
void Fakultetas::Naikinti()
{
	while (p != NULL){
      d = p;
	  p = p->ImtiPirmyn();
    delete d;
	}
}
//----------------------------------------------------------
Fakultetas *Fakultetas::ImtiPirmyn()
{
	return kitas;
}
//----------------------------------------------------------
void Fakultetas::DetiPirmyn(Fakultetas * r)
{
	kitas = r;
}
//----------------------------------------------------------
void Fakultetas::Lytis(double & a, int & b, double & c, int & e)
{
	a = 0.0;  //vyru vidurkiu suma
	b = 0;  //vary vidurkiu kiekis
	c = 0.0;  //moteru vidurkiu suma
	e = 0;  //moteru vidurkiu kiekis
	d = p;
	while (YraElementas())
	{
		Studentas S = d->ImtiStudenta();
		if (S.ImtiLyti() == "vyras")
		{
			a+= S.ImtiVidurki();
			b++;
		}
		else 
			if (S.ImtiLyti() == "moteris")
			{
				c+= S.ImtiVidurki();
			    e++;
		    }
		SekantisElementas();
	}
}
//--------------------------------------------------
void Fakultetas::Isarasa(SarasuGrupe *S, double v)
{
	FakultetoPradzia();
	while (YraElementas())
	{
		if (d->ImtiStudenta().ImtiLyti() == "vyras")
		if (d->ImtiStudenta().ImtiVidurki() >= v)
			S->DetiIPabaiga(d->ImtiStudenta());
		SekantisElementas();
	}
}