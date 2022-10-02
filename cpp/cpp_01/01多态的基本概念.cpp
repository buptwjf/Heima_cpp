#include <iostream>
using namespace std;
/*
	1. 多态的分类
		静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
		动态多态: 派生类和虚函数实现运行时多态
	2. 静态多态和动态多态的区别
		静态多态: 编译阶段确定函数的地址
		动态多态: 运行阶段确定函数的地址
		动态多态满足条件：
			1. 继承关系
			2. 子类要重写父类的虚函数
			3. 重写-> 返回类型  函数名 参数列表 完全相同
			4. 使用： 父类的引用（指针），执行子类对象
*/

// 动物类
class Animal
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "动物说话" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "小猫说话" << endl;
	}
};


class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗说话" << endl;
	}
};

// 执行说话的函数
// 动物说话，由于地址早绑定，在编译阶段确定了函数的地址
// 如果需要地址软绑定 -> virtual
void doSpeak(Animal& animal)  // 父类的引用
{
	animal.speak();
}

void test_01()
{
	Cat cat;
	doSpeak(cat);  // 子类调用

	Dog dog;
	doSpeak(dog);
}

int main()
{
	test_01();  // 动物说话 由于地址早绑定，在编译阶段确定了函数的地址
	system("pause");
	return 0;
}