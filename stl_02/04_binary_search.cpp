#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	bool binary_search(iterator beg, iterator end, value);  `
		查找指定的元素是否存在，查到返回 true，否则 false
		在无序的容器中不可用
*/

void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool flag = false;
	// 判断元素是否存在
	flag = binary_search(v.begin(), v.end(), 5);
	if (flag)
	{
		cout << "元素存在" << endl;
	}
	else
	{
		cout << "元素不存在 " << endl;
	}
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}