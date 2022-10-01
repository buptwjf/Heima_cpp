#include <iostream>
using namespace std;

/*
	��ģ���������ݲ����ķ�ʽ
	1. ָ�����������
	2. ��������ģ�廯
	3. ������ģ�廯
*/


// ��ģ��
template <class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	template<class T1, class T2>
	Person<T1, T2>::Person(T1 name, T2 age)
	{
	}

	void showPerson()
	{
		cout << "����:" << this->Name << "\t����" << this->Age << endl;
	}

private:
	NameType Name;
	AgeType Age;
};


// 1. ָ�����������
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

void test_01()
{
	Person <string, int> p("����", 18);
	printPerson1(p);
}


// 2. ��������ģ�廯
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "T1 ������Ϊ: " << typeid(T1).name() << endl;
	cout << "T2 ������Ϊ: " << typeid(T2).name() << endl;
	p.showPerson();
}

void test_02()
{
	Person <string, int> p("����", 20);
	printPerson2(p);
}


// 3. ������ģ�廯
template <class T>
void printPerson3(T& p)
{
	cout << "T������Ϊ: " << typeid(T).name() << endl;
	p.showPerson();
}

void test_03()
{
	Person <string, int> p("����", 30);
	printPerson3(p);
}

int main()
{
	test_01();
	test_02();
	test_03();
	system("pause");
	system("cls");
	return 0;
}