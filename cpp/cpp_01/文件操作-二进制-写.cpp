#include <iostream>
#include <fstream>
using namespace std;
/*
	二进制写文件
	ostream& write(const char * buffer,int len);
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
	ofstream ofs;
	// 3. 打开文件
	ofs.open("person.txt", ios::out | ios::binary);
	// 4. 写文件
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
	// 5. 关闭文件
	ofs.close();

}

void test_02()
{

}


int main()
{
	test_01();
	system("pause");
	return 0;
}