#include <iostream>
#include "SpeechManager.h"
#include <string>
#include <ctime>
using namespace std;

int main()
{
	// �������������
	srand((unsigned int)time(NULL));

	SpeechManger sm;

	while (true)
	{
		int choice;
		sm.show_Menu();
		cout << "*************************" << endl;

		 //��ʾ����
		//sm.showSpeaker();

		cout << "���������ѡ��" << endl;
		cin >> choice;  // �����û���ѡ��

		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;  // ��ʼ����
		case 2:
			sm.showRecord();
			break;	// �鿴��¼
		case 3:
			sm.clearRecord();
			break;  // ��ձ�����¼
		case 0:
			//sm.exitSystem();
			break;  // �˳�����ϵͳ
		default:
			system("cls");  // ����
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}