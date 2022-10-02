#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	replace(iterator beg, iterator end, oldvalue, newvalue)
	将区间内旧元素 替换成 新元素
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
	vector<int> v;

	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	
	cout << "代替前" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	// 将容器中的 20 换成 2000
	cout << "代替后" << endl;
	replace(v.begin(), v.end(), 20, 20000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}