#include <iostream>
using namespace std;
/*
	���μ̳У���ʯ�̳У�
	1. ����������������
	2. ʹ������࣬����̳���������
*/


// ������
class Animal
{
public:
	int m_Age;
};


// ��̳У������������
// �̳�ǰ����� virtual
// ͨ��������������ָ�룬ʹ�� Sheep �� Camel ��ָ��ͬһ������
class Sheep : public virtual Animal {};

class Camel :public virtual Animal {};

class Alpca : public Sheep, public Camel {};

void test_01()
{
	Alpca al;
	// al.m_Age = 18;  // ��̳в���ȷ

	// �����μ̳�ʱ��������������ͬ���ݣ���Ҫ��������������
	al.Sheep::m_Age = 18;
	al.Camel::m_Age = 20;

	cout << "al.Sheep::m_Age" << al.Sheep::m_Age << endl;
	cout << "al.Camel::m_Age" << al.Camel::m_Age << endl;

	// ��α������������� -> ������̳�  virtual
	cout << "al.Sheep::m_Age" << al.Sheep::m_Age << endl;
	cout << "al.Camel::m_Age" << al.Camel::m_Age << endl;
	cout << "al.m_Age" << al.m_Age << endl;
}

void test_02()
{

}


int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}