#include <iostream>
using namespace std;

/*
	1. ģ����﷨
		template <typename T>
	2. ģ���ʵ��
		a. �Զ������Ƶ�
		b. ��ʾ�ƶ�����
	3. ע������
		a. �Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
		b. ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*/

// ʹ��ģ��
template <typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


void test_01()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Swap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}