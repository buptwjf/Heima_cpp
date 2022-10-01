#include <iostream>
using namespace std;

/*
	������Ĭ���ṩ�� = ��ǳ��������������ݷ��ڶ�������ô�ͻ����
	�����Ҫ���� = ���أ��������
*/
class Person
{
public:
	Person(int age)
	{
		// ���������ݿ��ٵ�����
		m_Age = new int(age);
	}

	~Person()
	{
		m_Age != NULL;
		delete m_Age;  // ɾ�� m_Age ָ����ڴ�
		m_Age = NULL;
	}

	// ���ظ�ֵ�����
	Person& operator = (Person& p)  
	{
		// �������ṩ����ǳ����
		// m_Age = p.m_Age
		// ����ֵ Person& Ϊ��ʵ�� p3 = p2 = p1

		// Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;	
		}
		// �ڿ����µĿռ䣬�����
		m_Age = new int(*p.m_Age);
		return *this;
	}

	int* m_Age;
};

void test_01()
{
	Person p1(18);
	cout << "p1 ������Ϊ: " << *p1.m_Age << endl;
	Person p2(20);
	cout << "p2 ������Ϊ: " << *p2.m_Age << endl;

	p2 = p1;  // ��ֵ����
	// ��ǳ�������൱�ڰ� p1.m_Age �� p2.m_Age����ָ�빲ָͬ�������� 18 
	// ��˵�������������ʱ�򣬻���ڴ� delete ���Σ����±���
	cout << "p1 ������Ϊ: " << *p1.m_Age << endl;
	cout << "p2 ������Ϊ: " << *p2.m_Age << endl;
}

void test_02()
{
	Person p1(18);
	Person p2(20);
	Person p3(10);
	p3 = p2 = p1;
	cout << "p1 ������Ϊ: " << *p1.m_Age << endl;  // 18
	cout << "p2 ������Ϊ: " << *p2.m_Age << endl;  // 18
	cout << "p3 ������Ϊ: " << *p3.m_Age << endl;  // 18
}

int main()
{
	test_01();
	cout << "**************" << endl;
	test_02();
	system("pause");
	return 0;
}