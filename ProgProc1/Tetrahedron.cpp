#include "Tetrahedron.h"
#include <fstream>
#include <cmath>
using namespace std;
void In(tetrahedron& b, ifstream& ifst)
{
	ifst >> b.a ;
	if (ifst.fail())
	{
		printf_s("Can't read a side of tetrahedron\n");
		exit(-1);
	}
	if (b.a <= 0)
	{
		printf_s("Negative a side of tetrahedron\n");
		exit(-1);
	}
}
void Out(tetrahedron& b, ofstream& ofst)
{
	ofst << "It is Tetrahedron: a = " << b.a ;
}
float volume(tetrahedron& p)
{
	return (p.a * p.a * p.a) * (sqrt(2) / 12);
}