#include <iostream>
#include <map>
using namespace std;

/*
	map.size() 返回容器中元素的数量
	map.empty()  返回容器是否为空
	map.swap(st)  交换两个容器
 */

void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << "\tvalue" << it->second << endl;
	}
}

// 大小
void test_01()
{
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(20, 100));
	m.insert(pair<int, int>(30, 100));

	if (!m.empty())
	{
		cout << "m不为空" << endl;
		cout << "m的大小为" << m.size() << endl;
	}
	else
	{
		cout << "m为空" << endl;
	}

}

// 交换
void test_02()
{
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(20, 100));
	m.insert(pair<int, int>(30, 100));

	map<int, int> m1;
	m.insert(pair<int, int>(1, 100));
	m.insert(pair<int, int>(2, 100));
	m.insert(pair<int, int>(3, 100));

	cout << "交换前" << endl;
	PrintMap(m);
	PrintMap(m1);
	m.swap(m1);
	cout << "交换后" << endl;
	PrintMap(m);
	PrintMap(m1);

}
int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}