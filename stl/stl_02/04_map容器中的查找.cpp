#include <iostream>
#include <map>
using namespace std;

/*
	map�����Ĳ��Һ�ͳ��
*/

void test_01()
{
	// ����
	map<int, int> m;
	m.insert(make_pair(10, 100));
	m.insert(make_pair(20, 200));
	m.insert(make_pair(30, 300));

	// find ���ص����������򷵻� m.end()
	map<int, int>::iterator pos = m.find(40);
	if (pos != m.end())
	{
		cout << "���ҵ�, value Ϊ " << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	// ͳ��  map ҪôΪ 0��ҪôΪ 1
	// cout(key)
	cout << m.count(30) << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}