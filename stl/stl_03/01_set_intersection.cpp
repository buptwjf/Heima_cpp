#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

	1. 返回目标容器的最后一个元素的迭代器地址
	2. 新容器的长度 min(v1.size(), v2.size())
*/

class MyPrint
{
public:
	void operator() (int val)
	{
		cout << val << " ";
	}
};


void test_01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> target;
	target.resize(min(v1.size(), v2.size()));

	// 返回目标容器的最后一位元素的迭代器地址
	vector<int>::iterator itEnd =
		set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());

	for_each(target.begin(), itEnd, MyPrint());
}



int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}