#include "Ball.h"
#include <fstream>
using namespace std;
void In(ball& b, ifstream& ifst)
{
	ifst >> b.r ;
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