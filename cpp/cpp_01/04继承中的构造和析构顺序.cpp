#include <iostream>
using namespace std;
/*
	父类和子类构造的顺序和析构的顺序
	父类构造 -> 子类构造 -> 子类析构 -> 父类析构
*/

class Base
{
public:
	Base()
	{
		cout << "Base构造函数" << endl;
	}

	~Base()
	{
		cout << "Base析构函数" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};

void test_01()
{
	Son s;
}


int main()
{
	test_01();
	system("pause");
	return 0;
}