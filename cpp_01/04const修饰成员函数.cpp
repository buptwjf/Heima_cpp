#include <iostream>
using namespace std;
/*
	������
	1. ��Ա�������const�����ǳ�Ϊ�������Ϊ������
	2. �����������޸ĳ�Ա����

	������
	1. �����޸ĳ�Ա���ԣ�mutable���⣩
	2. ������ֻ�ܵ��ó�����

*/

class Person
{
public:
	// this ָ��ı��ʣ�ָ�볣����ָ�򲻿ɸ���
	void showPerson() const  
	// �൱�� const Person * const this,Ҳ����thisָ��ָ���ֵҲ�ǳ���
	{
		// this-> m_A = 100;  // ����
		// this = NULL; ����
		this->m_B = 100;
	}

	void func() {}
	int m_A;
	mutable int m_B;  // mutable���εı���
private:

};

void test_01()
{
	Person p;
	p.showPerson();
}

void test_02()
{
	const Person p;  // �ڶ���ǰ�� const����Ϊ������
	
					 
	// p.m_A = 100; // �����޸�
	p.m_B = 100;    // ���޸�
	p.showPerson(); // �ɵ���
	//p.func();     // ���ɵ���

}
int main()
{
	test_01();
}