#include <iostream>
using namespace std;

class MyInteger
{
	//friend void test_01();
	friend ostream& operator << (ostream& cout, const MyInteger& myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}

	// ����ǰ�� ++ �����
	MyInteger & operator ++ ()  
	// Ҫ�� & ��ֹ���� ++(++a) �ڶ��� ++ ʧЧ��һֱ��һ�����ݽ��е�������
	{
		// �Ƚ��� ++ ����
		m_Num++;
		// �ٽ�������
		return *this;
	}

	// ���غ��� ++ �����
	MyInteger operator ++ (int)  // ռλ��������������ǰ�úͺ��õ���,������ int
	{
		// �ȼ�¼һ�µ�ʱ�Ľ��
		MyInteger temp = *this;
		// �����
		m_Num ++;
		// ��󽫼�¼�Ľ������
		return temp;
		// ���ܷ������ã���Ϊ���ص��Ǿֲ������ֵ
	}

private:
	int m_Num;
};


// ���� << �������������Ϊ��Ա������cout ���������
ostream& operator << (ostream & cout, const MyInteger & myint)
{
	cout << myint.m_Num;
	return cout;
}


void test_01()
{
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;
	cout << myint << endl;
}


void test_02()
{
	MyInteger myint;
	cout << myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
}



int main()
{
	test_01();
	cout << "***********" << endl;
	test_02();
	system("pause");
	return 0;
}