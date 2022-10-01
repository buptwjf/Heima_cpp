#include <iostream>
#include <string>
using namespace std;

/*
	1. ģ�岻�����ܣ�ֻ�ܴ���������������
	2. ģ������أ�����Ϊ��Щ�ض��������ṩ���廯��ģ��
		��������template<>��ͷ����ͨ�������β���ָ�����ͣ������ڳ���ģ��
*/


class Person
{
public:

	Person(string name, int age) : Name(name), Age(age) {}

	string Name;
	int Age;
};


// ��ͨ����ģ��
template <typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}


// ���廯����ģ��
// �������� Person ����
template <> bool myCompare(Person& a, Person& b)
{
	if (a.Age == b.Age && a.Name == b.Name)
		return true;
	else
		return false;
}


void test_01()
{
	// ��ͨ����ģ��
	int d = 10;
	int e = 20;
	if (myCompare(d, e))
		cout << "�������" << endl;
	else
		cout << "���߲���" << endl;

	cout << "*******************" << endl;

	// ���廯����ģ��
	Person a("����", 18);
	Person b("����", 20);
	Person c("����", 18);
	if (myCompare(a, b))
		cout << "�������" << endl;
	else
		cout << "���߲���" << endl;


	if (myCompare(a, c))
		cout << "�������" << endl;
	else
		cout << "���߲���" << endl;
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}