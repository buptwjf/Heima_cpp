#include <iostream>
using namespace std;

/*
	string();       				//创建一个空的字符串 例如: string str;
	string(const char* s);	        //使用字符串s初始化
	string(const string& str);    //使用一个string对象初始化另一个string对象
	string(int n, char c);          //使用n个字符c初始化 
*/

void test_01()
{
	// 默认构造
	string s1;
	cout << s1 << endl;
	// 有参构造
	const char* str = "hello";
	string s2(str);
	cout << s2 << endl;
	// 拷贝构造
	string s3(s2);
	cout << s3 << endl;
	// 有参构造( 重载 )
	string s4(5, 'a');
	cout << s4 << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}