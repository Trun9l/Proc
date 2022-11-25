#include "Ball.h"
#include <fstream>
using namespace std;
void In(Ball& b, ifstream& ifst)
{
	ifst >> b.r ;
}
void Out(Ball& b, ofstream& ofst)
{
	ofst << "It is Ball: r = "	<< b.r;
}
float Volume(Ball& b)
{
	float pi = 3.14;
	return (4 / 3) * pi * b.r * b.r;
}