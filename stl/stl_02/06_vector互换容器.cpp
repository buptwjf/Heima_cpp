#include <iostream>
#include <vector>
using namespace std;

/*

*/

void printVector(vector<int> v)  // 不能加 const
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
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	for (int i = 20; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "互换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	cout << "v1的容量为：" << v1.capacity() << endl;  // 28
	cout << "v1的大小为：" << v1.size() << endl;  // 20
	cout << "v2的容量为：" << v2.capacity() << endl;
	cout << "v2的大小为：" << v2.size() << endl;

	// 使用匿名对象自己交换，可以收缩内存
	vector<int>(v1).swap(v1);
	cout << "v1的容量为：" << v1.capacity() << endl;  // 20
	cout << "v1的大小为：" << v1.size() << endl;   // 20 

}


//使用匿名对象自己交换，可以收缩内存
void test_02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//收缩内存
	vector<int>(v).swap(v); //匿名对象

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}


int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}