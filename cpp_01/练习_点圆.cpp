#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"
//// ���������
//class Point
//{
//public:
//	// ��������
//	void setPointXY(float x, float y)
//	{
//		p_X = x;
//		p_Y = y;
//	}
//	// ��� X ����
//	float getX()
//	{
//		return p_X;
//	}
//	// ��� Y ����
//	float getY()
//	{
//		return p_Y;
//	}
//private:
//	float p_X;
//	float p_Y;
//};

// ����Բ����
//class Circle
//{
//public:
//	// ����Բ��
//	void setCenter(Point & center)
//	{
//		c_Center = center;
//	}
//	// ���ð뾶
//	void setR(float r)
//	{
//		radius = r;
//	}
//	// ��ȡԲ��
//	Point getCenter()
//	{
//		return c_Center;
//	}
//	// ��ȡ�뾶
//	float getR()
//	{
//		return radius;
//	}
//private:
//	Point c_Center;
//	float radius;
//};


// �жϵ��Բ֮��Ĺ�ϵ
void isInCircle(Point& p, Circle& c)
{
	float distance =
		((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
			(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()));
	float rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance < rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
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
	//c1.getCenter().setPointXY(10, 10);  // ������������
	p2.setPointXY(10, 10);
	c1.setCenter(p2);
	cout << c1.getCenter().getY() << endl;
	isInCircle(p1, c1);
	system("pause");
	return 0;
}