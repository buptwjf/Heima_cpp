#include <iostream>
using namespace std;
/*
	分别利用普通的写法和多态技术实现计算器
*/

// 普通的写法
class Calculator
{
public:
	int  getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		// 如果想扩展新的功能，需要修改密码
		// 在真实的开发中 提倡 开闭原则
		// 开闭原则：对扩展进行开放，对修改进行关闭
	}
	int m_Num1;  // 操作数 1 
	int m_Num2;  // 操作数 2

};
void test_01()
{
	// 创建计算器对象
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " - " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " * " << c.getResult("*") << endl;
}

// 利用多态实现计算器
/*
	多态的好处
		1. 组织结构清晰
		2. 可读性强
		3. 避免出错
		4. 保护好源码
*/

// 实现计算器的抽象类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;

};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};


// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test_02()
{
	// 多态的使用：父类的引用（指针)，指向子类的对象

	// 加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << "= " << abc->getResult() << endl;
	// 用完后 delete
	delete abc;

	// 减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << "= " << abc->getResult() << endl;
	// 用完后 delete
	delete abc;

	// 乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	// 用完后 delete
	delete abc;
}


int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}