#include <iostream>
using namespace std;

/*
	�������̳е��Ǹ����һ����ģ�壬����������ʱ��
		1. ����Ҫָ������� T ����
		2. �����ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/


template <class T>
class Base
{
	T m;
};


//class Son : public Base  
// ���� c++������Ҫ����������ڴ棬����֪�������� T �����Ͳſ������¼̳�
class Son : public Base <int>
{
};


// ��ģ��̳���ģ�� ,������ T2 ָ�������е� T ����
template <class T1, class T2>
class Son2 : public Base <T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};


void test_01()
{
	Son c;
}

void test_02()
{
	Son2 <int, char> child;
}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}