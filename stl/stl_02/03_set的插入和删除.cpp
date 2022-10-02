#include <iostream>
#include <set>
using namespace std;

/*
* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。
*/


void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_01()
{
	set<int> s1;

	// 插入
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	// 遍历
	printSet(s1);

	// 删除
	// 1. 根据值（根据迭代器）
	s1.erase(10);
	printSet(s1);

	// 2. 根据区间
	set<int>::iterator it = s1.begin();
	it++;
	s1.erase(it, s1.end());
	printSet(s1);

	// 清空
	s1.clear();
	printSet(s1);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}