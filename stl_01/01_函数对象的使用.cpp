#include <iostream>
#include <string>
using namespace std;

/*
	�������󣺷º���
	1. �����в����������з���ֵ
	2. �������Լ���״̬������һ�㺯���ĸ���
	3. ������Ϊ��������
*/


class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

class Myprint
{
public:
	Myprint() { this->count = 0; }
	void operator() (string test)
	{
		cout << test << endl;
		count++;  // ͳ�Ƶ��ô���
	}
	int count;
};


// 1. ����һ��ʹ��
void test_01()
{
	
	MyAdd myadd;
	cout << myadd(10, 10)<< endl;

}

// 2. �����������Լ���״̬
void test_02()
{
	Myprint myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	
	cout << "myprint�ĵ��ô���: " << myprint.count << endl;
}

// 3. �������������Ϊ��������
void doPrint(Myprint& mp, string test)
{
	mp(test);
}

void test_03()
{
	Myprint myprint;
	doPrint(myprint, "Hello c++");
}

int main()
{
	test_01();
	test_02();
	test_03();
	system("pause");
	return 0;
}