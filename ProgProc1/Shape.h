#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include <fstream>
struct shape {
	// �������� ������ ��� ������ �� �����
	enum class key { BALL, PARALLELEPIPED };
	key k; // ����
	float density;
	int meltingPoint;
	// ������������ ������������
	union { // ���������� ���������
		ball b;
		parallelepiped p;
	};
};