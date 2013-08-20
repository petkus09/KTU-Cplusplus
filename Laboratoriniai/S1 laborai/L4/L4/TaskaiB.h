#include <iostream>
using namespace std;

class TaskaiB
{
private:
	string spalva;
	bool dalyvis;
public:
	TaskaiB();
	TaskaiB(string spalvaReiksme, bool dalyvisReiksme);
	~TaskaiB();
	string ImtiSpalva()        {return spalva; }
	void DetiSpalva(string a)  {spalva = a; }
	bool ImtiDalyvi()          {return dalyvis; }
	void DetiDalyvi(bool a)    {dalyvis = a; }
};