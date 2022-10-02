#include <iostream>
#include <vector>
using namespace std;

/*
	由于 vector 每次 push_back 数据时候，如果当前内存不够，会重新开辟一处内存。 
	预留空间：减少vector在动态扩展容量时的扩展次数
	reserve(int len);
	容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/

void test_01()
{
	vector<int> v;
	v.reserve(1000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;  // 记录重新开辟了多少次内存
		}
	}
	cout << "num:" << num << endl;

	cout << "v的容量为：" << v.capacity() << endl;  // 28
	cout << "v的大小为：" << v.size() << endl;  // 20
}

int main()
{
	test_01();
	system("pause");
	return 0;
}