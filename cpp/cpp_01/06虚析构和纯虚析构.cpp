#include <iostream>
#include <string>
using namespace std;
/*
	虚析构与纯虚析构
		1. 利用虚析构解决子类对象无法析构的问题
			virtual ~Animal()
		2. 纯虚析构
			virtual ~Animal() = 0: 
			报错：无法解析的外部命令
			原因：纯虚析构需要声明，也需要实现，
		3. 有了 纯虚析构 之后，这个类也会变成抽象类，无法实例化对象
		4. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
*/


class Animal
{
public:

	Animal()
	{
		cout << "Animal 的构造" << endl;
	}
	// 纯虚函数
	virtual void speak() = 0;

	// 虚析构
	//virtual ~Animal()
	//{
	//	cout << "Animal 的析构" << endl;
	//}

	// 纯虚析构
	virtual ~Animal() = 0;
};

Animal :: ~Animal()
{
	cout << "Animal 的纯虚析构函数" << endl;
}

class Cat : public Animal
{
public:
	
	Cat(string name)
	{
		m_Name = new string(name);
		cout << "Cat的构造" << endl;
	}
	virtual void speak()
	{
		cout << *m_Name << "猫在说话" << endl;
	}

	~Cat()
	{
		if (m_Name != NULL)
			delete m_Name;
		cout << "Cat的析构" << endl;
	}
	string* m_Name;
};


void test_01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	// 父类的指针在析构时候，不会调用子类的析构函数，导致子类堆区的数据没有delet，出现了内存泄露
	// 解决 把父类的 析构 -> 虚析构
	delete animal;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}