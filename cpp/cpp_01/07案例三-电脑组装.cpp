#include <iostream>
using namespace std;
/*

*/


// 抽象的 CPU 类
class CPU
{
public:
	// 抽象的计算
	virtual void calculate() = 0;
};

// 抽象的 GPU 类
class GPU
{
public:
	// 抽象的显示函数
	virtual void display() = 0;
};

// 抽象的 内存条类
class Memory
{
public:
	// 抽象的存储函数
	virtual void storage() = 0;
};

// 电脑类
class Computer
{
public:
	Computer(CPU * cpu, GPU * gpu, Memory * mem)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_mem = mem;
	}

	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

	// 工作函数
	void work()
	{
		// 让零件工作起来
		m_cpu->calculate();

		m_gpu->display();
		
		m_mem->storage();
	}

private:
	CPU * m_cpu; // CPU 指针
	GPU * m_gpu;  // GPU 指针
	Memory * m_mem;  // 内存条指针

};

// 具体厂商
// Intel 厂商
class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel\t 的 CPU\t 开始计算！" << endl;
	}
};

class IntelGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Intel\t 的 GPU\t 开始显示！" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel\t 的 内存条\t 开始存储！" << endl;
	}
};

// Lenovo 厂商
class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo\t 的 CPU\t 开始计算！" << endl;
	}
};

class LenovoGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo\t 的 GPU\t 开始显示！" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo\t 的 内存条\t 开始存储！" << endl;
	}
};

void test_01()
{
	// 第一台电脑零件
	// 父类的指针指向子类的对象
	CPU * intelCpu = new IntelCPU;
	GPU * intelGpu = new IntelGPU;
	Memory * lenovoMemory = new LenovoMemory;
	
	// 创建第一台电脑
	cout << "第一台电脑开始工作" << endl;
	Computer * com1 = new Computer(intelCpu, intelGpu, lenovoMemory);
	com1->work();
	delete com1;

	cout << "******************************" << endl;

	// 创建第二台电脑
	cout << "第二台电脑开始工作" << endl;
	intelCpu = new IntelCPU;
	GPU* lenovoGpu = new LenovoGPU;
	Memory* intelMemory = new IntelMemory;
	Computer * com2 = new Computer(new IntelCPU, new LenovoGPU, new IntelMemory);
	com2->work();
	delete com2;  // 在 Computer 的析构函数中释放
}

void test_02()
{

}


int main()
{
	test_01();
	system("pause");
	return 0;
}