#include <iostream>
using namespace std;
/*
	1. ���������еķǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	2. �����˽������ʱ�������������ˣ���˷��ʲ���
	3. ���ÿ�����Ա����鿴����ģ��
		��ת�̷� D:
		cd ������·����
		cl /d1 reportSingleClassLayout�鿴������ "�����ļ���.cpp"
*/

// �����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;  
};

class Son : public Base1
{
public:
	int m_D;
};


void test_01()
{
	cout << "sizeof Son " << sizeof(Son) << endl;  // Son ռ�� 16 ���ֽ�

}


int main()
{
	test_01();
	system("pause");
	return 0;
}