//#include <iostream>
//using namespace std;

/*

*/

//template <class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//};


//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) : m_Name(name),m_Age(age) { }
//
//template <class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名: " << this->m_Name << "\t年龄：" << this->m_Age << endl;
//}



// 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到，编译的时候看不到成员函数
// 解决方式1：包含cpp源文件
// #include "Person.h"
#include "Person.cpp"

// 解决方式2：更推荐
// 将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include "Person.hpp"


void test_01()
{
	Person<string, int> p("张三", 18);
	p.showPerson();
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}