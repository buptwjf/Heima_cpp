#pragma once
#include <iostream>
using namespace std;

#include "Identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include <fstream>
#include "globalFile.h"
#include "computerRoom.h"

// 管理员类
class Manager : public Identity
{
public:
	// 默认构造
	Manager();

	// 有参构造（姓名、密码）
	Manager(string name, string pwd);

	// 菜单界面
	virtual void operMune();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 清空预约记录
	void clearFile();

	// 管理员菜单
	void managerMenu();

	// 初始化容器
	void initVector();

	// 检验重复 参数：(传入 id, 传入类型)  （true 代表有重复，false 代表没有重复)
	bool checkRepeat(int id, int type);

	// 初始化机房信息
	void initComputerRoom();


	// 学生容器
	vector<Student> vStu;

	// 教师容器
	vector<Teacher> vTea;

	// 机房容器
	vector<CoumputerRoom> vCom;


};


