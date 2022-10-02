#include <iostream>
using namespace std;
/*
	1. 公共继承
	2. 保护继承
	3. 私有继承
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

class Son1 : public Base1
{
public:
	void func()
	{
		m_A = 10;  // 父类公共 -> 子类公共
		m_B = 10;  // 父类保护 -> 子类保护
		//m_C = 10;  // 父类私有 -> 子类无法使用
	}
};

void test_01()
{
	Son1 s1;
	s1.m_A = 100;     // 类外可以访问
	// s1.m_B = 100;  // 类外不可以访问  子类保护 -> 子类中 m_B 为私有
	s1.func();
}


// 保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2
{
public: 
	void func()
	{
	m_A = 10;  // 父类公共 -> 子类保护
	m_B = 10;  // 父类保护 -> 子类保护
	//m_C = 10;  // 父类私有 -> 子类无法使用
	}
};

void test_02()
{
	Son2 s2;
	// s2.m_A = 100;  // 类外不可以访问  子类保护
	// s2.m_B = 100;  // 类外不可以访问  子类保护
	s2.func();
}

// 私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 : private Base3
{
public:
	void func()
	{
		m_A = 10;  // 父类公共 -> 子类私有
		m_B = 10;  // 父类保护 -> 子类私有
		// m_C = 10;  // 父类私有 -> 子类无法使用
	}
};

class GrandSon : public Son3
{
public:
	void func()
	{
		// 在 Son3 中 m_A, m_B 为私有，GrandSon 不可访问
		// m_A = 100;
		// m_B = 100;
	}
};
void test_03()
{
	Son3 s3;
	// s2.m_A = 100;  // 类外不可以访问  子类私有 
	// s2.m_B = 100;  // 类外不可以访问  子类私有
	s3.func();
}



int main()
{
	test_01();
	test_02();
	test_03();
	system("pause");
	return 0;
}