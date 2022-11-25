#include "Tetrahedron.h"
#include <fstream>
#include <cmath>
using namespace std;
void In(Tetrahedron& b, ifstream& ifst)
{
	ifst >> b.a ;
}
void Out(Tetrahedron& b, ofstream& ofst)
{
	ofst << "It is Tetrahedron: a = " << b.a ;
}
float Volume(Tetrahedron& p)
{
	return (p.a * p.a * p.a) * (sqrt(2) / 12);
}