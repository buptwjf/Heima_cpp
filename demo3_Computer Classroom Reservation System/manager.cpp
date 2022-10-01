#include "manager.h"


Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 初始化容器
	this->initVector();

	// 获取机房信息
	initComputerRoom();
}

void Manager::operMune()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加的账号类型" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 添加老师" << endl;

	string fileName;  // 操作的文件名
	string tip;  // 提示 id 号

	ofstream ofs;  // 文件操作对象
	
	int select = 0;
	cin >> select;  // 接受用户的选项
	string errorTip;  // 重复错误提示

	if (select == 1)
	{
		cout << "添加学生信息" << endl;
		fileName = STUDENT_FILE;
		tip = "请输入学生编号";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		cout << "添加老师信息" << endl;
		fileName = TEACHER_FILE;
		tip = "请输入职工编号";
		errorTip = "职工号重复，请重新输入";
	}

	// 利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;  // 学号/职工号
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret)  // 有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	// 向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功 " << endl;

	system("pause");
	system("cls");
	ofs.close();
}

 //仿函数
void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}



void Manager::showPerson()
{
	cout << "请选择查看得内容：" << endl;
	cout << "1. 查看所有学生" << endl;
	cout << "2. 查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生的信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师的信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<CoumputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " 机房最大容量" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()
{
	// 重新以清空的模式打开文件
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功! " << endl;
	system("pause");
	system("cls");
}

void Manager::managerMenu()
{
	while (true)
	{
		// 管理员菜单
		operMune();

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			this->addPerson();
			break;
		case 2:
			cout << "查看账号" << endl;
			this->showPerson();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "查看机房" << endl;
			this->showComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			this->clearFile();
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

void Manager::initVector()
{
	// 读取学生文件
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件打开失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	
	// 学生初始化
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "当前学生数量为: " << vStu.size() << endl;
	ifs.close();  

	// 读取老师文件
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "老师文件打开失败" << endl;
		return;
	}
	
	// 老师初始化
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "当前老师数量为: " << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{	
	// 判断学生学号有无重复
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}

	// 判断老师职工号有无重复
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::initComputerRoom()
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