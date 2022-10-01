#include <iostream>
#include <deque>
using namespace std;

/*
	两端插入操作：
- `push_back(elem);`          //在容器尾部添加一个数据
- `push_front(elem);`        //在容器头部插入一个数据
- `pop_back();`                   //删除容器最后一个数据
- `pop_front();`                 //删除容器第一个数
指定位置操作：
* `insert(pos,elem);`         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。
* `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。
* `clear();`                           //清空容器的所有数据
* `erase(beg,end);`             //删除[beg,end)区间的数据，返回下一个数据的位置。
* `erase(pos);`                    //删除pos位置的数据，返回下一个数据的位置。
*/

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n****************\n";
}


// 两端操作
void test_01()
{
	deque<int> d;
	// 尾插
	d.push_back(10);
	d.push_back(20);

	// 头插
	d.push_front(30);
	d.push_front(40);

	printDeque(d);

	// 尾删
	d.pop_back();
	d.pop_front();

	printDeque(d);
}


// 插入
// 与vector 不同， deque 插入和删除提供的位置是迭代器！ 
void test_02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2, 100);
	printDeque(d);

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_front(3);
	d2.push_front(4);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}

// 删除
void test_03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	// 按位置删除
	//erase(pos); //删除pos位置的数据，返回下一个数据的位置。
	d.insert(d.erase(d.begin()), 5, 5);
	printDeque(d);

	deque<int>::const_iterator it = d.begin();
	it++;
	d.erase(it);
	printDeque(d);

	// 按区间删除
	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

int main()
{
	//test_01();
	//test_02();
	test_03();
	system("pause");
	return 0;
}