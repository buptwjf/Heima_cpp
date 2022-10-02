#include <iostream>
using namespace std;

// 成员变量和成员函数分开存储

class Person
{
public:
	int m_A;  // 非静态成员变量，属于类的对象上
	//int m_C;
	static int m_B;  // 静态成员变量，不属于类的对象上

	void fun() {}  // 非静态成员函数, 不属于类的对象上

	static void func2() {}  // 静态成员函数, 不属于类的对象上
private:
	
};

int Person::m_B = 10;



void test_01()
{
	Person p;
	/*
		1. 没有任何成员变量时：空对象占用的内存空间为: 1 字节
		2. C++编译器会给每个空对象分配一个字节，为了区分空对象占内存的位置。
		3. 每个空对象有一个独一无二的内存地址
	*/
	//cout << "size of p: " << sizeof(p) << endl;
	
	/*
		增加 int m_A
		1. 空对象占用的内存空间为: 4 字节
	*/
	//cout << "size of p: " << sizeof(p) << endl;

	/*
		增加 static int m_B;
		1. 空对象占用的内存空间为: 4 字节
	*/
	//cout << "size of p: " << sizeof(p) << endl;

	/*
		增加 void fun() 非静态成员函数
		1. 空对象占用的内存空间为: 4 字节，不占用存储空间
	*/
	cout << "size of p: " << sizeof(p) << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}