#include <iostream>
using namespace std;

// ��Ա�����ͳ�Ա�����ֿ��洢

class Person
{
public:
	int m_A;  // �Ǿ�̬��Ա������������Ķ�����
	//int m_C;
	static int m_B;  // ��̬��Ա��������������Ķ�����

	void fun() {}  // �Ǿ�̬��Ա����, ��������Ķ�����

	static void func2() {}  // ��̬��Ա����, ��������Ķ�����
private:
	
};

int Person::m_B = 10;



void test_01()
{
	Person p;
	/*
		1. û���κγ�Ա����ʱ���ն���ռ�õ��ڴ�ռ�Ϊ: 1 �ֽ�
		2. C++���������ÿ���ն������һ���ֽڣ�Ϊ�����ֿն���ռ�ڴ��λ�á�
		3. ÿ���ն�����һ����һ�޶����ڴ��ַ
	*/
	//cout << "size of p: " << sizeof(p) << endl;
	
	/*
		���� int m_A
		1. �ն���ռ�õ��ڴ�ռ�Ϊ: 4 �ֽ�
	*/
	//cout << "size of p: " << sizeof(p) << endl;

	/*
		���� static int m_B;
		1. �ն���ռ�õ��ڴ�ռ�Ϊ: 4 �ֽ�
	*/
	//cout << "size of p: " << sizeof(p) << endl;

	/*
		���� void fun() �Ǿ�̬��Ա����
		1. �ն���ռ�õ��ڴ�ռ�Ϊ: 4 �ֽڣ���ռ�ô洢�ռ�
	*/
	cout << "size of p: " << sizeof(p) << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}