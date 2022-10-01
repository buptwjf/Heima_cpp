#include <iostream>
#include <string>
using namespace std;

/*
	类模板
		语法： 
		template <class T>
		class xxx
*/

template <class NameType, class AgeType>
class Person
{
public:

	// 构造函数
	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	void Show()
	{
		cout << "name: " << Name << "\tage: " << Age << endl;
	}
private:
	NameType Name;
	AgeType Age;
};


void test_01()
{
	// 指定NameType类型, AgeType类型
	Person<string, int> p1("张三", 999);
	p1.Show();
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}