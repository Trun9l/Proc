#include "Shape.h"
#include <fstream>
using namespace std;
void In(ball& b, ifstream& ist);
void Out(ball& b, ofstream& ofst);
void In(parallelepiped& p, ifstream& ist);
void Out(parallelepiped& p, ofstream& ofst);
void In(tetrahedron& b, ifstream& ifst);
void Out(tetrahedron& b, ofstream& ofst);
float volume(parallelepiped& p);
float volume(ball& b);
float volume(tetrahedron& p);
float volume(shape* s)
{
	switch (s->k) {
	case shape::key::BALL:
		return volume(s->b);
	case shape::key::PARALLELEPIPED:
		return volume(s->p);
	case shape::key::TETRAHEDRON:
		return volume(s->t);
	default:
		return -1;
	}
}
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
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->b, ifst);
		return sp;
	case 2:
		sp = new shape;
		sp->k = shape::key::PARALLELEPIPED;
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->p, ifst);
		return sp;
	case 3:
		sp = new shape;
		sp->k = shape::key::TETRAHEDRON;
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->t, ifst);
		return sp;
	default:
		return 0;
	}
}
void OutShape(shape* s, ofstream& ofst) {
	switch (s->k) {
	case shape::key::BALL:
		Out(s->b, ofst);
		break;
	case shape::key::PARALLELEPIPED:
		Out(s->p, ofst);
		break;
	case shape::key::TETRAHEDRON:
		Out(s->t, ofst);
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
	ofst << ", density = " << s->density;
	ofst << ", melting temperature = " << s->meltingPoint << " ";
}