#include <iostream>
using namespace std;

/*
	�������캯���ĵ���ʱ��
	1. ʹ���Ѵ����Ķ�������ʼ��һ���¶���
		ע�⣺ֱ�Ӹ�ֵ�������ǿ�������
	2. ��ֵ���ݵķ�ʽ��������ֵ
	3. ��ֵ��ʽ���ؾֲ�����
*/

class Person
{
public:
	// Ĭ�Ϲ��캯�����޲ι��캯����
	Person(){
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	// �вι��캯��
	Person(int a){
		age = a;
		cout << "�вι��캯��" << endl;
	}
	// �������캯��
	Person(const Person& p){
		age = p.age;
		cout << "�������캯��" << endl;
	}
	// ��������
	~Person(){
		cout << "��������" << endl;
	}
private:
	int age;
};

// 1. ʹ���Ѵ����Ķ�������ʼ��һ���¶���
void test_01()
{
	Person man(100);  // �вι��캯��
	Person newman(man);  // ���ÿ������캯��
	Person newman2 = man;  // ��������

	Person newman3;  // Ĭ�Ϲ��캯��
	newman3 = man;  // ���ǿ�������
}


// 2. ��ֵ���ݵķ�ʽ��������ֵ��ʵ�θ��βε�ʱ�򣩣�ʹ��һ�ο�������
// �൱�� Person p1;
void doWork(Person pl) {}
void test_02()
{
	Person p;
	doWork(p);
}


// 3. ��ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;  // Ĭ�Ϲ��캯��
	cout << &p1 << endl;
	return p1;
}
void test_03()
{
	Person p = doWork2();  // �������캯��
	cout << &p << endl;
}

int main()
{
	test_01();
	cout << "----------------" << endl;
	test_02();
	cout << "----------------" << endl;
	test_03();
	system("pause");
	return 0;
}