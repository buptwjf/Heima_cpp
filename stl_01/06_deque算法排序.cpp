#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
	sort(iterator beg, iterator end)  //对beg和end区间内元素进行排序
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
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	sort(d.begin(), d.end());
	printDeque(d);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}