#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>
#include <string>
/*
	count(iterator beg, iterator end, value); 
	ͳ��Ԫ�س��ֵĴ���
*/

class Person
{
public:
	Person(string name, int age) : m_Name(name), m_Age(age) {}

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

void test_01()
{
	vector<Person> v;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p("�����", 35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}