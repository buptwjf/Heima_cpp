#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
	queue �������б�������Ϊ
	queue ���ṩ������������֧���������
*/

class Person
{
public: 

	Person(string name, int age) : m_Name(name), m_Age(age) { }

	string m_Name;
	int m_Age;
};

void test_01()
{
	// ��������
	queue<Person> q;

	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳɮ", 800);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty())
	{
		// �����ͷԪ��
		cout << "��ͷԪ��--����: " << q.front().m_Name << " "
			<< "����" << q.front().m_Age << endl;

		cout << "��βԪ��--����: " << q.back().m_Name << " "
			<< "����" << q.back().m_Age << endl;
		cout << endl;

		// ������ͷԪ��
		q.pop();
	}

	cout << "���д�С: " << q.size() << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}