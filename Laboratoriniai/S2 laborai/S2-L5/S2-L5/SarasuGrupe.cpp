#include "StdAfx.h"
#include "SarasuGrupe.h"

SarasuGrupe::SarasuGrupe(): p(NULL), d(NULL) {}
SarasuGrupe::~SarasuGrupe() {Naikinti();}
//----------------------------------------------------------
void SarasuGrupe::DetiIPabaiga(Studentas x)
{
	Pradzia();
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
//---------------------------------------------------------
void SarasuGrupe::Pradzia()
{
	d = p;
}
//---------------------------------------------------------
void SarasuGrupe::Kitas()
{
	d = d->ImtiPirmyn();
}
//---------------------------------------------------------
Studentas SarasuGrupe::ImtiStudenta()
{
	return d->ImtiStudenta();
}
//---------------------------------------------------------
bool SarasuGrupe::YraSarasas()
{
	return (d != NULL);
}
//---------------------------------------------------------
void SarasuGrupe::Naikinti()
{
	while (p != NULL){
      d = p;
	  p = p->ImtiPirmyn();
    delete d;
	}
}
//---------------------------------------------------------
void SarasuGrupe::Rikiavimas()
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
//-------------------------------------------------------------
void SarasuGrupe::Isvedimas(string Crez)
{
	ofstream rez(Crez.c_str(), ios::app);
	Pradzia();
	rez << "/------------------------------------------------------------------------------------------------/" << endl;
	rez << left << setw(15) << "Pavardë" << left << setw(15) << "Vardas" << setw(10) << "Grupë" << setw(12) << "Metai" << setw(10) << "Lytis" << setw(16) << "Paþymiai" << setw(9) << "Vidurkis" << right << setw(14) << "Fakultetas" << endl;
	rez << "/------------------------------------------------------------------------------------------------/" << endl;
	while (YraSarasas())
	{
		rez << d->ImtiStudenta().SpausdintiEilute() << "     " << d->ImtiStudenta().ImtiFakulteta() << endl;
		Kitas();
	}
	rez << "/------------------------------------------------------------------------------------------------/" << endl;
	rez.close();
}