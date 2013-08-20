#pragma once
#include "Mokslininkai.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class Elementas
{
private:
	Mokslininkai duom;
	Elementas *pirmyn;
	Elementas *atgal;
public:
	Elementas();
	~Elementas();
	void DetiDuom(Mokslininkai x);
	void DetiPirmyn(Elementas * p);
	void DetiAtgal(Elementas *a);
	Mokslininkai ImtiDuom();
	Elementas * ImtiPirmyn();
	Elementas * ImtiAtgal();
};
