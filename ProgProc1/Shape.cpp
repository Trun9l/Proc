#include "Shape.h"
#include <fstream>
using namespace std;
void In(Ball& b, ifstream& ist);
void Out(Ball& b, ofstream& ofst);
void In(Parallelepiped& p, ifstream& ist);
void Out(Parallelepiped& p, ofstream& ofst);
void In(Tetrahedron& b, ifstream& ifst);
void Out(Tetrahedron& b, ofstream& ofst);
float Volume(Parallelepiped& p);
float Volume(Ball& b);
float Volume(Tetrahedron& p);
float Volume(Shape* s)
{
	switch (s->k) {
	case Shape::Key::BALL:
		return Volume(s->b);
	case Shape::Key::PARALLELEPIPED:
		return Volume(s->p);
	case Shape::Key::TETRAHEDRON:
		return Volume(s->t);
	default:
		return -1;
	}
}
// ¬вод параметров обобщенной фигуры из файла
Shape* InShape(ifstream& ifst)
{
	Shape* sp;
	int k;
	ifst >> k;
	switch (k)
	{
	case 1:
		sp = new Shape;
		sp->k = Shape::Key::BALL;
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->b, ifst);
		return sp;
	case 2:
		sp = new Shape;
		sp->k = Shape::Key::PARALLELEPIPED;
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->p, ifst);
		return sp;
	case 3:
		sp = new Shape;
		sp->k = Shape::Key::TETRAHEDRON;
		ifst >> sp->meltingPoint;
		ifst >> sp->density;
		In(sp->t, ifst);
		return sp;
	default:
		return 0;
	}
}
void OutShape(Shape* s, ofstream& ofst) 
{
	switch (s->k) 
	{
	case Shape::Key::BALL:
		Out(s->b, ofst);
		break;
	case Shape::Key::PARALLELEPIPED:
		Out(s->p, ofst);
		break;
	case Shape::Key::TETRAHEDRON:
		Out(s->t, ofst);
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
	ofst << ", density = " << s->density;
	ofst << ", melting temperature = " << s->meltingPoint << " ";
}