#include <iostream>
using namespace std;

/*
	拷贝构造函数的调用时机
	1. 使用已创建的对象来初始化一个新对象；
		注意：直接赋值操作不是拷贝构造
	2. 以值传递的方式给函数传值
	3. 以值方式返回局部对象
*/

class Person
{
public:
	// 默认构造函数（无参构造函数）
	Person(){
		cout << "默认构造函数" << endl;
	}
	// 有参构造函数
	Person(int a){
		age = a;
		cout << "有参构造函数" << endl;
	}
	// 拷贝构造函数
	Person(const Person& p){
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}
	// 析构函数
	~Person(){
		cout << "析构函数" << endl;
	}
private:
	int age;
};

// 1. 使用已创建的对象来初始化一个新对象；
void test_01()
{
	Person man(100);  // 有参构造函数
	Person newman(man);  // 调用拷贝构造函数
	Person newman2 = man;  // 拷贝构造

	Person newman3;  // 默认构造函数
	newman3 = man;  // 不是拷贝构造
}


// 2. 以值传递的方式给函数传值（实参给形参的时候），使用一次拷贝构造
// 相当于 Person p1;
void doWork(Person pl) {}
void test_02()
{
	Person p;
	doWork(p);
}


// 3. 以值方式返回局部对象
Person doWork2()
{
	Person p1;  // 默认构造函数
	cout << &p1 << endl;
	return p1;
}
void test_03()
{
	Person p = doWork2();  // 拷贝构造函数
	cout << &p << endl;
}

int main()
{
	test_01();
	cout << "----------------" << endl;
	test_02();
	cout << "----------------" << endl;
	test_03();
	system("pause");
	return 0;
}