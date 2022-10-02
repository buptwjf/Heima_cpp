#include <iostream>
#include <vector>
using namespace std;

/*
	* empty();                             //判断容器是否为空
	* capacity();                      //容器的容量
	* size();                              //返回容器中元素的个数
	* resize(int num);             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					      //如果容器变短，则末尾超出容器长度的元素被删除。
	* resize(int num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				              //如果容器变短，则末尾超出容器长度的元素被删除
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
	for (int i = 0; i < 10; i++)
	{ 
		v1.push_back(i);
	}
	printVector(v1);

	cout << v1.empty() << endl; 
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	cout << "\n*********************\n";

	v1.resize(15);  // 默认用 0 填充
	printVector(v1);
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	cout << "\n*********************\n";

	v1.resize(19, 2);  // 用 2 填充
	printVector(v1);

	v1.resize(5);
	printVector(v1);

}

int main()
{
	test_01();
	system("pause");
	return 0;
}