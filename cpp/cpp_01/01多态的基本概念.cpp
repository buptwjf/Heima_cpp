#include <iostream>
using namespace std;
/*
	1. ��̬�ķ���
		��̬��̬: �������� �� ������������ھ�̬��̬�����ú�����
		��̬��̬: ��������麯��ʵ������ʱ��̬
	2. ��̬��̬�Ͷ�̬��̬������
		��̬��̬: ����׶�ȷ�������ĵ�ַ
		��̬��̬: ���н׶�ȷ�������ĵ�ַ
		��̬��̬����������
			1. �̳й�ϵ
			2. ����Ҫ��д������麯��
			3. ��д-> ��������  ������ �����б� ��ȫ��ͬ
			4. ʹ�ã� ��������ã�ָ�룩��ִ���������
*/

// ������
class Animal
{
public:
	// �麯��
	virtual void speak()
	{
		cout << "����˵��" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "Сè˵��" << endl;
	}
};


class Dog : public Animal
{
public:
	void speak()
	{
		cout << "С��˵��" << endl;
	}
};

// ִ��˵���ĺ���
// ����˵�������ڵ�ַ��󶨣��ڱ���׶�ȷ���˺����ĵ�ַ
// �����Ҫ��ַ��� -> virtual
void doSpeak(Animal& animal)  // ���������
{
	animal.speak();
}

void test_01()
{
	Cat cat;
	doSpeak(cat);  // �������

	Dog dog;
	doSpeak(dog);
}

int main()
{
	test_01();  // ����˵�� ���ڵ�ַ��󶨣��ڱ���׶�ȷ���˺����ĵ�ַ
	system("pause");
	return 0;
}