#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empId, string name, string pwd)
{
	// 初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMune()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Teacher::TeacherMenu()
{
	while (true)
	{
		// 显示老师菜单
		operMune();

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:  // 查看所有预约
			showAllOrder();
			break;
		case 2:  // 审核预约  
			validOrder();
			break;
		default:
			delete this;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "第" << i + 1 << "条： ";
		cout << " 预约日期：周" << of.m_orderData[i]["data"];
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["name"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.m_orderData[i]["roomId"];

		string status = " 状态：";
		// 0 取消预约 1 审核中 2 已预约 -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的记录如下" << endl;

	vector<int> v;
	int index = 1;

	// 遍历预约的文件
	for (int i = 0; i < of.m_Size; i++)
	{
		// 查询审核中的预约记录
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);  // 记录下对应的第几条记录
			cout << index++ << "、";
			cout << "预约日期：周" << of.m_orderData[i]["data"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderData[i]["roomId"];

			string status = " 状态：";
			// 0 取消预约 1 审核中 2 已预约 -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}

	if (v.size() == 0)
	{
		cout << "没有待审核的记录" << endl;
		return;
	}

	cout << "请输入审核的预约记录，0 代表返回" << endl;
	int select = 0;
	
	int ret = 0;  // 审核通过的标志位
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1. 通过" << endl;
				cout << "2. 不通过" << endl;

				cin >> ret;
				
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";  // 通过
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";  // 不通过
				}
				
				of.updateOrder();  // 更新记录
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}
