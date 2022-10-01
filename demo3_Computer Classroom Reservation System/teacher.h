#pragma once
#include <iostream>
using namespace std;

#include "Identity.h"
#include "globalFile.h"
#include "fstream"
#include "orderFile.h"
#include <vector>

// 教师类
class Teacher : public Identity
{
public:
	// 默认构造
	Teacher();

	// 有参构造（编号、姓名、密码）
	Teacher(int empId, string name, string pwd);

	// 显示菜单界面
	virtual void operMune();

	// 菜单功能
	void TeacherMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();

	// 教师职工
	int m_EmpId;
};


