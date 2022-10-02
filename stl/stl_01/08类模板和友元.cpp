#include <iostream>
using namespace std;
#include <string>

/*
	全局函数做友元：
		1. 类内声明，类内实现 -> 建议
		2. 类内声明，类外实现 -> 不建议
*/


// 提前知道有 Person 类
template <class T1, class T2>
class Person;

// 提前知道有这个全局函数的存在
template <class T1, class T2>
void printPerson2(Person<T1, T2> p);


template <class T1, class T2>
class Person
{
	// 全局函数，类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "姓名:" << p.Name << "\t年龄:" << p.Age << endl;
	}

	// 全局函数，类内声明
	friend void printPerson2<>(Person<T1, T2> p);  // 需要加空模板的参数列表

public:
	Person(T1 name, T2 age) : Name(name), Age(age) {}

private:
	T1 Name;
	T2 Age;
};

// 全局函数，类外实现
// 需要让编译器提前知道有类外实现
template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "类外实现-姓名:" << p.Name << "\t年龄:" << p.Age << endl;
}


// 全局函数类内实现测试
void test_01()
{
	Person<string, int> p("Tom", 20);
	printPerson(p);
}


// 全局函数类外实现测试
void test_02()
{
	Person<string, int> p("Jerry", 20);
	printPerson2(p);
}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}