#include <iostream>
using namespace std;

/*
	1. 模板的语法
		template <typename T>
	2. 模板的实现
		a. 自动类型推导
		b. 显示制定类型
	3. 注意事项
		a. 自动类型推导，必须推导出一致的数据类型T,才可以使用
		b. 模板必须要确定出T的数据类型，才可以使用
*/

// 使用模板
template <typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


void test_01()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Swap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main()
{
	test_01();
	system("pause");
	system("cls");
	return 0;
}