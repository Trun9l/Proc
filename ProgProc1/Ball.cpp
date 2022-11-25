#include "Ball.h"
#include <fstream>
using namespace std;
void In(ball& b, ifstream& ifst)
{
	ifst >> b.r ;
	if (ifst.fail())
	{
		printf_s("Can't read radius\n");
		exit(-1);
	}
	if (b.r <= 0)
	{
		printf_s("Negative radius\n");
		exit(-1);
	}
}
void Out(ball& b, ofstream& ofst)
{
	ofst << "It is Ball: r = "	<< b.r;
}
float volume(ball& b)
{
	float pi = 3.14;
	return (4 / 3) * pi * b.r * b.r;
}