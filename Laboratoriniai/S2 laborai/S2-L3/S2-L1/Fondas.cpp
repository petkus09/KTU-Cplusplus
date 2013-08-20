#include "StdAfx.h"
#include "Fondas.h"
using namespace std;
Fondas::Fondas() : pradzia(NULL), pabaiga(NULL), d(NULL) {}
Fondas::~Fondas()
{
	while (pradzia != pabaiga){
      d = pradzia;
      pradzia = pradzia->pirmyn;
    delete d;
 }
}
//-----------------Baziniai saraso veiksmai---------------------
void Fondas::Pradzia() { d = pradzia->pirmyn; }
void Fondas::Pabaiga() { d = pabaiga->atgal; }
void Fondas::Sekantis() {d = d->pirmyn;}
void Fondas::Ankstesnis() {d = d->atgal;}
bool Fondas::Yra() {return d != pabaiga; }
Mokslininkai Fondas::ImtiDuomenis() {return d->duom; }
void Fondas::DetiDuomenis(Mokslininkai x) { d->duom = x;}
//-----------------Naujas elementas dedamas i pradzia----------
void Fondas::DetiIPradzia(Mokslininkai x) 
{
	if (pradzia == NULL || pabaiga == NULL){
        pradzia = new Mazgas;
		pabaiga = new Mazgas;
		d = pradzia;
		Mazgas *t = new Mazgas;
		pradzia->pirmyn = t;
		t->pirmyn = pabaiga;
		pabaiga->atgal = t;
		t->atgal = pradzia;
		t->duom = x;
	}
	else{
	  Mazgas *t = new Mazgas;
	  t->duom = x;
	  t->atgal = pradzia;
	  (pradzia->pirmyn)->atgal = t;
	  t->pirmyn = pradzia->pirmyn;
	  pradzia->pirmyn = t;
	}
}
//----------------Naujas elementas dedamas i pabaiga-----------
void Fondas::DetiIPabaiga(Mokslininkai x)
{
	if (pradzia == NULL || pabaiga == NULL){
		pradzia = new Mazgas;
		pabaiga = new Mazgas;
		d = pradzia;
		Mazgas *t = new Mazgas;
		pradzia->pirmyn = t;
		t->pirmyn = pabaiga;
		pabaiga->atgal = t;
		t->atgal = pradzia;
		t->duom = x;
	}
	else{
	  Mazgas *t = new Mazgas;
	  t->duom = x;
	  t->pirmyn = pabaiga;
	  (pabaiga->atgal)->pirmyn = t;
	  t->atgal = pabaiga->atgal;
	  pabaiga->atgal = t;
	}
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
		 d = d1 = r = pradzia->pirmyn;
	     while (d1 != pabaiga) {
			 if (d1->duom > d->duom) {
               yra = true;
               if (d == pradzia->pirmyn) {      // pirmas elementas su kaimynu
                 pradzia->pirmyn = (pradzia->pirmyn)->pirmyn;            
			     d->pirmyn = d1->pirmyn;       
			     d1->pirmyn = d;
               }
               else {               // pora tolesniø elementø
                 d->pirmyn = d1->pirmyn;          
			     d1->pirmyn = d;           
			     r->pirmyn = d1;
               }
            }  
        r = d; 
	    d = d1;  
	    d1 = d1->pirmyn;
        }
	  }
    }