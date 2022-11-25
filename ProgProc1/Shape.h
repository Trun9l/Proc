#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include <fstream>
struct shape {
	// �������� ������ ��� ������ �� �����
	enum class key { BALL, PARALLELEPIPED, TETRAHEDRON	};
	key k; // ����
	float density;
	// ������������ ������������
	union { // ���������� ���������
		ball b;
		parallelepiped p;
		tetrahedron t;
	};
};