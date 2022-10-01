#include <iostream>
using namespace std;
/*
	��̬���ڲ�ԭ�� �����ڲ������任
		1. ���� vfptr �麯����ָ��
		2. vfptr ָ�� vftable �麯����
		3. ��������д������麯�����ڲ��ỻ��������麯����ַ
*/

// ������
class Animal
{
public:
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

void test_02()
{
	cout << "sizeof(Animal): " << sizeof(Animal) << endl;  
	// û�� virtual sizeof Ϊ 1
	cout << "sizeof(Animal): " << sizeof(Cat) << endl;
	// ���� virtual sizeof Ϊ 4��64λ����Ϊ8��������д������
}

int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}