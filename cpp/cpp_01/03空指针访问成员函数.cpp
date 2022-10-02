#include <iostream>
using namespace std;

/*
	空指针调用成员函数
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
		if (this == NULL)  // 防止空指针调用成员变量，增加代码健壮性
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

