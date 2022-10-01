#include <iostream>
#include <map>
using namespace std;

/*
	map �����ɾ��
 */

void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << "\tvalue" << it->second << endl;
	}
	cout << endl;
}

void test_01()
{
	// ����
	// ��һ��
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));

	// �ڶ���
	m.insert(make_pair(20, 100));

	// ������
	m.insert(map<int, int>::value_type(3, 30));

	// ������
	m[4] = 40;

	// ������
	m[5];  // Ĭ�� value Ϊ0�����������,������Ϊ����
	PrintMap(m);

	// ɾ��
	// 1. ������
	m.erase(m.begin());
	PrintMap(m);

	// 2. key ֵ
	m.erase(3);
	PrintMap(m);

	// 3. ��������
	m.erase(m.begin(), m.end());
	PrintMap(m);

	// 4. clear
	m.clear();
	PrintMap(m);
}


int main()
{
	test_01();
	system("pause");
	return 0;
}