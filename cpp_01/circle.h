#pragma once
#include <iostream>
using namespace std;

#include "point.h"

class Circle
{
public:
	// ����Բ��
	void setCenter(Point& center);

	// ���ð뾶
	void setR(float r);

	// ��ȡԲ��
	Point getCenter();

	// ��ȡ�뾶
	float getR();

private:
	Point c_Center;
	float radius;
};
