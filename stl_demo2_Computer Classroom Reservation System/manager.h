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

// ����Ա��
class Manager : public Identity
{
public:
	// Ĭ�Ϲ���
	Manager();

	// �вι��죨���������룩
	Manager(string name, string pwd);

	// �˵�����
	virtual void operMune();

	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��¼
	void clearFile();

	// ����Ա�˵�
	void managerMenu();

	// ��ʼ������
	void initVector();

	// �����ظ� ������(���� id, ��������)  ��true �������ظ���false ����û���ظ�)
	bool checkRepeat(int id, int type);

	// ��ʼ��������Ϣ
	void initComputerRoom();


	// ѧ������
	vector<Student> vStu;

	// ��ʦ����
	vector<Teacher> vTea;

	// ��������
	vector<CoumputerRoom> vCom;


};


