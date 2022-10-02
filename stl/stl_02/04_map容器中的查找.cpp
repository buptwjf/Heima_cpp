#include <iostream>
#include <map>
using namespace std;

/*
	map容器的查找和统计
*/

void test_01()
{
	// 查找
	map<int, int> m;
	m.insert(make_pair(10, 100));
	m.insert(make_pair(20, 200));
	m.insert(make_pair(30, 300));

	// find 返回迭代器，否则返回 m.end()
	map<int, int>::iterator pos = m.find(40);
	if (pos != m.end())
	{
		cout << "查找到, value 为 " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	// 统计  map 要么为 0，要么为 1
	// cout(key)
	cout << m.count(30) << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}