#pragma once
#include <iostream>;
using namespace std;

// ����������ͷ�ļ�
// ֻ��Ҫ��Ա����������������Ҫʵ��
class Point
{
public:
	// ��������
	void setPointXY(float x, float y);

	// ��� X ����
	float getX();

	// ��� Y ����
	float getY();

private:
	float p_X;
	float p_Y;
};