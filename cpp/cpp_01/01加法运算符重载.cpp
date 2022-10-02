#include <iostream>
using namespace std;
/*
	�ӷ����������
	1. ��Ա����ʵ�� + ���������
	2. ȫ�ֺ���ʵ�� + ���������
*/

class Person
{
public:
	Person() {}
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	// ��Ա����ʵ�� + ��������أ�ֻҪ����һ������
	Person operator + (const Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

public:
	int m_A;
	int m_B;
};

// ȫ�ֺ���ʵ�� + ��������أ���Ҫ������������
//Person operator + (const Person& p1, const Person& p2)
//{
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// ��������أ����Է�����������
Person operator + (const Person& p1, int val)
{
	Person temp;
	temp.m_A = p1.m_A + val;
	temp.m_B = p1.m_B + val;
	return temp;  // ��Ϊ temp ����ʱ�ģ����Բ��ܷ�������
}

void test_01()
{
	Person p1(10, 20);
	Person p2(10, 20);
	Person p3 = p1 + p2;
	// �൱�� p1.operator+(p2);
	p1 = p1 + p2;
	cout << "p1.m_A " << p1.m_A << "\tp1.m_B: " << p1.m_B << endl;
	cout << "p3.m_A " << p3.m_A << "\tp3.m_B: " << p3.m_B << endl;
	
	p1 = p1 + 10;
	//p1 = 10 + p1; ����
	cout << "p1.m_A " << p1.m_A << "\tp1.m_B: " << p1.m_B << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}