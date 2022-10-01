#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 加载机房信息
	initComputer();
}

void Student::operMune()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Student::studentMenu()
{
	while (true)
	{
		// 显示学生菜单
		operMune();

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:  // 申请预约
			applyOrder();
			break;
		case 2:  // 查看我的预约
			showMyOrder();
			break;
		case 3:  // 查看所有预约
			showAllOrder();
			break;
		case 4:  // 取消预约
			cancelOrder();
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

void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五! " << endl;
	cout << "请输入申请预约时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	// 日期
	int data = 0;
	// 时间段
	int interval = 0;
	// 房间
	int room = 0;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "出入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约时间" << endl;
	cout << "1. 上午" << endl;
	cout << "2. 下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << " 请选择机房 " << endl;
	cout << "1 号机房容量" << vCom[0].m_MaxNum << endl;
	cout << "2 号机房容量" << vCom[1].m_MaxNum << endl;
	cout << "3 号机房容量" << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	// 写入文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "name:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOrder()
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
		// string 使用 .c_str 转为 c风格的字符串
		// 再用 atoi 转为 int 类型 
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)  // 将文本读入的字符串类型转化为 int 型
		{
			cout << "预约日期：周" << of.m_orderData[i]["data"];
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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;
	int index = 1;

	// 遍历预约的文件
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			// 查询审核中或预约成功的jilu
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "已预约";
				}
				cout << status << endl;
			}
		}
	}

	if (v.size() == 0)
	{
		cout << "没有您的预约记录" << endl;
		return;
	}

	cout << "请输入取消的记录，0 代表返回" << endl;
	int select = 0;
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
				// cout << "记录所在的位置：" << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";  // 修改记录
				of.updateOrder();  // 更新记录
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}

void Student::initComputer()
{
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	CoumputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
}
