#include <iostream>
#include <fstream>  // ����ͷ�ļ�

using namespace std;
/*
	�ļ����ͷ��ࣺ
		1. �ı��ļ�
		2. �������ļ�

	�����ļ��������ࣺ
		1. ofstream: д����
		2. ifstream: ������
		3. fstream : ��д����
		
	д�ļ�����
		1. ����ͷ�ļ�
			#include <fstream>
		2. ����������
			ofstream ofs;
		3. ���ļ�
			ofs.open("�ļ�·��", �򿪷�ʽ)
		4. д����
			ofs << "д�������";
		5. �ر��ļ�
			ofs.close();

	�ļ��Ĵ򿪷�ʽ
		1. ios::in ���ļ�
		2. ios::out д�ļ�
		3. ios::ate �ļ�β
		4. ios::app ׷�ӷ�ʽд
		5. ios::trunc ��ɾ�����ٴ���
		6. ios::binary �����Ʒ�ʽ
*/


class
{
public:
};
void test_01()
{
	// ����������
	ofstream ofs;
	// �ƶ��򿪷�ʽ
	ofs.open("test.txt", ios::out);
	ofs << " ���������� "<< endl;
	ofs << " �Ա��� " << endl;
	ofs << " ���䣺18 " << endl;
	ofs.close();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}