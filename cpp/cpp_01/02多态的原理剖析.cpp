#include <iostream>
using namespace std;
/*
	多态的内部原理： 父类内部发生变换
		1. 增加 vfptr 虚函数表指针
		2. vfptr 指向 vftable 虚函数表
		3. 当子类重写父类的虚函数，内部会换成子类的虚函数地址
*/

// 动物类
class Animal
{
public:
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

void test_02()
{
	cout << "sizeof(Animal): " << sizeof(Animal) << endl;  
	// 没有 virtual sizeof 为 1
	cout << "sizeof(Animal): " << sizeof(Cat) << endl;
	// 加上 virtual sizeof 为 4（64位电脑为8）子类重写的数量
}

int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}