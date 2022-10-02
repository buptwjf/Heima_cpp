#include <iostream>
using namespace std;
/*
	1. 子类对象可以直接访问到子类中同名成员
	2. 子类对象加作用域可以访问到父类同名成员
	3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
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
		cout << "Base 中的 func" << endl;
	}

	// 父类成员函数的重载
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
		cout << "Son 中的 func" << endl;
	}
};

// 同名的成员属性
void test_01()
{
	Son son;
	cout << "m_A: " << son.m_A << endl;  // 200  子类的成员
	cout << "m_A: " << son.Base::m_A << endl;  // 100 父类的成员
}

// 同名的成员函数
void test_02()
{
	Son son;
	son.func();  // 子类的成员函数
	son.Base::func();  // 父类的成员函数
	
	// son.func(100);
	// 如果子类中出现父类同名的成员函数，子类的同名成员会隐藏父类中的所用同名成员
	// 也需要加作用域
	son.Base::func(100);
}
int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}