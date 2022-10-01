#pragma once
#include <iostream>;
using namespace std;

// 建立点对象的头文件
// 只需要成员函数的声明，不需要实现
class Point
{
public:
	// 设置坐标
	void setPointXY(float x, float y);

	// 获得 X 坐标
	float getX();

	// 获得 Y 坐标
	float getY();

private:
	float p_X;
	float p_Y;
};