#include <iostream>
using namespace std;
/*
	加法运算符重载
	1. 成员函数实现 + 运算符重载
	2. 全局函数实现 + 运算符重载
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

	// 成员函数实现 + 运算符重载，只要传递一个对象
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

// 全局函数实现 + 运算符重载，需要传递两个对象
//Person operator + (const Person& p1, const Person& p2)
//{
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// 运算符重载，可以发生函数重载
Person operator + (const Person& p1, int val)
{
	Person temp;
	temp.m_A = p1.m_A + val;
	temp.m_B = p1.m_B + val;
	return temp;  // 因为 temp 是临时的，所以不能返回引用
}

void test_01()
{
	Person p1(10, 20);
	Person p2(10, 20);
	Person p3 = p1 + p2;
	// 相当于 p1.operator+(p2);
	p1 = p1 + p2;
	cout << "p1.m_A " << p1.m_A << "\tp1.m_B: " << p1.m_B << endl;
	cout << "p3.m_A " << p3.m_A << "\tp3.m_B: " << p3.m_B << endl;
	
	p1 = p1 + 10;
	//p1 = 10 + p1; 不行
	cout << "p1.m_A " << p1.m_A << "\tp1.m_B: " << p1.m_B << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}