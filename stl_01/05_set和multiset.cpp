#include <iostream>
#include <set>
using namespace std;

/*
	1. set �����Բ����ظ����ݣ��� multiset ����
	2. set ��������ʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
	3. multiset ���������ݣ���˿��Բ����ظ�����
*/

void test_01()
{
	set<int> s;

	s.insert(10);
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
	
	// multiset
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it  << " ";
	}
	cout << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}