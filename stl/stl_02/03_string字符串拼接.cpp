#include <iostream>
#include <string>
using namespace std;

/*
* `string& operator+=(const char* str);`                   //重载+=操作符
* `string& operator+=(const char c);`                         //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                           //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾
*/

void test_01()
{
	string str1 = "我";

	string str2 = "电子游戏";

	str1 += str2;
	cout << str1 << endl;

	str1 += ":";

	str1 += "LOL";

	string str3 = "I";
	str3.append(" Love");
	cout << str3 << endl;

	str3.append("game asd", 4);
	cout << str3 << endl;

	str3.append(str2);
	cout << str3 << endl;

	str3.append(str3, 2, 3);
	cout << str3 << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}