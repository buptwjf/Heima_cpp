#include <iostream>
#include <set>
using namespace std;

/*
* set �Ĵ�С�ͽ���
* `size();`          //����������Ԫ�ص���Ŀ
* `empty();`        //�ж������Ƿ�Ϊ��
* `swap(st);`      //����������������
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
}

// ��С
void test_01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	// ��ӡ����
	printSet(s1);

	// �ж��Ƿ�Ϊ��
	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
	}
}


void test_02()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	set<int> s2;
	s1.insert(100);
	s1.insert(400);
	s1.insert(300);
	//s1.insert(200);

	cout << "����ǰ: " << endl;
	printSet(s1);
	printSet(s2);

	cout << "\n������" << endl;
	printSet(s1);
	printSet(s2);

}

// ����
int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}