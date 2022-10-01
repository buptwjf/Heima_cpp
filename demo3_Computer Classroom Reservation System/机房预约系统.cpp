#include <iostream>
using namespace std;

#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

// 登录功能
void LoginIn(string filename, int type)
{
	// 父类指针指向子类对象
	Identity* person = NULL;

	// 读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	// 判断文件是否村子
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	// 准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	// 判断身份
	if (type == 1)  // 学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		// 学生身份验证
		int fId; // 从文件中读取的 id
		string fName; // 从文件中获取的姓名
		string fPwd; // 文件中获取的密码

		// 逐行读取文件
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId;
			//cout << fName;
			//cout << fPwd;
			//cout << endl;

			// 与用户输入的信息做对比
			if (id == fId && fName == name && fPwd == pwd)
			{
				
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				// 进入学生身份的子菜单
				// 转换指针类型
				Student* stu = (Student*)person;

				stu->studentMenu();
				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师身份验证
		int fId; // 从文件中读取的 id
		string fName; // 从文件中获取的姓名
		string fPwd; // 文件中获取的密码

		// 逐行读取文件
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			cout << fId;
			cout << fName;
			cout << fPwd;
			cout << endl;

			// 与用户输入的信息做对比
			if (id == fId && fName == name && fPwd == pwd)
			{

				cout << "老师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				// 进入老师身份的子菜单
				// 转换指针类型
				Teacher* tea = (Teacher*)person;
				tea->TeacherMenu();
				return;
			}
		}
	}
	else if (type == 3)
	{
		// 验证管理员身份
		string fName; // 从文件中获取的姓名
		string fPwd; // 文件中获取的密码

		// 逐行读取文件
		while (ifs >> fName && ifs >> fPwd)
		{
			cout << fName;
			cout << fPwd;
			cout << endl;

			// 与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{

				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				// 将父类的指针强制转换成子类的指针
				Manager* man = (Manager*)person;

				man->managerMenu();
				// 进入管理员身份的子菜单
				return;
			}
		}
		
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择
		switch (select)
		{
		case 1:  // 学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  // 教师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  // 管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  // 退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误！，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


}