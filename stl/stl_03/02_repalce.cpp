#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	replace(iterator beg, iterator end, oldvalue, newvalue)
	�������ھ�Ԫ�� �滻�� ��Ԫ��
*/

class MyPrint
{
public:
	void operator () (int val)
	{
		cout << val << " ";
	}
};

void test_01()
{
	vector<int> v;

	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	
	cout << "����ǰ" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	// �������е� 20 ���� 2000
	cout << "�����" << endl;
	replace(v.begin(), v.end(), 20, 20000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}