#include <iostream>
#include <set>
using namespace std;

/*
* `insert(elem);`           //�������в���Ԫ�ء�
* `clear();`                    //�������Ԫ��
* `erase(pos);`              //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
* `erase(beg, end);`    //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
* `erase(elem);`            //ɾ��������ֵΪelem��Ԫ�ء�
*/


void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_01()
{
	set<int> s1;

	// ����
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	// ����
	printSet(s1);

	// ɾ��
	// 1. ����ֵ�����ݵ�������
	s1.erase(10);
	printSet(s1);

	// 2. ��������
	set<int>::iterator it = s1.begin();
	it++;
	s1.erase(it, s1.end());
	printSet(s1);

	// ���
	s1.clear();
	printSet(s1);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}