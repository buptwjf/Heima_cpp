#include <iostream>
using namespace std;

#include "circle.h"

// ����Բ����ĳ�Ա������ʵ��
// ����Բ��
void Circle::setCenter(Point& center)  // ��� Circle ������
{
	c_Center = center;
}
// ���ð뾶
void Circle::setR(float r)
{
	radius = r;
}
// ��ȡԲ��
Point Circle::getCenter()
{
	return c_Center;
}
// ��ȡ�뾶
float Circle::getR()
{
	return radius;
}