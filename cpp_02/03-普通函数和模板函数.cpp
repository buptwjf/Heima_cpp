#include <iostream>
using namespace std;

/*
	普通函数：可以发生自动类型转换
	模板函数：
		1. 自动推导时： 不会发生隐式类型转换
		2. 指定类型时： 可以发生隐式类型转换
*/


// 普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

// 模板函数
template <typename T>
T myAdd02(T a, T b)
{
	return a + b;
}


void test_01()
{
	int a = 10;
	int b = 20;
	char c = 'a';

	// 普通函数发生自动类型转换
	cout << myAdd01(a, c) << endl;   // 107 将 'c' 转换为 97
	cout << int(c) << endl;

	// cout << myAdd02(a, c) << endl;  // 报错！自动推导时不会发生隐式类型转换
	cout << myAdd02<char>(a, c) << endl;  // 输出 'k' 不报错！ 指定类型时可以发生隐式类型转换
}

int main()
{
	
	test_01();
	system("pause");
	system("cls");
	return 0;
}