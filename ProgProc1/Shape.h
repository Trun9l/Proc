#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include <fstream>
struct Shape
{
	// значения ключей для каждой из фигур
	enum class Key { BALL, PARALLELEPIPED, TETRAHEDRON	};
	Key k; // ключ
	float density;
	int meltingPoint;
	// используемые альтернативы
	union
	{ // используем включение
		Ball b;
		Parallelepiped p;
		Tetrahedron t;
	};
};