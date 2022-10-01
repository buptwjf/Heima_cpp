#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	sort(iterator beg, iterator end, _Pred);
*/


void MyPrint(int val)
{
	cout << val << " ";
}

void test_01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	// 默认从小到大
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	// 从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}