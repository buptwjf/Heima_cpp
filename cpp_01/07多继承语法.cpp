#include <iostream>
using namespace std;
/*
	��̳��﷨
	1. �﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2 
	2. ��̳����ײ�����Աͬ�����������ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
*/


class Base1
{
public:

	Base1()
	{
		m_A = 100;
	}

	int m_A = 100;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
		m_B = 200;
	}

	int m_A;  // �� Base1 ����
	int m_B;
};

// ���� �̳�Base1 �� Base2
// cl / d1 reportSingleClassLayoutSon "07��̳��﷨.cpp"
class Son : public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}

	int m_C;
	int m_D;
};
void test_01()
{
	Son s;
	cout << "sizeof(son) " << sizeof(s) << endl;
	// cout << s.m_A << endl;  // ������
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

void test_02()
{

}

int main()
{
	test_01();
	system("pause");
	return 0;
}