#include <iostream>
#include <list>
using namespace std;

/*
	1. list 双向循环链表
	2. 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
	3. 空间(指针域) 和 时间（遍历）额外耗费较大
	4. 插入操作和删除操作都不会造成原有list迭代器的失效
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test_01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	list<int> L2(L1.begin(), L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(5, 100);
	printList(L4);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}