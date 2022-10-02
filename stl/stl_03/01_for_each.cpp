#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
	for_each(First, Last, Func)
*/

// ��ͨ����
void print01(int val)
{
	cout << val << " ";
}

// �º���
class print02
{
public:
	void operator() (int val)
	{
		cout << val << " ";
	}
};
void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ��ͨ����
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	// �º���
	for_each(v.begin(), v.end(), print02());
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}