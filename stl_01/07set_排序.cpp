#include <iostream>
#include <set>
using namespace std;

/*
	set 容器排序
*/

class MyCompare
{
public:
	bool operator() (int v1, int v2)
	{
		return v1 > v2;
	}
};

void test_01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);

	// 默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}