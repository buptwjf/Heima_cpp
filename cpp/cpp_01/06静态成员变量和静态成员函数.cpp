#include <iostream>
using namespace std;

class Person
{
public:

	static int m_A;  // 静态成员变量
	int m_C;         // 非静态成员变量
	/*
		静态成员变量的特点
		1. 在编译阶段分配内存
		2. 类内声明，类外初始化
		3. 所有对象共享一份数据

		静态成员函数的特点
		1. 静态成员函数，只能访问静态成员变量
	*/ 

	static void fun()
	{
		cout << "fun 调用" << endl;
		m_A = 1000;
		m_B = 1000;
		//m_C = 1000;  
	}
private:
	static int m_B;  // 静态成员变量也有权限  错误，不可以访问非静态成员变量
};

int Person::m_A = 10;
int Person::m_B = 10;

void test_01()
{
	/*
		静态成员变量两种访问方式
		1. 通过对象
		2. 通过类名
	*/
	Person p1;
	cout << "p1.m_A = " << p1.m_A << endl;
	p1.m_A = 100;
	Person p2;

	// 1. 通过对象
	cout << "p1.m_A = " << p1.m_A << endl;
	cout << "p2.m_A = " << p2.m_A << endl;  // 共享同一份数据
	// 2. 通过类名
	cout << "m_A" << Person::m_A << endl;
	//cout << "m_B" << Person::m_B << endl;  // 私有，不可访问

	/*
		静态成员函数
	*/
	p1.fun();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}