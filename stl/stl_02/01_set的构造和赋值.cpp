#include <iostream>
#include <set>
using namespace std;

/*
	set/ multiset������Ԫ�ض����ڲ���ʱ�Զ�������
	1. ����
		1. set���������������ظ���Ԫ��
		2. multiset�������������ظ���Ԫ��
	2. ����
		set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�

	3. 
		���죺
		set<T> st;               //Ĭ�Ϲ��캯����
		set(const set &st);       //�������캯��
		��ֵ��
		set& operator=(const set &st);    //���صȺŲ�����
		���룺
		insert(elem)
*/

void printSet(set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_01()
{
	set<int> s;
	s.insert(40);
	s.insert(10);
	s.insert(30);
	s.insert(50);
	s.insert(20);

	printSet(s);

	// ��������
	set<int> s1(s);
	printSet(s1);

	// ��ֵ
	// = ���������
	set<int> s2 = s1;
	printSet(s2);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}