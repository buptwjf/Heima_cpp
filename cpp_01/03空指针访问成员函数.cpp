#include <iostream>
using namespace std;

/*
	��ָ����ó�Ա����
*/
class Person
{
public:
	int m_Age;

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)  // ��ֹ��ָ����ó�Ա���������Ӵ��뽡׳��
			return;
		cout << "age" << this->m_Age << endl;
	}
private:

};


void test_01()
{
	Person* p = NULL;

	p->showClassName();

	p->showPersonAge();
}

int main()
{
	test_01();
}

