#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	vector 是存储的一段连续的空间
*/


void MyPrint(int val)
{
	cout << val << endl;
}


void test_01()
{
	// 创建 vector 容器
	vector<int> v;

	// 向容器内放入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 初始迭代器
	vector<int>::iterator pBegin = v.begin();
	// 尾迭代器
	vector<int>::iterator pEnd = v.end();

	// 第一种遍历方式
	//while (pBegin != pEnd)
	//{
	//	cout << *pBegin << endl;
	//	pBegin++;
	//}

	// 第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	//cout << endl;

	// 第三种遍历
	// 利用 stl 提供的标准遍历算法 头文件 algorithm
	for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}