#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	一元谓词： 仿函数返回类型是 bool， 接受一个参数
*/

class GreatFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找容器中大于 5 的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreatFive()); // 匿名对象
	if (it == v.end())
	{
		cout << " 未找到！" << endl;
	}
	else
	{
		cout << "找到了！" << *it << endl;
	}
}

int main()
{
	test_01();
	system("pause");
	return 0;
}