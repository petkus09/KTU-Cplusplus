#pragma once
#include "Studentas.h"
using namespace std;

class Elementas
{
private:
	Studentas duom;
	Elementas * kitas;
public:
	Elementas();
	~Elementas();
	void DetiStudenta(Studentas x);
	Studentas ImtiStudenta();
	Elementas * ImtiPirmyn();
	void DetiPirmyn(Elementas * p);
};
