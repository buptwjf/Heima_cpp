#include <iostream>
using namespace std;
/*
	���캯���ĵ��ù���
*/

class Person
{
public:
	Person() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int a, int h) {
		age = a;
		height = new int(h);  // �ڶ�������һ���ڴ����������
		cout << "�вι��캯��" << endl;
	}
	// �������캯��
	Person(const Person& p) {
		age = p.age;
		// height = p.height;  // ������Ĭ�ϲ����� ǳ����
		height = new int(*p.height);  // ���������������һ���ռ�
		cout << "�������캯��" << endl;
	}
	// ��������
	~Person() {
		// ���������ٵ��������ͷŲ����������ÿ�
		if (height != NULL)
		{
			delete height;
			height = NULL;
		}
		cout << "��������" << endl;
	}
	int age;  // ����
	int* height;  // ���
private:
};


void test_01()
{
	Person p1(18, 160);
	cout << "p1������Ϊ�� " << p1.age << "���Ϊ��" << *p1.height << endl;
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.age << "���Ϊ��" << *p2.height << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}
