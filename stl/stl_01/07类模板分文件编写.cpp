//#include <iostream>
//using namespace std;

/*

*/

//template <class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//};


//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) : m_Name(name),m_Age(age) { }
//
//template <class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "����: " << this->m_Name << "\t���䣺" << this->m_Age << endl;
//}



// ��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ����������ʱ�򿴲�����Ա����
// �����ʽ1������cppԴ�ļ�
// #include "Person.h"
#include "Person.cpp"

// �����ʽ2�����Ƽ�
// ��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
#include "Person.hpp"


void test_01()
{
	Person<string, int> p("����", 18);
	p.showPerson();
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}