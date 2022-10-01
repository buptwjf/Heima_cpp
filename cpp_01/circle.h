#pragma once
#include <iostream>
using namespace std;

#include "point.h"

class Circle
{
public:
	// 设置圆心
	void setCenter(Point& center);

	// 设置半径
	void setR(float r);

	// 获取圆心
	Point getCenter();

	// 获取半径
	float getR();

private:
	Point c_Center;
	float radius;
};
