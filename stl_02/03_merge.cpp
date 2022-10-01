#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	两个容器元素合并，并存储到另一容器中
*/

class MyPrint
{
public:
	void operator()(int val)
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
		v2.push_back(i + 1);
	}

	vector<int> target;
	
	// 开辟好空间
	target.resize(v1.size() + v2.size());

	// 合并
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());

	for_each(target.begin(), target.end(), MyPrint());
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}