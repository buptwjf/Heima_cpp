#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
	
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


bool maCompare(int v1, int v2)
{
	// 降序，让第一个数大于第二个数
	return v1 > v2;
}

void test_01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	// 反转容器的元素
	L1.reverse();
	printList(L1);

	// 排序
	// 所有不支持随机访问的容器，不能用标准的排序算法 sort()
	//sort(L1.begin(), L1.end());

	// 采用容器自己的成员函数
	L1.sort();  // 默认从小到大
	printList(L1);

	L1.sort(maCompare);
	printList(L1);


}

int main()
{
	test_01();
	system("pause");
	return 0;
}