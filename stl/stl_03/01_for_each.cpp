#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	for_each(First, Last, Func)
*/

// 普通函数
void print01(int val)
{
	cout << val << " ";
}

// 仿函数
class print02
{
public:
	void operator() (int val)
	{
		cout << val << " ";
	}
};
void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 普通函数
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	// 仿函数
	for_each(v.begin(), v.end(), print02());
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}