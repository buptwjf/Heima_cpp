#include <iostream>
#include <string>
using namespace std;

// 类对象作为类成员
class Phone
{
public:
	Phone(string pName)
	{
		m_pName = pName;  // 必须有Phone的有参数构造函数
		cout << "Phone 的构造函数" << endl;
	}

	string m_pName;
	~Phone() {
		cout << "Phone的析构函数" << endl;
	}
};

class Person
{
public:
	// 下一行相当于：Phone m_Phone = pName; 隐身转化法
	Person(string name, string pName): m_Name(name), m_Phone(pName)  //先构造Phone，再构造Person
	{
		cout << "Person 的构造函数" << endl;
	}
	~Person() {
		cout << "Person的析构函数" << endl;  // 先析构 Person，再析构 Phone
	}

	// 姓名
	string m_Name;
	Phone m_Phone;
};

void test_01()
{
	Person p("张三", "iphone max");
	cout << p.m_Name << "拿着" << p.m_Phone.m_pName << "手机" << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}