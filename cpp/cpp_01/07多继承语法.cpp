#include <iostream>
using namespace std;
/*
	多继承语法
	1. 语法：class 子类：继承方式 父类1 ，继承方式 父类2 
	2. 多继承容易产生成员同名的情况，可通过使用类名作用域可以区分调用哪一个基类的成员
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

	int m_A;  // 与 Base1 重名
	int m_B;
};

// 子类 继承Base1 和 Base2
// cl / d1 reportSingleClassLayoutSon "07多继承语法.cpp"
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
	// cout << s.m_A << endl;  // 二义性
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