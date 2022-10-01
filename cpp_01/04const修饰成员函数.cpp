#include <iostream>
using namespace std;
/*
	常函数
	1. 成员函数后加const后我们称为这个函数为常函数
	2. 常函数不可修改成员属性

	常对象
	1. 不可修改成员属性（mutable除外）
	2. 常对象只能调用常函数

*/

class Person
{
public:
	// this 指针的本质：指针常量，指向不可更改
	void showPerson() const  
	// 相当于 const Person * const this,也就是this指针指向的值也是常量
	{
		// this-> m_A = 100;  // 错误
		// this = NULL; 错误
		this->m_B = 100;
	}

	void func() {}
	int m_A;
	mutable int m_B;  // mutable修饰的变量
private:

};

void test_01()
{
	Person p;
	p.showPerson();
}

void test_02()
{
	const Person p;  // 在对象前加 const，变为常对象
	
					 
	// p.m_A = 100; // 不可修改
	p.m_B = 100;    // 可修改
	p.showPerson(); // 可调用
	//p.func();     // 不可调用

}
int main()
{
	test_01();
}