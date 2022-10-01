#include <iostream>
#include <vector>
using namespace std;

/*
	vector ���캯��
	* `vector<T> v; `               		     //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	* `vector(v.begin(), v.end());   `       //��v[begin(), end())�����е�Ԫ�ؿ���������
	* `vector(n, elem);`                            //���캯����n��elem����������
	* `vector(const vector &vec);`         //�������캯����

*/

void printVerctor(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n*********" << endl;
}



void test_01()
{
	vector<int> v;  // �޲ι���
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVerctor(v);

	vector<int> v1(v.begin(), v.end());  // ��v[begin(), end()]�����е�Ԫ�ؿ���
	printVerctor(v1);

	vector<int> v3(5, 100);  // �� 5 �� 100 ����
	printVerctor(v3);

	vector<int> v4(v3);  // ��������
	printVerctor(v4);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}