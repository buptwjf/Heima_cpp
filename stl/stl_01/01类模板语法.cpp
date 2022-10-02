#include <iostream>
#include <string>
using namespace std;

/*
	��ģ��
		�﷨�� 
		template <class T>
		class xxx
*/

template <class NameType, class AgeType>
class Person
{
public:

	// ���캯��
	Person(NameType name, AgeType age) : Name(name), Age(age) {}

	void Show()
	{
		cout << "name: " << Name << "\tage: " << Age << endl;
	}
private:
	NameType Name;
	AgeType Age;
};


void test_01()
{
	// ָ��NameType����, AgeType����
	Person<string, int> p1("����", 999);
	p1.Show();
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}