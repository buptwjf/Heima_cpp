#include <iostream>
#include <vector>
using namespace std;

/*
	pair<type, type> p(value1, value2)
	pair<type, typr> p = make_pair(value1, value2)
*/


// 对组创建
void test_01()
{
	pair<string, int> p(string("tom"), 20);
	cout << "姓名: " << p.first << "年龄" << p.second << endl;

	pair<string, int> p1 = make_pair(string("Jerry"), 20);
	cout << "姓名: " << p1.first << "年龄" << p1.second << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}