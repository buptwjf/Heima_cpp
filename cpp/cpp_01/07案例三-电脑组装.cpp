#include <iostream>
using namespace std;
/*

*/


// ����� CPU ��
class CPU
{
public:
	// ����ļ���
	virtual void calculate() = 0;
};

// ����� GPU ��
class GPU
{
public:
	// �������ʾ����
	virtual void display() = 0;
};

// ����� �ڴ�����
class Memory
{
public:
	// ����Ĵ洢����
	virtual void storage() = 0;
};

// ������
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

	// ��������
	void work()
	{
		// �������������
		m_cpu->calculate();

		m_gpu->display();
		
		m_mem->storage();
	}

private:
	CPU * m_cpu; // CPU ָ��
	GPU * m_gpu;  // GPU ָ��
	Memory * m_mem;  // �ڴ���ָ��

};

// ���峧��
// Intel ����
class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel\t �� CPU\t ��ʼ���㣡" << endl;
	}
};

class IntelGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Intel\t �� GPU\t ��ʼ��ʾ��" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel\t �� �ڴ���\t ��ʼ�洢��" << endl;
	}
};

// Lenovo ����
class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo\t �� CPU\t ��ʼ���㣡" << endl;
	}
};

class LenovoGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo\t �� GPU\t ��ʼ��ʾ��" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo\t �� �ڴ���\t ��ʼ�洢��" << endl;
	}
};

void test_01()
{
	// ��һ̨�������
	// �����ָ��ָ������Ķ���
	CPU * intelCpu = new IntelCPU;
	GPU * intelGpu = new IntelGPU;
	Memory * lenovoMemory = new LenovoMemory;
	
	// ������һ̨����
	cout << "��һ̨���Կ�ʼ����" << endl;
	Computer * com1 = new Computer(intelCpu, intelGpu, lenovoMemory);
	com1->work();
	delete com1;

	cout << "******************************" << endl;

	// �����ڶ�̨����
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	intelCpu = new IntelCPU;
	GPU* lenovoGpu = new LenovoGPU;
	Memory* intelMemory = new IntelMemory;
	Computer * com2 = new Computer(new IntelCPU, new LenovoGPU, new IntelMemory);
	com2->work();
	delete com2;  // �� Computer �������������ͷ�
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