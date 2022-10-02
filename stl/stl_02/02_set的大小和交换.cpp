#include <iostream>
#include <set>
using namespace std;

/*
* set 的大小和交换
* `size();`          //返回容器中元素的数目
* `empty();`        //判断容器是否为空
* `swap(st);`      //交换两个集合容器
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
}

// 大小
void test_01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	// 打印容器
	printSet(s1);

	// 判断是否为空
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}


void test_02()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	set<int> s2;
	s1.insert(100);
	s1.insert(400);
	s1.insert(300);
	//s1.insert(200);

	cout << "交换前: " << endl;
	printSet(s1);
	printSet(s2);

	cout << "\n交换后" << endl;
	printSet(s1);
	printSet(s2);

}

// 交换
int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}