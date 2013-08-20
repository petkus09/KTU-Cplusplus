#include <string>
#include "Leidinys.h"

using namespace std;

class Pajamos: public Leidinys
{
private:
	double uzdirbis;
public:
	Pajamos(void): Leidinys(), uzdirbis(0.0) {}
	Pajamos(string LeidinioKodas, string LeidinioPav, string LeidinioKaina, int LeidinioUzdirbis);
	~Pajamos(void) {}
	void DetiUzdirbi(int c) {uzdirbis = c; }
	int ImtiUzdirbi()       {return uzdirbis; }
};