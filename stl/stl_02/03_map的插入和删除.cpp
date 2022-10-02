#include <iostream>
#include <map>
using namespace std;

/*
	map 插入和删除
 */

void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << "\tvalue" << it->second << endl;
	}
	cout << endl;
}

void test_01()
{
	// 插入
	// 第一种
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));

	// 第二种
	m.insert(make_pair(20, 100));

	// 第三种
	m.insert(map<int, int>::value_type(3, 30));

	// 第四种
	m[4] = 40;

	// 第五种
	m[5];  // 默认 value 为0，不建议插入,建议作为查找
	PrintMap(m);

	// 删除
	// 1. 迭代器
	m.erase(m.begin());
	PrintMap(m);

	// 2. key 值
	m.erase(3);
	PrintMap(m);

	// 3. 按照区间
	m.erase(m.begin(), m.end());
	PrintMap(m);

	// 4. clear
	m.clear();
	PrintMap(m);
}


int main()
{
	test_01();
	system("pause");
	return 0;
}