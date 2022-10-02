#include <iostream>
#include <map>
using namespace std;

/*
	map ���������
*/

class MyCompare
{
public:
	bool operator() (int v1, int v2) const  // ����Ҫ�� cosnt
	{
		return v1 > v2;
	}
};

void PrintMap(map<int, int, MyCompare>& m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key��" << it->first << "\nvalue" << it->second << endl;
	}
	cout << endl;
}


void test_01()
{
	// ���÷º���ʵ�ִӴ�С����
	map<int, int, MyCompare> m;
	m.insert(make_pair(10, 100));
	m.insert(make_pair(20, 200));
	m.insert(make_pair(30, 300));

	PrintMap(m);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}