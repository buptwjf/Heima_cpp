#include <iostream>
using namespace std;

/*
	1. ���Ͷ�Ӧʱ��������ͨ����
	2. ��ʹ�ÿ�ģ�������ǿ�Ƶ��ú���ģ��
	3. ����ģ��ɲ������õĵ���ƥ��ʱ�����ú���ģ��
	4. ����ģ���������

	�ܽ᣺��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
*/


// ��ͨ����
void myPrint(int a, int b)
{
	cout << "��ͨ��������" << endl;
}


// ģ�庯��
template <typename T>
void myPrint(T a, T b)
{
	cout << "���õ�ģ��" << endl;
}


// ģ�庯������
template <typename T>
void myPrint(T a, T b, T c)
{
	cout << "ģ�庯������" << endl;
}


void test_01()
{
	int a = 10;
	int b = 10;
	int c = 20;

	// ��ͨ����
	myPrint(a, b);

	// ģ�庯��
	myPrint<>(a, b);

	// ģ�庯������
	myPrint(a, b, c);
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}