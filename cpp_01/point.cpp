#include "point.h"

// ���������ĳ�Ա������ʵ��

// ��������
void Point::setPointXY(float x, float y)  // ���Point:: ������
{
	p_X = x;
	p_Y = y;
}
// ��� X ����
float Point::getX()
{
	return p_X;
}
// ��� Y ����
float Point::getY()
{
	return p_Y;
}