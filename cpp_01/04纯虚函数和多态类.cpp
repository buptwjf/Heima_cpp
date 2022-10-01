#include <iostream>
using namespace std;
/*
	抽象类的特点：
	1. 无法实例化对象
	2. 子类必须重写抽象类的纯虚函数，否则也属于抽象类
	3. 语法 
		virtual 返回值类型 函数名 （参数列表） = 0
*/


class Base
{
public:
	// 纯虚函数
	// 类中只要有一个纯虚函数就称为 抽象类
	// 抽象类无法实例化对象
	// 子类必须重写父类的纯虚函数，否则也属于抽象类
	virtual void func() = 0;

};

class Son : public Base
{
public:
	// 重写父类的纯虚函数
	virtual void func()
	{
		cout << "func 调用" << endl;
	}
};


void test_01()
{
	Base* base = new Son;  
	// 多态，父类的指针，子类调用
	base->func();
}


int main()
{
	test_01();
	system("pause");
	return 0;
}