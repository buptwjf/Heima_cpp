#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	bool binary_search(iterator beg, iterator end, value);  `
		����ָ����Ԫ���Ƿ���ڣ��鵽���� true������ false
		������������в�����
*/

void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool flag = false;
	// �ж�Ԫ���Ƿ����
	flag = binary_search(v.begin(), v.end(), 5);
	if (flag)
	{
		cout << "Ԫ�ش���" << endl;
	}
	else
	{
		cout << "Ԫ�ز����� " << endl;
	}
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}