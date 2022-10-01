#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>


/*
	count_if(iterator beg, iterator end, _Pred)
		按条件统计元素出现次数，按照仿函数
*/

class Greater4
{
public:
	bool operator () (const int val)
	{
		return val > 4;
	}
};

// 内置数据类型
void test_01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于 4 的个数为" << num << endl;
}

// 自定义数据类型
class Person
{
public:
	Person(string name, int age): m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};

class AgeLess35
{
public:
	bool operator() (const Person& p)
	{
		return p.m_Age < 35;
	}	
};

void test_02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "年龄小于35的人数有 " << num << endl;
}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("clc");
	return 0;
}