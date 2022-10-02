#include <iostream>
#include <stack>
using namespace std;

/*
	1. 栈常用接口
	2. 栈不允许有遍历的行为
*/

void test_01()
{
	// 创建栈容器 
	stack<int> s;

	// 压栈
	s.push(10);
	s.push(20);
	s.push(30);

	cout << "栈的大小为：" << s.size() << endl;

	while (!s.empty())
	{
		// 输出栈顶元素
		cout << "栈顶元素" << s.top() << endl;
		// 弹出栈顶元素
		s.pop();
	}
	cout << "栈的大小为：" << s.size() << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}