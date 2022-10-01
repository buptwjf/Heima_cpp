#include <iostream>
using namespace std;
/*


*/
class Person
{
	friend ostream& operator << (ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//  利用成员函数来重载左移运算符 p.operator<<(cout),简化版本 p << cout
	//  不能利用成员函数实现重载 << 运算符，因为无法实现 cout 在左侧
	//void operator << (Person& p)
	//{

	//}
private:
	int m_A;
	int m_B;
};


// 只能利用全局函数重载左移运算符，返回值用 & 因为 cout 只能有一个
ostream & operator << (ostream& cout, Person& p)  // 本质operator << (cout, p)，简化为 cout << p
{
	cout << "m_A: " << p.m_A << "\tm_B" << p.m_B;
	return cout;
}
void test_01()
{
	Person p(10, 20);
	cout << p; // 无法添加 endl; 
	cout << "\n" << p << endl;  // 增加返回值后可以
}
int main()
{
	test_01();
	system("pause");
	return 0;
}