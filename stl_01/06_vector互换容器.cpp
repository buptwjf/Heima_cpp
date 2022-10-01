#include <iostream>
#include <vector>
using namespace std;

/*

*/

void printVector(vector<int> v)  // ���ܼ� const
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*********************\n";
}

void test_01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	for (int i = 20; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	cout << "v1������Ϊ��" << v1.capacity() << endl;  // 28
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;  // 20
	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;

	// ʹ�����������Լ����������������ڴ�
	vector<int>(v1).swap(v1);
	cout << "v1������Ϊ��" << v1.capacity() << endl;  // 20
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;   // 20 

}


//ʹ�����������Լ����������������ڴ�
void test_02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	v.resize(3);

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	//�����ڴ�
	vector<int>(v).swap(v); //��������

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
}


int main()
{
	test_01();
	test_02();
	system("pause");
	return 0;
}