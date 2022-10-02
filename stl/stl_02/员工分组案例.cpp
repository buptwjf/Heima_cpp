#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
	Ҫ��
	1. 10 ��Ա��ָ�ɲ���
	2. ���������ʣ�ְλ���߻����������з���
	3. ������䲿�ź͹���
	4. multimap ������Ϣ���� key(���ű��) value(Ա��)
	5. �ֲ�����ʾԱ����Ϣ
	
	ʵ��
	1. ʹ�� vector ����10��Ա��
	2. ���� vector �������������
	3. ����󣬷��� multimap ����
	4. �ֲ�����ʾԱ����Ϣ
*/

# define CEHUA 0
# define MEISHU 1
# define YANFA 2
class Worker
{
public:
	Worker() {}
	// �������вι���
	Worker(string name, int salary) :m_Name(name), m_Salary(salary) {}

	string m_Name;
	int m_Salary;
};

// ����
void Show_Workers(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << it->m_Name << "\tнˮ��" << it->m_Salary << endl;
	}
	cout << "******************" << endl;
}

// 1. ����Ա��
void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;  // 10000~19999

		// ��������
		v.push_back(worker);
	}
}

// 2. Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// �������ű��
		int depId = rand() % 3; // 0 1 2

		// �������
		m.insert(make_pair(depId, *it));
	}
	
}

// ������ʾԱ��
void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻�����" << endl;

	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int index = 0;
	int count = m.count(CEHUA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����: " << pos->second.m_Name << "\nнˮ: " << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;

	cout << "��������" << endl;
	pos = m.find(MEISHU);
	index = 0;
	count = m.count(MEISHU);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����: " << pos->second.m_Name << "\nнˮ: " << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;

	cout << "�з�����" << endl;
	pos = m.find(YANFA);
	index = 0;
	count = m.count(YANFA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����: " << pos->second.m_Name << "\nнˮ: " << pos->second.m_Salary << endl;
	}
}
void test_01()
{
	// ����Ա��
	vector<Worker> vworker;
	creatWorker(vworker);
	//Show_Workers(vworker);
	cout << vworker.size() << endl;
	multimap<int, Worker> mworker;
	setGroup(vworker, mworker);
	showWorkerByGroup(mworker);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}