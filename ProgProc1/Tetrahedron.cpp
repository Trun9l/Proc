#include "Tetrahedron.h"
#include <fstream>
using namespace std;
void In(tetrahedron& b, ifstream& ifst)
{
	ifst >> b.a ;
}
void Out(tetrahedron& b, ofstream& ofst)
{
	ofst << "It is Tetrahedron: a = " << b.a ;
}