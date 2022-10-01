#include <iostream>
#include <fstream>
using namespace std;
/*
	二进制读文件
	istream& read(char *buffer,int len);
*/


class Person
{
public:
	char m_Name[64];  // 姓名
	int m_Age;  // 年龄
};
void test_01()
{
	// 1. 包含头文件
	// 2. 创建流对象
	ifstream ifs;
	// 3. 打开文件
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	
	// 4. 读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	// 5. 关闭文件
	cout << "姓名" << p.m_Name << "\t年龄：" << p.m_Age << endl;
	ifs.close();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}