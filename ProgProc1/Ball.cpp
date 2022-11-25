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