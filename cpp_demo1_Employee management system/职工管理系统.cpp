#include <iostream>
#include <string>
using namespace std;
#include "WorkerManager.h"
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"

//void test_01()
//{
//	Worker* em = new Employee(1, "张三", 1);
//	em->showInfo();
//	delete em;
//
//	Worker* ma = new Manager(2, "张三", 2);
//	ma->showInfo();
//	delete ma;
//	
//	Worker* bs = new Boss(3, "张三", 3);
//	bs->showInfo();
//	delete bs;
//}

int main()
{
	// test_01();
	WorkerManager wm;
	int choic = 0;
	//test_01();
	while (true)
	{
		// 展示菜单
		wm.Show_Menu();
		cout << "请输入你的选择: " << endl;
		cin >> choic;

		switch (choic)
		{
		case 0:  //退出系统
			wm.exitSystem();
			break;
		case 1:  //添加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			wm.Show_Emp();
			break;
		case 3:  //删除职工
			wm.Del_Emp();
			break;
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");  // 清屏操作
			break;
		}
	}
	system("pause");
	return 0;
}


