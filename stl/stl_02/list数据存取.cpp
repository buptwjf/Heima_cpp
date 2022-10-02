#include <iostream>
#include <list>
using namespace std;

/*
	* `front();`        //返回第一个元素。
	* `back();`         //返回最后一个元素。
*/

void test_01()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);


	//1. list 不支持 at 和[]
	//	原因 : List 本质上是一个列表
	cout << "L的第一个元素" << L.front() << endl;
	cout << "L的最后一个元素" << L.back() << endl;

	// 2. 迭代器也不能跳跃访问, 只能 ++ 或者 --
	list<int>::iterator it = L.begin();
	//it = it + 1;  不支持
	it++;  // 支持
	it--;  // 支持
}

int main()
{
	test_01();
	system("pause");
	return 0;
}