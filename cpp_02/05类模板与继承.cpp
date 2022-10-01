#include <iostream>
using namespace std;

/*
	如果子类继承的是父类的一个类模板，子类在声明时：
		1. 子类要指出父类的 T 类型
		2. 想灵活指定出父类中T的类型，子类也需变为类模板
*/


template <class T>
class Base
{
	T m;
};


//class Son : public Base  
// 错误， c++编译需要给子类分配内存，必须知道父类中 T 的类型才可以向下继承
class Son : public Base <int>
{
};


// 类模板继承类模板 ,可以用 T2 指定父类中的 T 类型
template <class T1, class T2>
class Son2 : public Base <T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};


void test_01()
{
	Son c;
}

void test_02()
{
	Son2 <int, char> child;
}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}