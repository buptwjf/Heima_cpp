#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	swap(container c1, container c2); 
	������������Ԫ�� �滻�� ��Ԫ��
*/

class MyPrint
{
public:
	void operator () (int val)
	{
		cout << val << " ";
	}
};

class ReplaceGreater30
{
public:
	bool operator() (int val)
	{
		return val >= 30;
	}
};
void test_01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "����ǰ" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

	// ����
	cout << "������" << endl;
	swap(v1, v2);

	for_each(v1.begin(), v1.end(), MyPrint());
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}