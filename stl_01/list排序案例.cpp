#include <iostream>
#include <list>
using namespace std;

/*
	�Զ���������������

	Ҫ��:
		1. ������ͬ��ʱ����߽���
		2. ��������
*/

class Person
{
public:
	Person(string name, int age, int height) : 
		m_Name(name), m_Age(age), m_Height (height) {}

	string m_Name;
	int m_Age;
	int m_Height;
};

void printList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������" << it->m_Name << " "
			<< "����" << it->m_Age << " "
			<< "���" << it->m_Height << endl;
	}
	cout << endl;
}


bool comparePerson(Person& p1, Person p2)
{
	if (p1.m_Age == p2.m_Age)  // ������ͬ
	{
		return p1.m_Height > p2.m_Height;  // ����߽���
	}
	else
	{
		return p1.m_Age < p2.m_Age;  // ����������
	}
}

void test_01()
{
	list<Person> L1;
	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);

	L1.push_back(p1);
	L1.push_back(p2);
	L1.push_back(p3);
	L1.push_back(p4);
	L1.push_back(p5);
	L1.push_back(p6);
	printList(L1);


	// ��ָ����������
	L1.sort(comparePerson);
	printList(L1);

}

int main()
{
	test_01();
	system("pause");
	return 0;
}