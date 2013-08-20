#include "StdAfx.h"
#include "Fondas.h"
using namespace std;
Fondas::Fondas() : p(NULL), d(NULL) {}
Fondas::~Fondas()
{
	while (p != NULL){
      d = p;
      p = p->sek;
    delete d;
 }
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
	//--------------------------------------------------------
	void Fondas::Paskirstymas() {
		double indS = 0;
		double pinigai;
		for (int i = 0; i < Cpremijos; i++){
			indS = 0;
			Pradzia();
			while (Yra()){
				indS+= ImtiDuomenis().ImtiIndelius(i);
				Sekantis();
			}
			Pradzia();
			while (Yra()){
				pinigai = (ImtiDuomenis().ImtiIndelius(i) / indS) * Premija[i];
				Mokslininkai x;
				x = Mokslininkai(ImtiDuomenis());
				x.DetiUzdirbius(pinigai, i);
				DetiDuomenis(x);
				Sekantis();
			}
		}
		Pradzia();
		while (Yra()){
				Mokslininkai x;
				x = Mokslininkai(ImtiDuomenis());
				x.ApskaiciuotiS();
				DetiDuomenis(x);
				Sekantis();
			}
	}
	//-------------------------------------------------------
	void Fondas::Rikiavimas()
	{ 
	   bool yra = true;  	
	   Mazgas *d, *d1, *r;
       while (yra) {
         yra = false;                    
		 d = d1 = r = p;
	     while (d1 != NULL) {
			 if (d1->duom > d->duom) {
               yra = true;
               if (d == p) {      // pirmas elementas su kaimynu
                 p = p->sek;            
			     d->sek = d1->sek;       
			     d1->sek = d;
               }
               else {               // pora tolesniø elementø
                 d->sek = d1->sek;          
			     d1->sek = d;           
			     r->sek = d1;
               }
            }  
        r = d; 
	    d = d1;  
	    d1 = d1->sek;
        }
	  }
    }