#include <iostream>
using namespace std;
/*
	菱形继承（钻石继承）
	1. 加作用域避免二义性
	2. 使用虚基类，避免继承两份数据
*/


// 动物类
class Animal
{
public:
	int m_Age;
};


// 虚继承，解决菱形问题
// 继承前面加上 virtual
// 通过虚基类表的虚基类指针，使得 Sheep 和 Camel 都指向同一个数据
class Sheep : public virtual Animal {};

class Camel :public virtual Animal {};

class Alpca : public Sheep, public Camel {};

void test_01()
{
	Alpca al;
	// al.m_Age = 18;  // 多继承不明确

	// 当菱形继承时，两个父类有相同数据，需要加以作用域区分
	al.Sheep::m_Age = 18;
	al.Camel::m_Age = 20;

	cout << "al.Sheep::m_Age" << al.Sheep::m_Age << endl;
	cout << "al.Camel::m_Age" << al.Camel::m_Age << endl;

	// 如何避免数据有两份 -> 引入虚继承  virtual
	cout << "al.Sheep::m_Age" << al.Sheep::m_Age << endl;
	cout << "al.Camel::m_Age" << al.Camel::m_Age << endl;
	cout << "al.m_Age" << al.m_Age << endl;
}

void test_02()
{

}


int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}