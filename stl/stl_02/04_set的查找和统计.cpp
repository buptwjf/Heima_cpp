#include <iostream>
#include <set>
using namespace std;

/*
	find(key);  // 查找 key 值是否存在，返回该值的元素的迭代器；若不存在，返回set.end()
	count(key);  // 统计key的元素个数  结果为 0 或 1
*/

void test_01()
{
	set<int> s1;
	// 插入
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);

	// 查找
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "找到了元素" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	// 统计
	int num = s1.count(30);
	cout << "num = :" << num << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}