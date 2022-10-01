#include <iostream>
#include <string>
using namespace std;

/*
	类模板中成员函数类外实现时，需要加上模板参数列表
*/

template <class T1, class T2>
class Person 
{
public: 
	// 成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;

};

// 构造函数，类外实现
template <class T1, class T2>
Person <T1, T2> :: Person(T1 name, T2 age) : m_Name(name), m_Age(age) {}

// 成员函数，类外实现
template <class T1, class T2>
void Person <T1, T2> ::showPerson()
{
	cout << "姓名：" << this->m_Name << "年龄：" << this->m_Age << endl;
}

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