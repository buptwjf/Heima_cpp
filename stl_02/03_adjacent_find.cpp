#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	adjacent_find(iterator beg, iterator end)
		查找相邻重复的元素，返回相邻元素的第一个位置的迭代器
		如果未找到，返回 end()
*/

void test_01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);

	// 查找相邻的元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到相邻重复的元素为" << *it << endl;
	}

}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}