#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
	
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


bool maCompare(int v1, int v2)
{
	// �����õ�һ�������ڵڶ�����
	return v1 > v2;
}

void test_01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	// ��ת������Ԫ��
	L1.reverse();
	printList(L1);

	// ����
	// ���в�֧��������ʵ������������ñ�׼�������㷨 sort()
	//sort(L1.begin(), L1.end());

	// ���������Լ��ĳ�Ա����
	L1.sort();  // Ĭ�ϴ�С����
	printList(L1);

	L1.sort(maCompare);
	printList(L1);


}

int main()
{
	test_01();
	system("pause");
	return 0;
}