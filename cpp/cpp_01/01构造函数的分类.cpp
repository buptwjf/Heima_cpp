#include <iostream>
using namespace std;

// 1. 定义构造函数
class Person
{
public:
	// 默认构造函数（无参构造函数）
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	// 有参构造函数
	Person(int a)
	{
		age = a;
		cout << "有参构造函数" << endl;
	}
	// 拷贝构造函数
	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}
	// 析构函数
	~Person()
	{
		cout << "析构函数" << endl;
	}

private:
	int age;
};

// 2. 构造函数的调用
// 调用无参构造函数
void test_01()
{
	Person p;  // 默认构造函数不能有括号，否则会认为是函数声明
}

// 调用有参的构造函数
void test_02()
{
	// 2.1 括号法
	cout << "------括号法-------" << endl;
	Person p1(10);  // 有参构造
	Person p2(p1);  // 拷贝构造
	cout << "-------------------" << endl;
	// 注意 1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	// Person p2();
	// 注意 2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象 p1 的声明
	// Person(p1); 


	// 2.2 显示法
	cout << "------显示法-------" << endl;
	p2 = Person(10);         // 有参构造
	Person p3 = Person(p2);  // 拷贝构造
	cout << "-------------------" << endl;
	// 注意 3：Person(10) 单独写就是匿名对象，没有名，当前行结束后，会马上进行析构


	// 2.3 隐式转换法
	cout << "------隐式转换法-------" << endl;
	Person p4 = 10;  // 有参构造
	Person p5 = p4;  // 拷贝构造
	// 注意 4：与 Person p4 = Person(10);  Person p5 = Person(p4); 等价，但是没有 Person(10)的析构函数
	cout << "-----------------------" << endl;
}

int main()
{
	test_01();
	cout << "******************" << endl;
	test_02();
	system("pause");
	return 0;
}