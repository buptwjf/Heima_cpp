#include <iostream>
using namespace std;
/*
	1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
	2. ����������������Է��ʵ�����ͬ����Ա
	3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������
*/

class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base �е� func" << endl;
	}

	// �����Ա����������
	void func(int a)
	{
		cout << a << endl;
	}
	int m_A;
};

class Son : public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	int m_A;

	void func()
	{
		cout << "Son �е� func" << endl;
	}
};

// ͬ���ĳ�Ա����
void test_01()
{
	Son son;
	cout << "m_A: " << son.m_A << endl;  // 200  ����ĳ�Ա
	cout << "m_A: " << son.Base::m_A << endl;  // 100 ����ĳ�Ա
}

// ͬ���ĳ�Ա����
void test_02()
{
	Son son;
	son.func();  // ����ĳ�Ա����
	son.Base::func();  // ����ĳ�Ա����
	
	// son.func(100);
	// ��������г��ָ���ͬ���ĳ�Ա�����������ͬ����Ա�����ظ����е�����ͬ����Ա
	// Ҳ��Ҫ��������
	son.Base::func(100);
}
int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}