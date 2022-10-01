#include <iostream>
using namespace std;

/*
	类模板向函数传递参数的方式
	1. 指定传入的类型
	2. 参数类型模板化
	3. 整个类模板化
*/


// 类模板
template <class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	template<class T1, class T2>
	Person<T1, T2>::Person(T1 name, T2 age)
	{
	}

	void showPerson()
	{
		cout << "姓名:" << this->Name << "\t年龄" << this->Age << endl;
	}

private:
	NameType Name;
	AgeType Age;
};


// 1. 指定传入的类型
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

void test_01()
{
	Person <string, int> p("张三", 18);
	printPerson1(p);
}


// 2. 函数参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "T1 的类型为: " << typeid(T1).name() << endl;
	cout << "T2 的类型为: " << typeid(T2).name() << endl;
	p.showPerson();
}

void test_02()
{
	Person <string, int> p("李四", 20);
	printPerson2(p);
}


// 3. 整个类模板化
template <class T>
void printPerson3(T& p)
{
	cout << "T的类型为: " << typeid(T).name() << endl;
	p.showPerson();
}

void test_03()
{
	Person <string, int> p("王五", 30);
	printPerson3(p);
}

int main()
{
	test_01();
	test_02();
	test_03();
	system("pause");
	system("cls");
	return 0;
}