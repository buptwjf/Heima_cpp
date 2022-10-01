#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"
//// 建立点对象
//class Point
//{
//public:
//	// 设置坐标
//	void setPointXY(float x, float y)
//	{
//		p_X = x;
//		p_Y = y;
//	}
//	// 获得 X 坐标
//	float getX()
//	{
//		return p_X;
//	}
//	// 获得 Y 坐标
//	float getY()
//	{
//		return p_Y;
//	}
//private:
//	float p_X;
//	float p_Y;
//};

// 建立圆对象
//class Circle
//{
//public:
//	// 设置圆心
//	void setCenter(Point & center)
//	{
//		c_Center = center;
//	}
//	// 设置半径
//	void setR(float r)
//	{
//		radius = r;
//	}
//	// 获取圆心
//	Point getCenter()
//	{
//		return c_Center;
//	}
//	// 获取半径
//	float getR()
//	{
//		return radius;
//	}
//private:
//	Point c_Center;
//	float radius;
//};


// 判断点和圆之间的关系
void isInCircle(Point& p, Circle& c)
{
	float distance =
		((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
			(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()));
	float rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance < rDistance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

int main()
{
	Point p1,p2;
	p1.setPointXY(10.1, 10.1);
	p2.setPointXY(10, 0);
	Circle c1;
	c1.setCenter(p2);
	c1.setR(10);
	isInCircle(p1, c1);
	//c1.getCenter().setPointXY(10, 10);  // 不能这样设置
	p2.setPointXY(10, 10);
	c1.setCenter(p2);
	cout << c1.getCenter().getY() << endl;
	isInCircle(p1, c1);
	system("pause");
	return 0;
}