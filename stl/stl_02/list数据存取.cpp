#include <iostream>
#include <list>
using namespace std;

/*
	* `front();`        //���ص�һ��Ԫ�ء�
	* `back();`         //�������һ��Ԫ�ء�
*/

void test_01()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);


	//1. list ��֧�� at ��[]
	//	ԭ�� : List ��������һ���б�
	cout << "L�ĵ�һ��Ԫ��" << L.front() << endl;
	cout << "L�����һ��Ԫ��" << L.back() << endl;

	// 2. ������Ҳ������Ծ����, ֻ�� ++ ���� --
	list<int>::iterator it = L.begin();
	//it = it + 1;  ��֧��
	it++;  // ֧��
	it--;  // ֧��
}

int main()
{
	test_01();
	system("pause");
	return 0;
}