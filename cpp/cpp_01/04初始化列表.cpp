#include<iostream>
using namespace std;

// ��ʼ���б�
class Person
{
public:
	// ��ͳ��ʼ������
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	// ��ʼ���б�
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)  // ע�� : ��λ��
	{

	}
	~Person()
	{
		cout << "��������" << endl;
	}

	int m_A;
	int m_B;
	int m_C;

private:

};

void test_01()
{
	//Person p(10, 20, 30);
	Person p(30, 20, 10);
	cout << "m_A " << p.m_A << endl;
	cout << "m_B " << p.m_B << endl;
	cout << "m_C " << p.m_C << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}

