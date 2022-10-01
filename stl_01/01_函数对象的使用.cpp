#include <iostream>
#include <string>
using namespace std;

/*
	函数对象：仿函数
	1. 可以有参数，可以有返回值
	2. 可以有自己的状态，超出一般函数的概念
	3. 可以作为参数传递
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
		count++;  // 统计调用次数
	}
	int count;
};


// 1. 像函数一样使用
void test_01()
{
	
	MyAdd myadd;
	cout << myadd(10, 10)<< endl;

}

// 2. 函数对象有自己的状态
void test_02()
{
	Myprint myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	
	cout << "myprint的调用次数: " << myprint.count << endl;
}

// 3. 函数对象可以作为参数传递
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