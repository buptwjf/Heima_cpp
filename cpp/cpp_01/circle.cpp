#include <iostream>
using namespace std;

#include "circle.h"

// 建立圆对象的成员函数的实现
// 设置圆心
void Circle::setCenter(Point& center)  // 添加 Circle 作用域
{
	c_Center = center;
}
// 设置半径
void Circle::setR(float r)
{
	radius = r;
}
// 获取圆心
Point Circle::getCenter()
{
	return c_Center;
}
// 获取半径
float Circle::getR()
{
	return radius;
}