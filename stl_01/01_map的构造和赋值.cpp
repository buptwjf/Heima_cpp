#include <iostream>
#include <map>
using namespace std;

/*
	map 构造和赋值
*/

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key " << it->first << "value" << it->second << endl;
	}
	cout << endl;
}

void test_01()
{
	map<int, int> m;  // 默认构造

	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(20, 200));
	m.insert(pair<int, int>(30, 300));
	m.insert(pair<int, int>(15, 400));
	m.insert(pair<int, int>(15, 300));  // 不报错,但是后写的插不进去


	printMap(m);

	// 拷贝构造
	map<int, int>m2(m);
	printMap(m2);

	// 赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}