#include <iostream>
#include <fstream>  // ����ͷ�ļ�
#include <string>
using namespace std;
/*
	���ļ�����
*/


class
{
public:
};
void test_01()
{
	// ����������
	ifstream ifs;
	// ���ļ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// ���ļ�
	// ��һ��
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	// �ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// ������
	//string buf;

	//while (getline(ifs, buf))
	//{ 
	//	cout << buf << endl;
	//}
	
	// ������
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();  // �ر�����
}

int main()
{
	test_01();
	system("pause");
	return 0;
}