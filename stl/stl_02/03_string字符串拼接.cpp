#include <iostream>
#include <string>
using namespace std;

/*
* `string& operator+=(const char* str);`                   //����+=������
* `string& operator+=(const char c);`                         //����+=������
* `string& operator+=(const string& str);`                //����+=������
* `string& append(const char *s); `                               //���ַ���s���ӵ���ǰ�ַ�����β
* `string& append(const char *s, int n);`                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
* `string& append(const string &s);`                           //ͬoperator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/

void test_01()
{
	string str1 = "��";

	string str2 = "������Ϸ";

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