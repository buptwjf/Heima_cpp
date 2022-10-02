#include <iostream>
#include <list>
using namespace std;

/*
	1. list ˫��ѭ������
	2. ����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��
	3. �ռ�(ָ����) �� ʱ�䣨����������ķѽϴ�
	4. ���������ɾ���������������ԭ��list��������ʧЧ
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test_01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	list<int> L2(L1.begin(), L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(5, 100);
	printList(L4);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}