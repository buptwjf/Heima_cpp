#include <iostream>
#include <fstream>
using namespace std;
/*
	�����ƶ��ļ�
	istream& read(char *buffer,int len);
*/


class Person
{
public:
	char m_Name[64];  // ����
	int m_Age;  // ����
};
void test_01()
{
	// 1. ����ͷ�ļ�
	// 2. ����������
	ifstream ifs;
	// 3. ���ļ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	
	// 4. ���ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	// 5. �ر��ļ�
	cout << "����" << p.m_Name << "\t���䣺" << p.m_Age << endl;
	ifs.close();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}