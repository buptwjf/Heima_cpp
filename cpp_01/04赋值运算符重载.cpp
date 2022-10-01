#include <iostream>
using namespace std;

/*
	编译器默认提供的 = 是浅拷贝，如果有数据放在堆区，那么就会出错
	因此需要进行 = 重载，进行深拷贝
*/
class Person
{
public:
	Person(int age)
	{
		// 将年龄数据开辟到堆区
		m_Age = new int(age);
	}

	~Person()
	{
		m_Age != NULL;
		delete m_Age;  // 删除 m_Age 指向的内存
		m_Age = NULL;
	}

	// 重载赋值运算符
	Person& operator = (Person& p)  
	{
		// 编译器提供的是浅拷贝
		// m_Age = p.m_Age
		// 返回值 Person& 为了实现 p3 = p2 = p1

		// 应该先判断是否有属性在堆区，如果有先释放干净，
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;	
		}
		// 在开辟新的空间，做深拷贝
		m_Age = new int(*p.m_Age);
		return *this;
	}

	int* m_Age;
};

void test_01()
{
	Person p1(18);
	cout << "p1 的年龄为: " << *p1.m_Age << endl;
	Person p2(20);
	cout << "p2 的年龄为: " << *p2.m_Age << endl;

	p2 = p1;  // 赋值操作
	// 做浅拷贝，相当于把 p1.m_Age 给 p2.m_Age，两指针共同指向堆区里的 18 
	// 因此当有析构函数的时候，会对内存 delete 两次，导致报错
	cout << "p1 的年龄为: " << *p1.m_Age << endl;
	cout << "p2 的年龄为: " << *p2.m_Age << endl;
}

void test_02()
{
	Person p1(18);
	Person p2(20);
	Person p3(10);
	p3 = p2 = p1;
	cout << "p1 的年龄为: " << *p1.m_Age << endl;  // 18
	cout << "p2 的年龄为: " << *p2.m_Age << endl;  // 18
	cout << "p3 的年龄为: " << *p3.m_Age << endl;  // 18
}

int main()
{
	test_01();
	cout << "**************" << endl;
	test_02();
	system("pause");
	return 0;
}