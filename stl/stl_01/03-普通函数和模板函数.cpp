#include <iostream>
using namespace std;

/*
	��ͨ���������Է����Զ�����ת��
	ģ�庯����
		1. �Զ��Ƶ�ʱ�� ���ᷢ����ʽ����ת��
		2. ָ������ʱ�� ���Է�����ʽ����ת��
*/


// ��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}

// ģ�庯��
template <typename T>
T myAdd02(T a, T b)
{
	return a + b;
}


void test_01()
{
	int a = 10;
	int b = 20;
	char c = 'a';

	// ��ͨ���������Զ�����ת��
	cout << myAdd01(a, c) << endl;   // 107 �� 'c' ת��Ϊ 97
	cout << int(c) << endl;

	// cout << myAdd02(a, c) << endl;  // �����Զ��Ƶ�ʱ���ᷢ����ʽ����ת��
	cout << myAdd02<char>(a, c) << endl;  // ��� 'k' ������ ָ������ʱ���Է�����ʽ����ת��
}

int main()
{
	
	test_01();
	system("pause");
	system("cls");
	return 0;
}