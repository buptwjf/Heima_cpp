#include "workerManager.h"
#include <string.h>
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;


#include <fstream>
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// 1. 文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		
		// 初始化人数为 0
		this->m_EmpNum = 0;
		// 初始化指针为空
		this->m_EmpArray = NULL;
		// 初始化标志位为空
		this->m_FileIsEmpty = true;
		// 关闭文件
		ifs.close();
		return;
	}
	
	// 2. 文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())  // 文件读完了
	{
		// 文件为空
		cout << "文件为空 !" << endl;
		// 初始化人数为 0
		this->m_EmpNum = 0;
		// 初始化指针为空
		this->m_EmpArray = NULL;
		// 初始化标志位为空
		this->m_FileIsEmpty = true;
		// 关闭文件
		ifs.close();
		return;
	}
	
	// 3. 文件存在且不为空
	int num = this->get_EmpNum();
	cout << "职工个数为" << num << endl;
	// 更新成员属性
	this->m_EmpNum = num;
	
	// 根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 初始化职工数组
	init_Emp();

	// 测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工号： " << this->m_EmpArray[i]->m_Id 
	//		<< "\t职工姓名: " << this->m_EmpArray[i]->m_Name
	//		<< "\t部门编号: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		// 释放堆区所有的数据，并且置位 NULL
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];  // delete 对象的指针
			}
		}	
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


// 显示菜单
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// 退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);  // 退出系统
}

// 增加职工
void WorkerManager::Add_Emp()
{
	cout << "要增加的职工数量" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// 计算新空间的大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 将原有空间的内容放在新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:  // 普通员工
				worker = new Employee(id, name, 1);
			case 2:  // 经理
				worker = new Employee(id, name, 2);
			case 3:  // 老板
				worker = new Employee(id, name, 3);
			default:
				break;
			}

			// 插入数组
			newSpace[this->m_EmpNum + i] = worker;
		}

		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改指向新的空间
		this->m_EmpArray = newSpace;

		// 更新新的个数
		this->m_EmpNum = newSize;

		// 提示信息
		cout << "已添加" << addNum << "个新员工信息" << endl;

		// 设置职工文件不为空
		this->m_FileIsEmpty = false;

		// 保存到文件中
		this->save();
	}

	else
		cout << "输入有误" << endl;

	system("pause");
	system("cls");
}

// 保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  // 用输出的方式打开文件  -- 写文件

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

// 统计文件中的人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)  // 由于文件写入时候是中间隔一个空格
	{
		// 记录人数
		num++;
	}
	
	ifs.close();
	return num;
}

// 初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		// 根据不同部门的 dId 创建不同的对象
		if (dId == 1)  // 普通职工
		{
			worker = new Employee(id, name, dId);
		}
		
		if (dId == 2)  // 经理
		{
			worker = new Manager(id, name, dId);
		}

		if (dId == 3)  // 老板
		{
			worker = new Boss(id, name, dId);
		}

		// 存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

// 显示职工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

// 删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		// 按职工编号删除
		cout << "请输入要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index == -1)
		{
			cout << "不存在此职工" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();  // 同步数据到文件

			cout << "删除成功" << endl;
		}
	}

	system("pause");
	system("cls");

}

// 判断职工号是否存在
int WorkerManager::IsExist(int id)
{
	// 按照职工编号返回职工在数组中的位置，不存在返回 -1
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		// 按职工编号删除
		cout << "请输入要修改的职工编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);

		if (ret == -1)
		{
			cout << "不存在此职工" << endl;
		}
		else
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查找到" << id << "号职工, 请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新职位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// 更新到数组中
			this->m_EmpArray[ret] = worker;
			
			cout << "修改成功" << endl;

			// 保存到文件中
			this->save();
		}

		// 按任意键 清屏
		system("pause");
		system("cls");
	}
}

// 寻找职工（职工号/姓名）
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "请输入查找方式: " << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
	}

	int select = 0;
	cin >> select;

	if (select == 1) // 按职工号查找
	{
		int id;
		cout << "请输入职工编号" << endl;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			cout << "查找职工成功! 职工信息如下: " << endl;
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}

	else if (select == 2) // 按姓名查找
	{
		string name;
		cout << "请输入职工姓名" << endl;
		cin >> name;

		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				cout << "查找成功，职工编号为："
					<< this->m_EmpArray[i]->m_Id
					<< "\t信息如下：";

				flag = true;

				this->m_EmpArray[i]->showInfo();
			}
		}

		if (flag == false)
		{
			cout << "查无此人" << endl;
		}
	}


	else
	{
		cout << "输入选项有误，请重新输入。" << endl;
	}

	system("pause");
	system("cls");

}

// 排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)  // 升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)  // 每趟选出最小值
					{
						minOrMax = j;
					}
				}

				if (select == 2)  // 降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)  // 每趟选出最大值
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
	
}

// 清空函数
void WorkerManager::Clean_File()
{
	cout << "确认清空" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 删除文件并重新创建 ios::trunc
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();


		if (this->m_EmpArray != NULL)
		{
			// 释放堆区所有的数据，并且置位 NULL
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];  // delete 对象的指针
				}
			}
		}

		// 修改成员属性
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}


