#include <iostream>
#include <vector>
using namespace std;

/*
	* `vector& operator=(const vector &vec);`//���صȺŲ�����
	* `assign(beg, end);`       //��[beg, end]�����е����ݿ�����ֵ������
	* `assign(n, elem);`        //��n��elem������ֵ������
*/
void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*************\n";
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
	v2 = v1;  // = ����
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.end());  // ��[beg, end]�����е����ݸ�ֵ��
	printVector(v3);

	vector<int> v4;
	v4.assign(5, 100);  // ��n��elem������ֵ������
	printVector(v4);

}

int main()
{
	test_01();
	system("pause");
	return 0;
}