#include <iostream>
using namespace std;
/*
	1. 父类中所有的非静态成员属性都会被子类继承下去
	2. 父类的私有属性时被编译器隐藏了，因此访问不到
	3. 利用开发人员命令查看对象模型
		跳转盘符 D:
		cd 到具体路径下
		cl /d1 reportSingleClassLayout查看的类名 "所属文件名.cpp"
*/

// 公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;  
};

class Son : public Base1
{
public:
	int m_D;
};


void test_01()
{
	cout << "sizeof Son " << sizeof(Son) << endl;  // Son 占用 16 个字节

}


int main()
{
	test_01();
	system("pause");
	return 0;
}