#include <iostream>
#include <vector>
using namespace std;

/*
	vector 构造函数
	* `vector<T> v; `               		     //采用模板实现类实现，默认构造函数
	* `vector(v.begin(), v.end());   `       //将v[begin(), end())区间中的元素拷贝给本身。
	* `vector(n, elem);`                            //构造函数将n个elem拷贝给本身。
	* `vector(const vector &vec);`         //拷贝构造函数。

*/

void printVerctor(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*********" << endl;
}



void test_01()
{
	vector<int> v;  // 无参构造
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVerctor(v);

	vector<int> v1(v.begin(), v.end());  // 将v[begin(), end()]区间中的元素拷贝
	printVerctor(v1);

	vector<int> v3(5, 100);  // 将 5 个 100 拷贝
	printVerctor(v3);

	vector<int> v4(v3);  // 拷贝构造
	printVerctor(v4);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}