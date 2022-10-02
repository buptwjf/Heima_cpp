#include <iostream>
using namespace std;
/*
	构造函数的调用规则
*/

class Person
{
public:
	Person() {
		cout << "默认构造函数" << endl;
	}
	Person(int a, int h) {
		age = a;
		height = new int(h);  // 在堆区创建一个内存来接收身高
		cout << "有参构造函数" << endl;
	}
	// 拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		// height = p.height;  // 编译器默认操作， 浅拷贝
		height = new int(*p.height);  // 利用深拷贝重新申请一个空间
		cout << "拷贝构造函数" << endl;
	}
	// 析构函数
	~Person() {
		// 将堆区开辟的数据做释放操作，并且置空
		if (height != NULL)
		{
			delete height;
			height = NULL;
		}
		cout << "析构函数" << endl;
	}
	int age;  // 年龄
	int* height;  // 身高
private:
};


void test_01()
{
	Person p1(18, 160);
	cout << "p1的年龄为： " << p1.age << "身高为：" << *p1.height << endl;
	Person p2(p1);
	cout << "p2的年龄为：" << p2.age << "身高为：" << *p2.height << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}
