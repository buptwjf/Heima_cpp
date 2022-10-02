#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	fill(iterator beg, iterator end, value); 
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
	vector<int> v;
	v.resize(10);

	// Моід
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint());
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}