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
//	Worker* em = new Employee(1, "����", 1);
//	em->showInfo();
//	delete em;
//
//	Worker* ma = new Manager(2, "����", 2);
//	ma->showInfo();
//	delete ma;
//	
//	Worker* bs = new Boss(3, "����", 3);
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
		// չʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��: " << endl;
		cin >> choic;

		switch (choic)
		{
		case 0:  //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:  //���ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			wm.Show_Emp();
			break;
		case 3:  //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:  //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:  //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");  // ��������
			break;
		}
	}
	system("pause");
	return 0;
}


