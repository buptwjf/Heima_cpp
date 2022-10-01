#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
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
	// 取较大容器的空间
	target.resize(max(v1.size(), v2.size()));
	
	// v1 - v2
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), itEnd, MyPrint());

	// v2 - v1
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), target.begin());
	for_each(target.begin(), itEnd, MyPrint());
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}