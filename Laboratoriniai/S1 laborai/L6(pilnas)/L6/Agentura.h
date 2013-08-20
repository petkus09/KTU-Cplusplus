#pragma once
#include "Agentas.h"

class Agentura
{
private:
	int AgentuKiekis;
	Agentas A[10];
public:
	Agentura() {}
	~Agentura() {}
	void DetiAgenta(string a, string b, string c, string d, string e);
	void NuskaitymasA(string DuomFailas);
	void NuskaitymasB(string DuomFailas);
	void SpausdinimasIfaila(string RezFailas);
	void Rikiavimas();
	void RikiavimoSpausdinimas(string RezFailas);
	void MazaiDirbantysAgentai(string RezFailas);
	void VidurkinisSpausdinimas(Agentas M[], int Mkiekis, double vidurkis, string RezFailas, int r);
	};
