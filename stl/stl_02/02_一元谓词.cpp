#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	һԪν�ʣ� �º������������� bool�� ����һ������
*/

class GreatFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test_01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ���������д��� 5 ������
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreatFive()); // ��������
	if (it == v.end())
	{
		cout << " δ�ҵ���" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�" << *it << endl;
	}
}

int main()
{
	test_01();
	system("pause");
	return 0;
}