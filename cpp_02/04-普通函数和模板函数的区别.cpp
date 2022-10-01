#include <iostream>
using namespace std;

/*
	1. 类型对应时，优先普通函数
	2. 可使用空模板参数，强制调用函数模板
	3. 函数模板可产生更好的调用匹配时，调用函数模板
	4. 函数模板可以重载

	总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
*/


// 普通函数
void myPrint(int a, int b)
{
	cout << "普通函数调用" << endl;
}


// 模板函数
template <typename T>
void myPrint(T a, T b)
{
	cout << "调用的模板" << endl;
}


// 模板函数重载
template <typename T>
void myPrint(T a, T b, T c)
{
	cout << "模板函数重载" << endl;
}


void test_01()
{
	int a = 10;
	int b = 10;
	int c = 20;

	// 普通函数
	myPrint(a, b);

	// 模板函数
	myPrint<>(a, b);

	// 模板函数重载
	myPrint(a, b, c);
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}