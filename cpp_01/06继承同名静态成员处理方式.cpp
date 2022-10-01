#include <iostream>
using namespace std;
/*
	继承中的同名静态成员的处理方式
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


// 同名静态成员属性
void test_01()
{
	Son s;
	// 1. 通过对象访问
	cout << "Son 下的 m_A" << s.m_A << endl;
	cout << "Base 下的 m_A" << s.Base::m_A << endl;

	// 2. 通过类名访问
	cout << "通过类名访问 " << endl;
	cout << "Son 下的 m_A" << Son::m_A << endl;
	cout << "Base 下的 m_A" << Son::Base::m_A << endl;  
	/*
		注意：
		1. 第一个 :: 表示用类名的方式访问；
		2. 第二个 :: 表示 Base 作用域下
	*/
}

// 同名静态成员函数
void test_02()
{
	// 1. 通过对象访问
	Son s;
	s.func();
	s.Base::func();

	// 2. 通过类名访问
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