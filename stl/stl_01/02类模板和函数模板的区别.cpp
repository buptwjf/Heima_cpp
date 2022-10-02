#include <iostream>
using namespace std;

/*
	��ģ��ͺ���ģ�������
	l. ��ģ��û���Զ������Ƶ���ʹ�û���
	2. ��ģ����ģ������б��п�����Ĭ�ϲ���
*/

template <class NameType, class AgeType = int>
class Person
{
public:

	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	void ShowPerson()
	{
		cout << "name: " << Name << endl;
		cout << "age: " << Age << endl;
	}

	NameType Name;
	AgeType Age;
};


// ��ģ��û���Զ������Ƶ���ʹ�û���
void test_01()
{
	//Person p1("����", 99);  // �����޷��Զ������Ƶ�
	Person<string, int> p1("����", 99);  // ��ȷ
	p1.ShowPerson();
}

// ��ģ����ģ������б��п�����Ĭ�ϲ���
void test_02()
{
	Person<string> p2("����", 20.1);  // �� 20.1 -> 20
	p2.ShowPerson();
}

int main()
{
	test_01();

	cout << "**********" << endl;

	test_02();
	system("pause");
	system("cls");
	return 0;
}