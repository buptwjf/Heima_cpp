#include <iostream>
using namespace std;
/*
	��������ص㣺
	1. �޷�ʵ��������
	2. ���������д������Ĵ��麯��������Ҳ���ڳ�����
	3. �﷨ 
		virtual ����ֵ���� ������ �������б� = 0
*/


class Base
{
public:
	// ���麯��
	// ����ֻҪ��һ�����麯���ͳ�Ϊ ������
	// �������޷�ʵ��������
	// ���������д����Ĵ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;

};

class Son : public Base
{
public:
	// ��д����Ĵ��麯��
	virtual void func()
	{
		cout << "func ����" << endl;
	}
};


void test_01()
{
	Base* base = new Son;  
	// ��̬�������ָ�룬�������
	base->func();
}


int main()
{
	test_01();
	system("pause");
	return 0;
}