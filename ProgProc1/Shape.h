#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include <fstream>
struct shape {
	// значения ключей для каждой из фигур
	enum class key { BALL, PARALLELEPIPED, TETRAHEDRON	};
	key k; // ключ
	float density;
	// используемые альтернативы
	union { // используем включение
		ball b;
		parallelepiped p;
		tetrahedron t;
	};
};