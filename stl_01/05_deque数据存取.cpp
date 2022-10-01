#include <iostream>
#include <deque>
using namespace std;

/*
	at(int idx);   //��������idx��ָ������
	operator[];     //��������idx��ָ������
	front();          //���������е�һ������Ԫ��
	back();            //�������������һ������Ԫ��

*/

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n****************\n";
}

void test_01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	cout << d.at(2) << endl;
	cout << d[2] << endl;

	cout << d.front() << endl;
	cout << d.back() << endl;;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}