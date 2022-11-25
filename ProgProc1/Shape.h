#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include <fstream>
struct Shape
{
	// �������� ������ ��� ������ �� �����
	enum class Key { BALL, PARALLELEPIPED, TETRAHEDRON	};
	Key k; // ����
	float density;
	int meltingPoint;
	// ������������ ������������
	union
	{ // ���������� ���������
		Ball b;
		Parallelepiped p;
		Tetrahedron t;
	};
};