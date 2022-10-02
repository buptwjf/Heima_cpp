#include <iostream>
using namespace std;

/*
	类模板和函数模板的区别：
	l. 类模板没有自动类型推导的使用机制
	2. 类模板在模板参数列表中可以有默认参数
*/

template <class NameType, class AgeType = int>
class Person
{
public:

	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	void ShowPerson()
	{
		cout << "name: " << Name << endl;
		cout << "age: " << Age << endl;
	}

	NameType Name;
	AgeType Age;
};


// 类模板没有自动类型推导的使用机制
void test_01()
{
	//Person p1("张三", 99);  // 错误，无法自动类型推导
	Person<string, int> p1("张三", 99);  // 正确
	p1.ShowPerson();
}

// 类模板在模板参数列表中可以有默认参数
void test_02()
{
	Person<string> p2("李四", 20.1);  // 将 20.1 -> 20
	p2.ShowPerson();
}

int main()
{
	test_01();

	cout << "**********" << endl;

	test_02();
	system("pause");
	system("cls");
	return 0;
}