#include "point.h"

// 建立点对象的成员函数的实现

// 设置坐标
void Point::setPointXY(float x, float y)  // 添加Point:: 作用域
{
	p_X = x;
	p_Y = y;
}
// 获得 X 坐标
float Point::getX()
{
	return p_X;
}
// 获得 Y 坐标
float Point::getY()
{
	return p_Y;
}