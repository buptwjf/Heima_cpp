#include <iostream>
#include <stack>
using namespace std;

/*
	1. ջ���ýӿ�
	2. ջ�������б�������Ϊ
*/

void test_01()
{
	// ����ջ���� 
	stack<int> s;

	// ѹջ
	s.push(10);
	s.push(20);
	s.push(30);

	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;

	while (!s.empty())
	{
		// ���ջ��Ԫ��
		cout << "ջ��Ԫ��" << s.top() << endl;
		// ����ջ��Ԫ��
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}