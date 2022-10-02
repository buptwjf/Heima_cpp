#include <iostream>
#include <deque>
using namespace std;

/*
	deque 的赋值操作和 vector 相同
	deque& operator=(const deque &deq);       //重载等号操作符
	assign(beg, end);                         //将[beg, end]区间中的数据拷贝赋值给本身。
	assign(n, elem);                          //将n个elem拷贝赋值给本身
*/

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n****************\n";
}

void test_01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	// 三种赋值方法
	deque<int> d2;
	d2 = d1;
	printDeque(d2);

	deque<int> d3;
	d3.assign(d2.begin(), d2.end());
	printDeque(d3);

	deque<int> d4;
	d4.assign(5, 100);
	printDeque(d4);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}