#include <iostream>
#include "SpeechManager.h"
#include <string>
#include <ctime>
using namespace std;

int main()
{
	// 设置随机数种子
	srand((unsigned int)time(NULL));

	SpeechManger sm;

	while (true)
	{
		int choice;
		sm.show_Menu();
		cout << "*************************" << endl;

		 //显示测试
		//sm.showSpeaker();

		cout << "请输入你的选择：" << endl;
		cin >> choice;  // 接受用户的选项

		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;  // 开始比赛
		case 2:
			sm.showRecord();
			break;	// 查看记录
		case 3:
			sm.clearRecord();
			break;  // 清空比赛记录
		case 0:
			//sm.exitSystem();
			break;  // 退出比赛系统
		default:
			system("cls");  // 清屏
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}