#include <iostream>
#include <functional>
using namespace std;

/*
	内建函数对象：算数仿函数
*/

// negate 一元仿函数 取反
void test_01()
{
	negate<int> n;
	cout << n(50) << endl;
}

// plus
void test_02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}
int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}