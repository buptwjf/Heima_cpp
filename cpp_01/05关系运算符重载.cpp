#include <iostream>
#include <string>
using namespace std;
/*
	���ع�ϵ�����
*/

class Person
{
public:
	Person(string name, int age) : m_Name(name), m_Age(age) {}

	bool operator == (const Person& p)
	{
		if (m_Name == p.m_Name && m_Age == p.m_Age)
			return true;
		else
			return false;
	}

	bool operator != (const Person& p)
	{
		if (m_Name != p.m_Name || m_Age != p.m_Age)
			return true;
		else
			return false;
	}


	string m_Name;
	int m_Age;
};

void test_01()
{
	Person p1("����", 12);
	Person p2("����", 12);

	if (p1 == p2)
		cout << "p1��p2���" << endl;
	else
		cout << "p1��p2�����" << endl;
	
	cout << "*********" << endl;

	if (p1 != p2)
		cout << "p1��p2�����" << endl;
	else
		cout << "p1��p2���" << endl;
}


int main()
{
	test_01();
	system("pause");
	return 0;
}