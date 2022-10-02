#include <iostream>
using namespace std;
#include <string>
/*
	函数调用运算符重载：仿函数
*/

class MyPrint
{
public:

	// 重载函数调用运算符
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
	// 对象来使用重载后的小括号，对象就像一个函数名，因此叫做仿函数

	MyPrint02("hellow world");  // 使用函数来调用
}


// 仿函数非常灵活，没有固定的写法
// 加法类

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

	// 匿名函数对象
	cout << MyAdd()(100, 150) << endl;
}


int main()
{
	test_01();
	test02();
	system("pause");
	return 0;
}