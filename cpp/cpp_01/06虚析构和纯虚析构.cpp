#include <iostream>
#include <string>
using namespace std;
/*
	�������봿������
		1. ���������������������޷�����������
			virtual ~Animal()
		2. ��������
			virtual ~Animal() = 0: 
			�����޷��������ⲿ����
			ԭ�򣺴���������Ҫ������Ҳ��Ҫʵ�֣�
		3. ���� �������� ֮�������Ҳ���ɳ����࣬�޷�ʵ��������
		4. ���������û�ж������ݣ����Բ�дΪ��������������
*/


class Animal
{
public:

	Animal()
	{
		cout << "Animal �Ĺ���" << endl;
	}
	// ���麯��
	virtual void speak() = 0;

	// ������
	//virtual ~Animal()
	//{
	//	cout << "Animal ������" << endl;
	//}

	// ��������
	virtual ~Animal() = 0;
};

Animal :: ~Animal()
{
	cout << "Animal �Ĵ�����������" << endl;
}

class Cat : public Animal
{
public:
	
	Cat(string name)
	{
		m_Name = new string(name);
		cout << "Cat�Ĺ���" << endl;
	}
	virtual void speak()
	{
		cout << *m_Name << "è��˵��" << endl;
	}

	~Cat()
	{
		if (m_Name != NULL)
			delete m_Name;
		cout << "Cat������" << endl;
	}
	string* m_Name;
};


void test_01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	// �����ָ��������ʱ�򣬲��������������������������������������û��delet���������ڴ�й¶
	// ��� �Ѹ���� ���� -> ������
	delete animal;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}