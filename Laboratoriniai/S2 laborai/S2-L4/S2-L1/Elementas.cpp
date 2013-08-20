#include "StdAfx.h"
#include "Elementas.h"
using namespace std;

Elementas::Elementas() : duom(Mokslininkai()), pirmyn(NULL), atgal(NULL) {}
Elementas::~Elementas() {}
void Elementas::DetiDuom(Mokslininkai x) { duom = x; }
void Elementas::DetiPirmyn(Elementas * p) { pirmyn = p; }
void Elementas::DetiAtgal(Elementas *a) { atgal = a; }
Mokslininkai Elementas::ImtiDuom() {return duom; }
Elementas * Elementas::ImtiPirmyn() {return pirmyn; }
Elementas * Elementas::ImtiAtgal() {return atgal; }
