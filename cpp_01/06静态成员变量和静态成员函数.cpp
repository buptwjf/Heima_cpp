#include <iostream>
using namespace std;

class Person
{
public:

	static int m_A;  // ��̬��Ա����
	int m_C;         // �Ǿ�̬��Ա����
	/*
		��̬��Ա�������ص�
		1. �ڱ���׶η����ڴ�
		2. ���������������ʼ��
		3. ���ж�����һ������

		��̬��Ա�������ص�
		1. ��̬��Ա������ֻ�ܷ��ʾ�̬��Ա����
	*/ 

	static void fun()
	{
		cout << "fun ����" << endl;
		m_A = 1000;
		m_B = 1000;
		//m_C = 1000;  
	}
private:
	static int m_B;  // ��̬��Ա����Ҳ��Ȩ��  ���󣬲����Է��ʷǾ�̬��Ա����
};

int Person::m_A = 10;
int Person::m_B = 10;

void test_01()
{
	/*
		��̬��Ա�������ַ��ʷ�ʽ
		1. ͨ������
		2. ͨ������
	*/
	Person p1;
	cout << "p1.m_A = " << p1.m_A << endl;
	p1.m_A = 100;
	Person p2;

	// 1. ͨ������
	cout << "p1.m_A = " << p1.m_A << endl;
	cout << "p2.m_A = " << p2.m_A << endl;  // ����ͬһ������
	// 2. ͨ������
	cout << "m_A" << Person::m_A << endl;
	//cout << "m_B" << Person::m_B << endl;  // ˽�У����ɷ���

	/*
		��̬��Ա����
	*/
	p1.fun();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}