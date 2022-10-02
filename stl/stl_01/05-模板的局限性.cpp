#include <iostream>
#include <string>
using namespace std;

/*
	1. 模板不是万能，只能处理内置数据类型
	2. 模板的重载，可以为这些特定的类型提供具体化的模板
		做法：以template<>开头，并通过函数形参来指出类型，优先于常规模板
*/


class Person
{
public:

	Person(string name, int age) : Name(name), Age(age) {}

	string Name;
	int Age;
};


// 普通函数模板
template <typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}


// 具体化函数模板
// 用来处理 Person 类型
template <> bool myCompare(Person& a, Person& b)
{
	if (a.Age == b.Age && a.Name == b.Name)
		return true;
	else
		return false;
}


void test_01()
{
	// 普通函数模板
	int d = 10;
	int e = 20;
	if (myCompare(d, e))
		cout << "两者相等" << endl;
	else
		cout << "两者不等" << endl;

	cout << "*******************" << endl;

	// 具体化函数模板
	Person a("张三", 18);
	Person b("李四", 20);
	Person c("张三", 18);
	if (myCompare(a, b))
		cout << "两者相等" << endl;
	else
		cout << "两者不等" << endl;


	if (myCompare(a, c))
		cout << "两者相等" << endl;
	else
		cout << "两者不等" << endl;
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}