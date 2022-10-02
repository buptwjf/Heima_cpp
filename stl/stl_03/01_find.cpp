#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>


/*
	find(iterator beg, iterator end, value);
	返回迭代器，或者end()
*/


// 查找内置的类型
void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找 是否有 5 这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 50);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
	
}

// 查找自定义的类型
class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age) {}

	bool operator == (const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test_02()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到, 姓名: " << it->m_Name << "年龄：" << it->m_Age << endl;
	}

}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("clc");
	return 0;
}