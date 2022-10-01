#include <iostream>
#include <fstream>  // 包含头文件
#include <string>
using namespace std;
/*
	读文件操作
*/


class
{
public:
};
void test_01()
{
	// 创建流对象
	ifstream ifs;
	// 打开文件
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	// 读文件
	// 第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	// 第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// 第三种
	//string buf;

	//while (getline(ifs, buf))
	//{ 
	//	cout << buf << endl;
	//}
	
	// 第四种
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();  // 关闭流程
}

int main()
{
	test_01();
	system("pause");
	return 0;
}