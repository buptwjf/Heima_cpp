#include <iostream>
#include <vector>
using namespace std;

/*
	pair<type, type> p(value1, value2)
	pair<type, typr> p = make_pair(value1, value2)
*/


// ���鴴��
void test_01()
{
	pair<string, int> p(string("tom"), 20);
	cout << "����: " << p.first << "����" << p.second << endl;

	pair<string, int> p1 = make_pair(string("Jerry"), 20);
	cout << "����: " << p1.first << "����" << p1.second << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}