#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	vector �Ǵ洢��һ�������Ŀռ�
*/


void MyPrint(int val)
{
	cout << val << endl;
}


void test_01()
{
	// ���� vector ����
	vector<int> v;

	// �������ڷ�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// ��ʼ������
	vector<int>::iterator pBegin = v.begin();
	// β������
	vector<int>::iterator pEnd = v.end();

	// ��һ�ֱ�����ʽ
	//while (pBegin != pEnd)
	//{
	//	cout << *pBegin << endl;
	//	pBegin++;
	//}

	// �ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	//cout << endl;

	// �����ֱ���
	// ���� stl �ṩ�ı�׼�����㷨 ͷ�ļ� algorithm
	for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}