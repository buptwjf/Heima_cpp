#include <iostream>
#include <vector>
using namespace std;

/*
	* `push_back(ele);`                                         //尾部插入元素ele
	* `pop_back();`                                                //删除最后一个元素
	* `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
	* `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
	* `erase(const_iterator pos);`                     //删除迭代器指向的元素
	* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
	* `clear();`                                                        //删除容器中所有元素
*/

void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*********************\n";
}

void test_01()
{
	vector<int> v1;

	// 尾插
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	// 尾删
	v1.pop_back();
	printVector(v1);

	// 插入
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 3, 200);
	printVector(v1);

	// 删除
	v1.erase(v1.begin());
	printVector(v1);

	// 清空
	v1.erase(v1.begin(), v1.end());
	printVector(v1);

	v1.clear();
	printVector(v1);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}