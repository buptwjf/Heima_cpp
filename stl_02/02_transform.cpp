#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>


/*
	transform(iterator beg1, iterator end1, iterator beg2, _func)
	执行完 _func 后再进行搬运
*/

class Transform
{
public:
	int operator() (int v)
	{
		return v + 100 ;
	}
};

class MyPrint
{
public:
	void operator() (int v)
	{
		cout << v << " ";
	}
};

void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 目标容器
	vector<int> target;

	// 目标容器需要提前的开辟空间
	target.resize(v.size());

	transform(v.begin(), v.end(), target.begin(), Transform());

	for_each(target.begin(), target.end(), MyPrint());

}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}