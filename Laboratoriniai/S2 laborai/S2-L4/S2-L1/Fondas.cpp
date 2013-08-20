#include "StdAfx.h"
#include "Fondas.h"
using namespace std;
Fondas::Fondas() : pradzia(NULL), pabaiga(NULL), d(NULL) {}
Fondas::~Fondas()
{
	Elementas *pap;
	while (pradzia != pabaiga){
      pap = pradzia;
      pradzia = pradzia->ImtiPirmyn();
	  delete pap;
	}
    d = NULL;
}
//-----------------Baziniai saraso veiksmai---------------------
void Fondas::Pradzia() { d = pradzia->ImtiPirmyn(); }
void Fondas::Pabaiga() { d = pabaiga->ImtiAtgal(); }
void Fondas::Sekantis() {d = d->ImtiPirmyn();}
void Fondas::Ankstesnis() {d = d->ImtiAtgal();}
bool Fondas::Yra() {return d != pabaiga; }
Mokslininkai Fondas::ImtiDuomenis() {return d->ImtiDuom(); }
void Fondas::DetiDuomenis(const Mokslininkai & x) { d->DetiDuom(x);}
//-----------------Naujas elementas dedamas i pradzia----------
void Fondas::DetiIPradzia(const Mokslininkai & x) 
{
	if (pradzia == NULL || pabaiga == NULL){
        pradzia = new Elementas;
		pabaiga = new Elementas;
		d = pradzia;
		Elementas *t = new Elementas;
		pradzia->DetiPirmyn(t);
		t->DetiPirmyn(pabaiga);
		pabaiga->DetiAtgal(t);
		t->DetiAtgal(pradzia);
		t->DetiDuom(x);
	}
	else{
	  Elementas *t = new Elementas;
	  t->DetiDuom(x);
	  t->DetiAtgal(pradzia);
	  (pradzia->ImtiPirmyn())->DetiAtgal(t);
	  t->DetiPirmyn(pradzia->ImtiPirmyn());
	  pradzia->DetiPirmyn(t);
	}
}
//----------------Naujas elementas dedamas i pabaiga-----------
void Fondas::DetiIPabaiga(const Mokslininkai & x)
{
	if (pradzia == NULL || pabaiga == NULL){
		pradzia = new Elementas;
		pabaiga = new Elementas;
		d = pradzia;
		Elementas *t = new Elementas;
		pradzia->DetiPirmyn(t);
		t->DetiPirmyn(pabaiga);
		pabaiga->DetiAtgal(t);
		t->DetiAtgal(pradzia);
		t->DetiDuom(x);
	}
	else{
	  Elementas *t = new Elementas;
	  t->DetiDuom(x);
	  t->DetiPirmyn(pabaiga);
	  (pabaiga->ImtiAtgal())->DetiPirmyn(t);
	  t->DetiAtgal(pabaiga->ImtiAtgal());
	  pabaiga->DetiAtgal(t);
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
	   Elementas *d, *d1, *r;
       while (yra) {
         yra = false;                    
		 d = d1 = r = pradzia->ImtiPirmyn();
	     while (d1 != pabaiga) {
			 if (d1->ImtiDuom() > d->ImtiDuom()) {
               yra = true;
               if (d == pradzia->ImtiPirmyn()) {      // pirmas elementas su kaimynu
                 pradzia->DetiPirmyn((pradzia->ImtiPirmyn())->ImtiPirmyn());            
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