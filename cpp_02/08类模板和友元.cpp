#include <iostream>
using namespace std;
#include <string>

/*
	ȫ�ֺ�������Ԫ��
		1. ��������������ʵ�� -> ����
		2. ��������������ʵ�� -> ������
*/


// ��ǰ֪���� Person ��
template <class T1, class T2>
class Person;

// ��ǰ֪�������ȫ�ֺ����Ĵ���
template <class T1, class T2>
void printPerson2(Person<T1, T2> p);


template <class T1, class T2>
class Person
{
	// ȫ�ֺ���������ʵ��
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "����:" << p.Name << "\t����:" << p.Age << endl;
	}

	// ȫ�ֺ�������������
	friend void printPerson2<>(Person<T1, T2> p);  // ��Ҫ�ӿ�ģ��Ĳ����б�

public:
	Person(T1 name, T2 age) : Name(name), Age(age) {}

private:
	T1 Name;
	T2 Age;
};

// ȫ�ֺ���������ʵ��
// ��Ҫ�ñ�������ǰ֪��������ʵ��
template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "����ʵ��-����:" << p.Name << "\t����:" << p.Age << endl;
}


// ȫ�ֺ�������ʵ�ֲ���
void test_01()
{
	Person<string, int> p("Tom", 20);
	printPerson(p);
}


// ȫ�ֺ�������ʵ�ֲ���
void test_02()
{
	Person<string, int> p("Jerry", 20);
	printPerson2(p);
}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}