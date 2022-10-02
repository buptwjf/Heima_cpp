#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	adjacent_find(iterator beg, iterator end)
		���������ظ���Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
		���δ�ҵ������� end()
*/

void test_01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);

	// �������ڵ�Ԫ��
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ������ظ���Ԫ��Ϊ" << *it << endl;
	}

}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}