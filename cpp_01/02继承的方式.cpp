#include <iostream>
using namespace std;
/*
	1. �����̳�
	2. �����̳�
	3. ˽�м̳�
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

class Son1 : public Base1
{
public:
	void func()
	{
		m_A = 10;  // ���๫�� -> ���๫��
		m_B = 10;  // ���ౣ�� -> ���ౣ��
		//m_C = 10;  // ����˽�� -> �����޷�ʹ��
	}
};

void test_01()
{
	Son1 s1;
	s1.m_A = 100;     // ������Է���
	// s1.m_B = 100;  // ���ⲻ���Է���  ���ౣ�� -> ������ m_B Ϊ˽��
	s1.func();
}


// �����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2
{
public: 
	void func()
	{
	m_A = 10;  // ���๫�� -> ���ౣ��
	m_B = 10;  // ���ౣ�� -> ���ౣ��
	//m_C = 10;  // ����˽�� -> �����޷�ʹ��
	}
};

void test_02()
{
	Son2 s2;
	// s2.m_A = 100;  // ���ⲻ���Է���  ���ౣ��
	// s2.m_B = 100;  // ���ⲻ���Է���  ���ౣ��
	s2.func();
}

// ˽�м̳�
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 : private Base3
{
public:
	void func()
	{
		m_A = 10;  // ���๫�� -> ����˽��
		m_B = 10;  // ���ౣ�� -> ����˽��
		// m_C = 10;  // ����˽�� -> �����޷�ʹ��
	}
};

class GrandSon : public Son3
{
public:
	void func()
	{
		// �� Son3 �� m_A, m_B Ϊ˽�У�GrandSon ���ɷ���
		// m_A = 100;
		// m_B = 100;
	}
};
void test_03()
{
	Son3 s3;
	// s2.m_A = 100;  // ���ⲻ���Է���  ����˽�� 
	// s2.m_B = 100;  // ���ⲻ���Է���  ����˽��
	s3.func();
}



int main()
{
	test_01();
	test_02();
	test_03();
	system("pause");
	return 0;
}