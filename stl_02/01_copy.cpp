#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	copy(iterator beg, iterator end, iterator dest);
	需要对目标容器设定容量
*/

class MyPrint
{
public:
	void operator () (int val)
	{
		cout << val << " ";
	}
};

void test_01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), MyPrint());
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}