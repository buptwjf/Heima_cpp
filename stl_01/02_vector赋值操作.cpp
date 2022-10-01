#include <iostream>
#include <vector>
using namespace std;

/*
	* `vector& operator=(const vector &vec);`//重载等号操作符
	* `assign(beg, end);`       //将[beg, end]区间中的数据拷贝赋值给本身。
	* `assign(n, elem);`        //将n个elem拷贝赋值给本身。
*/
void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*************\n";
}


void test_01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	v2 = v1;  // = 重载
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.end());  // 将[beg, end]区间中的数据赋值。
	printVector(v3);

	vector<int> v4;
	v4.assign(5, 100);  // 将n个elem拷贝赋值给本身
	printVector(v4);

}

int main()
{
	test_01();
	system("pause");
	return 0;
}