#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include <fstream>
struct shape {
	// значения ключей для каждой из фигур
	enum class key { BALL, PARALLELEPIPED };
	key k; // ключ
	float density;
	int meltingPoint;
	// используемые альтернативы
	union { // используем включение
		ball b;
		parallelepiped p;
	};
};