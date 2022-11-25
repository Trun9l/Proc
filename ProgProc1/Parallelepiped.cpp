#include "Parallelepiped.h"
#include <fstream>
using namespace std;
void In(parallelepiped& p, ifstream& ifst)
{
	ifst >> p.a >> p.b >> p.c;
}
void Out(parallelepiped& p, ofstream& ofst)
{
	ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c;
}