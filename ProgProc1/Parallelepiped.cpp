#include "Parallelepiped.h"
#include <fstream>
using namespace std;
void In(Parallelepiped& p, ifstream& ifst)
{
	ifst >> p.a >> p.b >> p.c;
}
void Out(Parallelepiped& p, ofstream& ofst)
{
	ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c;
}
float Volume(Parallelepiped& p)
{
	return p.a * p.b * p.c;
}