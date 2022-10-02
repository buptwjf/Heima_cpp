#pragma once  // 防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"

class WorkerManager
{
public:

	// 构造函数
	WorkerManager();

	// 展示菜单
	void Show_Menu();

	// 析构函数
	~WorkerManager();

	// 退出功能
	void exitSystem();

	// 增加职工
	void Add_Emp();

	// 保存文件
	void save();


	// 记录文件中员工的人数
	int m_EmpNum;

	// 员工数组的指针
	Worker** m_EmpArray;

	// 标志文件是否存在  构造函数中赋值
	bool m_FileIsEmpty;

	// 统计人数
	int get_EmpNum();

	// 初始化职工
	void init_Emp();

	// 显示职工人数
	void Show_Emp();

	// 删除职工
	void Del_Emp();

	// 判断职工是否存在
	int IsExist(int id);

	// 修改职工
	void Mod_Emp();

	// 查找职工
	void Find_Emp();

	// 排序职工（按编号）
	void Sort_Emp();

	// 清空文件
	void Clean_File();
};