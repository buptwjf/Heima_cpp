#include <iostream>
using namespace std;
#include <string>
/*
	����������������أ��º���
*/

class MyPrint
{
public:

	// ���غ������������
	void operator () (string test)
	{
		cout << test << endl;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

void test_01()
{
	MyPrint myPrint;
	myPrint("hellow world");  
	// ������ʹ�����غ��С���ţ��������һ������������˽����º���

	MyPrint02("hellow world");  // ʹ�ú���������
}


// �º����ǳ���û�й̶���д��
// �ӷ���

class MyAdd
{
public:

	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	// ������������
	cout << MyAdd()(100, 150) << endl;
}


int main()
{
	test_01();
	test02();
	system("pause");
	return 0;
}