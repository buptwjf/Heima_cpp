#include <iostream>
using namespace std;

/*
	��ģ���еĳ�Ա����������һ��ʼ�ʹ����ģ��ڵ���ʱ��ȥ����
*/

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template <class T>
class MyClass
{
public:

	T obj;
	// ��ģ��ĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������

	void fun1()	{ obj.showPerson1(); }

	void fun2() { obj.showPerson2(); }  
};

void test_01()
{
	MyClass<Person1> m;

	m.fun1();

	//m.fun2();  // showPerson2 ���� Person1 �ĳ�Ա��˵���������òŻ�ȥ������Ա����
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}