#include "Shape.h"
#include <fstream>
using namespace std;
void In(ball& b, ifstream& ist);
void Out(ball& b, ofstream& ofst);
void In(parallelepiped& p, ifstream& ist);
void Out(parallelepiped& p, ofstream& ofst);
// ¬вод параметров обобщенной фигуры из файла
shape* InShape(ifstream& ifst)
{
	shape* sp;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sp = new shape;
		sp->k = shape::key::BALL;
		ifst >> sp->density;
		In(sp->b, ifst);
		return sp;
	case 2:
		sp = new shape;
		sp->k = shape::key::PARALLELEPIPED;
		ifst >> sp->density;
		In(sp->p, ifst);
		return sp;
	default:
		return 0;
	}
}
void OutShape(shape* s, ofstream& ofst) {
	switch (s->k) {
	case shape::key::BALL:
		Out(s->b, ofst);
		ofst << ", density = " << s->density << endl;
		break;
	case shape::key::PARALLELEPIPED:
		Out(s->p, ofst);
		ofst << ", density = " << s->density << endl;
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
}