#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
	要求：
	1. 10 个员工指派部门
	2. 姓名，工资，职位（策划，美术，研发）
	3. 随机分配部门和工资
	4. multimap 进行信息插入 key(部门编号) value(员工)
	5. 分部门显示员工信息
	
	实现
	1. 使用 vector 放入10个员工
	2. 遍历 vector 容器，随机分组
	3. 分组后，放入 multimap 容易
	4. 分部门显示员工信息
*/

# define CEHUA 0
# define MEISHU 1
# define YANFA 2
class Worker
{
public:
	Worker() {}
	// 不能有有参构造
	Worker(string name, int salary) :m_Name(name), m_Salary(salary) {}

	string m_Name;
	int m_Salary;
};

// 测试
void Show_Workers(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t薪水：" << it->m_Salary << endl;
	}
	cout << "******************" << endl;
}

// 1. 创建员工
void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;  // 10000~19999

		// 放入容器
		v.push_back(worker);
	}
}

// 2. 员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 产生部门编号
		int depId = rand() % 3; // 0 1 2

		// 插入分组
		m.insert(make_pair(depId, *it));
	}
	
}

// 分组显示员工
void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;

	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int index = 0;
	int count = m.count(CEHUA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_Name << "\n薪水: " << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;

	cout << "美术部门" << endl;
	pos = m.find(MEISHU);
	index = 0;
	count = m.count(MEISHU);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_Name << "\n薪水: " << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;

	cout << "研发部门" << endl;
	pos = m.find(YANFA);
	index = 0;
	count = m.count(YANFA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_Name << "\n薪水: " << pos->second.m_Salary << endl;
	}
}
void test_01()
{
	// 创建员工
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