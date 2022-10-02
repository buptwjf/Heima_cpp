#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
	set �����Զ���������������
*/

class Person
{
public:
	Person(string name, int age) :  m_Name(name), m_Age(age) {}
	string m_Name;
	int m_Age;
};

class ComparePerson
{
public:
	bool operator()  (const Person& p1, const Person& p2) const  // �������� cosnt????? 
	{
		// ����������н�������
		return p1.m_Age > p2.m_Age;
	}
};
void test_01()
{
	set<Person, ComparePerson> s;

	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "����: " << it->m_Name << "����: " << it->m_Age << endl;
	}
}

int main()
{
	test_01();
	system("pause");
	return 0;
}