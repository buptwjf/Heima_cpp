#include <iostream>
using namespace std;

// 1. ���幹�캯��
class Person
{
public:
	// Ĭ�Ϲ��캯�����޲ι��캯����
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	// �вι��캯��
	Person(int a)
	{
		age = a;
		cout << "�вι��캯��" << endl;
	}
	// �������캯��
	Person(const Person& p)
	{
		age = p.age;
		cout << "�������캯��" << endl;
	}
	// ��������
	~Person()
	{
		cout << "��������" << endl;
	}

private:
	int age;
};

// 2. ���캯���ĵ���
// �����޲ι��캯��
void test_01()
{
	Person p;  // Ĭ�Ϲ��캯�����������ţ��������Ϊ�Ǻ�������
}

// �����вεĹ��캯��
void test_02()
{
	// 2.1 ���ŷ�
	cout << "------���ŷ�-------" << endl;
	Person p1(10);  // �вι���
	Person p2(p1);  // ��������
	cout << "-------------------" << endl;
	// ע�� 1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
	// Person p2();
	// ע�� 2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ��� p1 ������
	// Person(p1); 


	// 2.2 ��ʾ��
	cout << "------��ʾ��-------" << endl;
	p2 = Person(10);         // �вι���
	Person p3 = Person(p2);  // ��������
	cout << "-------------------" << endl;
	// ע�� 3��Person(10) ����д������������û��������ǰ�н����󣬻����Ͻ�������


	// 2.3 ��ʽת����
	cout << "------��ʽת����-------" << endl;
	Person p4 = 10;  // �вι���
	Person p5 = p4;  // ��������
	// ע�� 4���� Person p4 = Person(10);  Person p5 = Person(p4); �ȼۣ�����û�� Person(10)����������
	cout << "-----------------------" << endl;
}

int main()
{
	test_01();
	cout << "******************" << endl;
	test_02();
	system("pause");
	return 0;
}