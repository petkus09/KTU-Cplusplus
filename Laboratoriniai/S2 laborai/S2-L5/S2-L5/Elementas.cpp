#include "StdAfx.h"
#include "Elementas.h"

Elementas::Elementas(): duom(Studentas()), kitas(NULL) {}
Elementas::~Elementas() {}
//-----------------------------------------
void Elementas::DetiStudenta(Studentas x)
{
	duom = x;
}
//-----------------------------------------
Studentas Elementas::ImtiStudenta()
{
	return duom;
}
//-----------------------------------------
Elementas * Elementas::ImtiPirmyn()
{
	return kitas;
}
//-----------------------------------------
void Elementas::DetiPirmyn(Elementas * p)
{
	kitas = p;
}
//-----------------------------------------