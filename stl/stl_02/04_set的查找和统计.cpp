#include <iostream>
#include <set>
using namespace std;

/*
	find(key);  // ���� key ֵ�Ƿ���ڣ����ظ�ֵ��Ԫ�صĵ��������������ڣ�����set.end()
	count(key);  // ͳ��key��Ԫ�ظ���  ���Ϊ 0 �� 1
*/

void test_01()
{
	set<int> s1;
	// ����
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);

	// ����
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "�ҵ���Ԫ��" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	// ͳ��
	int num = s1.count(30);
	cout << "num = :" << num << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}