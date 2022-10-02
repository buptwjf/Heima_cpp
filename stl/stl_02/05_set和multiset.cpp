#include <iostream>
#include <set>
using namespace std;

/*
	1. set 不可以插入重复数据，而 multiset 可以
	2. set 插入数据时会返回插入结果，表示插入是否成功
	3. multiset 不会检测数据，因此可以插入重复数据
*/

void test_01()
{
	set<int> s;

	s.insert(10);
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
	
	// multiset
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it  << " ";
	}
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}