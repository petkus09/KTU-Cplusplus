#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	stringstream ss;
	ss << "asnfalfn" << "ASjnfskjfbn" ;
	for (int i = 0; i < 9; i++)
		ss << i;
	cout << ss.str();
	return 0;
}