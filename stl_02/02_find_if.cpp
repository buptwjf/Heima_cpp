#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	find_if(iterator beg, iterator end, _Pred;  
	_Pred 函数或者谓词（返回bool的仿函数）
*/

// 1. 查找内置数据类型
class GreaterFive
{
public:
	bool operator() (int val)
	{
		return val > 5;
	}
};
void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
}


// 2. 查找自定义数据类型 
class Person
{
public:

	Person(string name,int age) : m_Name(name), m_Age(age) {}
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator() (const Person& p)
	{
		return p.m_Age > 20;
	}
};
void test_02()
{
	vector<Person> v;
	Person p1("aa", 10);
	Person p2("bb", 20);
	Person p3("cc", 30);
	Person p4("dd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	// 寻找年龄大于 20
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于20, 姓名：" << it->m_Name << "年龄：" << it->m_Age << endl;
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