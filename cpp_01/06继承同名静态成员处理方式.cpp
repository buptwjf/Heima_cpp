#include <iostream>
using namespace std;
/*
	�̳��е�ͬ����̬��Ա�Ĵ���ʽ
*/


class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base -> func()" << endl;
	}
};

int Base::m_A = 100;

class Son : public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son -> func()" << endl;
	}
};

int Son::m_A = 200;


// ͬ����̬��Ա����
void test_01()
{
	Son s;
	// 1. ͨ���������
	cout << "Son �µ� m_A" << s.m_A << endl;
	cout << "Base �µ� m_A" << s.Base::m_A << endl;

	// 2. ͨ����������
	cout << "ͨ���������� " << endl;
	cout << "Son �µ� m_A" << Son::m_A << endl;
	cout << "Base �µ� m_A" << Son::Base::m_A << endl;  
	/*
		ע�⣺
		1. ��һ�� :: ��ʾ�������ķ�ʽ���ʣ�
		2. �ڶ��� :: ��ʾ Base ��������
	*/
}

// ͬ����̬��Ա����
void test_02()
{
	// 1. ͨ���������
	Son s;
	s.func();
	s.Base::func();

	// 2. ͨ����������
	Son::func();
	Son::Base::func();
}

int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}