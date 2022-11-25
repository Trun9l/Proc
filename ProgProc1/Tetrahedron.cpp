#include "Tetrahedron.h"
#include <fstream>
#include <cmath>
using namespace std;
void In(tetrahedron& b, ifstream& ifst)
{
	ifst >> b.a ;
}
void Out(tetrahedron& b, ofstream& ofst)
{
	ofst << "It is Tetrahedron: a = " << b.a ;
}
float volume(tetrahedron& p)
{
	return (p.a * p.a * p.a) * (sqrt(2) / 12);
}