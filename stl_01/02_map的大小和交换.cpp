#include <iostream>
#include <map>
using namespace std;

/*
	map.size() ����������Ԫ�ص�����
	map.empty()  ���������Ƿ�Ϊ��
	map.swap(st)  ������������
 */

void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << "\tvalue" << it->second << endl;
	}
}

// ��С
void test_01()
{
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(20, 100));
	m.insert(pair<int, int>(30, 100));

	if (!m.empty())
	{
		cout << "m��Ϊ��" << endl;
		cout << "m�Ĵ�СΪ" << m.size() << endl;
	}
	else
	{
		cout << "mΪ��" << endl;
	}

}

// ����
void test_02()
{
	map<int, int> m;
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(20, 100));
	m.insert(pair<int, int>(30, 100));

	map<int, int> m1;
	m.insert(pair<int, int>(1, 100));
	m.insert(pair<int, int>(2, 100));
	m.insert(pair<int, int>(3, 100));

	cout << "����ǰ" << endl;
	PrintMap(m);
	PrintMap(m1);
	m.swap(m1);
	cout << "������" << endl;
	PrintMap(m);
	PrintMap(m1);

}
int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}