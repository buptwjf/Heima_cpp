#include <iostream>
using namespace std;

/*
	string();       				//����һ���յ��ַ��� ����: string str;
	string(const char* s);	        //ʹ���ַ���s��ʼ��
	string(const string& str);    //ʹ��һ��string�����ʼ����һ��string����
	string(int n, char c);          //ʹ��n���ַ�c��ʼ�� 
*/

void test_01()
{
	// Ĭ�Ϲ���
	string s1;
	cout << s1 << endl;
	// �вι���
	const char* str = "hello";
	string s2(str);
	cout << s2 << endl;
	// ��������
	string s3(s2);
	cout << s3 << endl;
	// �вι���( ���� )
	string s4(5, 'a');
	cout << s4 << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}