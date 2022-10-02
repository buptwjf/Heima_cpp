#include <iostream>
using namespace std;

class MyInteger
{
	//friend void test_01();
	friend ostream& operator << (ostream& cout, const MyInteger& myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}

	// 重载前置 ++ 运算符
	MyInteger & operator ++ ()  
	// 要加 & 防止进行 ++(++a) 第二次 ++ 失效，一直对一个数据进行递增操作
	{
		// 先进行 ++ 运算
		m_Num++;
		// 再将自身返回
		return *this;
	}

	// 重载后置 ++ 运算符
	MyInteger operator ++ (int)  // 占位参数：用于区分前置和后置递增,必须用 int
	{
		// 先记录一下当时的结果
		MyInteger temp = *this;
		// 后递增
		m_Num ++;
		// 最后将记录的结果返回
		return temp;
		// 不能返回引用，因为返回的是局部对象的值
	}

private:
	int m_Num;
};


// 重载 << 运算符，不能作为成员函数，cout 必须在左边
ostream& operator << (ostream & cout, const MyInteger & myint)
{
	cout << myint.m_Num;
	return cout;
}


void test_01()
{
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;
	cout << myint << endl;
}


void test_02()
{
	MyInteger myint;
	cout << myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
}



int main()
{
	test_01();
	cout << "***********" << endl;
	test_02();
	system("pause");
	return 0;
}