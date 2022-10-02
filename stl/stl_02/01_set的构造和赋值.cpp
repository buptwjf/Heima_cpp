#include <iostream>
#include <set>
using namespace std;

/*
	set/ multiset：所有元素都会在插入时自动被排序
	1. 区别
		1. set不允许容器中有重复的元素
		2. multiset允许容器中有重复的元素
	2. 本质
		set/multiset属于关联式容器，底层结构是用二叉树实现。

	3. 
		构造：
		set<T> st;               //默认构造函数：
		set(const set &st);       //拷贝构造函数
		赋值：
		set& operator=(const set &st);    //重载等号操作符
		插入：
		insert(elem)
*/

void printSet(set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_01()
{
	set<int> s;
	s.insert(40);
	s.insert(10);
	s.insert(30);
	s.insert(50);
	s.insert(20);

	printSet(s);

	// 拷贝构造
	set<int> s1(s);
	printSet(s1);

	// 赋值
	// = 运算符重载
	set<int> s2 = s1;
	printSet(s2);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}