#include <iostream>
#include <vector>
using namespace std;

/*
	���� vector ÿ�� push_back ����ʱ�������ǰ�ڴ治���������¿���һ���ڴ档 
	Ԥ���ռ䣺����vector�ڶ�̬��չ����ʱ����չ����
	reserve(int len);
	����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/

void test_01()
{
	vector<int> v;
	v.reserve(1000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;  // ��¼���¿����˶��ٴ��ڴ�
		}
	}
	cout << "num:" << num << endl;

	cout << "v������Ϊ��" << v.capacity() << endl;  // 28
	cout << "v�Ĵ�СΪ��" << v.size() << endl;  // 20
}

int main()
{
	test_01();
	system("pause");
	return 0;
}