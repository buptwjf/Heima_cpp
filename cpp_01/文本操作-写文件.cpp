#include <iostream>
#include <fstream>  // 增加头文件

using namespace std;
/*
	文件类型分类：
		1. 文本文件
		2. 二进制文件

	操作文件的三大类：
		1. ofstream: 写操作
		2. ifstream: 读操作
		3. fstream : 读写操作
		
	写文件步骤
		1. 包含头文件
			#include <fstream>
		2. 创建流对象
			ofstream ofs;
		3. 打开文件
			ofs.open("文件路径", 打开方式)
		4. 写数据
			ofs << "写入的数据";
		5. 关闭文件
			ofs.close();

	文件的打开方式
		1. ios::in 读文件
		2. ios::out 写文件
		3. ios::ate 文件尾
		4. ios::app 追加方式写
		5. ios::trunc 先删除，再创建
		6. ios::binary 二进制方式
*/


class
{
public:
};
void test_01()
{
	// 创建流对象
	ofstream ofs;
	// 制定打开方式
	ofs.open("test.txt", ios::out);
	ofs << " 姓名：张三 "<< endl;
	ofs << " 性别：男 " << endl;
	ofs << " 年龄：18 " << endl;
	ofs.close();
}

int main()
{
	test_01();
	system("pause");
	return 0;
}