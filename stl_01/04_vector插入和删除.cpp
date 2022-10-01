#include <iostream>
#include <vector>
using namespace std;

/*
	* `push_back(ele);`                                         //β������Ԫ��ele
	* `pop_back();`                                                //ɾ�����һ��Ԫ��
	* `insert(const_iterator pos, ele);`        //������ָ��λ��pos����Ԫ��ele
	* `insert(const_iterator pos, int count,ele);`//������ָ��λ��pos����count��Ԫ��ele
	* `erase(const_iterator pos);`                     //ɾ��������ָ���Ԫ��
	* `erase(const_iterator start, const_iterator end);`//ɾ����������start��end֮���Ԫ��
	* `clear();`                                                        //ɾ������������Ԫ��
*/

void printVector(vector<int> v)
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

	// β��
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	// βɾ
	v1.pop_back();
	printVector(v1);

	// ����
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 3, 200);
	printVector(v1);

	// ɾ��
	v1.erase(v1.begin());
	printVector(v1);

	// ���
	v1.erase(v1.begin(), v1.end());
	printVector(v1);

	v1.clear();
	printVector(v1);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}