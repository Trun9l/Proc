#include "Parallelepiped.h"
#include <fstream>
using namespace std;
void In(parallelepiped& p, ifstream& ifst)
{
	ifst >> p.a;
	if (ifst.fail())
	{
		printf_s("Can't read a side of parallelepiped\n");
		exit(-1);
	}
	if (p.a <= 0)
	{
		printf_s("Negative a side of parallelepiped\n");
		exit(-1);
	}
	ifst >> p.b;
	if (ifst.fail())
	{
		printf_s("Can't read b side of parallelepiped\n");
		exit(-1);
	}
	if (p.b <= 0)
	{
		printf_s("Negative b side of parallelepiped\n");
		exit(-1);
	}
	ifst >> p.c;
	if (ifst.fail())
	{
		printf_s("Can't read c side of parallelepiped\n");
		exit(-1);
	}
	if (p.c <= 0)
	{
		printf_s("Negative c side of parallelepiped\n");
		exit(-1);
	}
}
void Out(parallelepiped& p, ofstream& ofst)
{
	ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c;
}
float volume(parallelepiped& p)
{
	return p.a * p.b * p.c;
}