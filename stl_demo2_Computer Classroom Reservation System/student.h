#pragma once
#include <iostream>
using namespace std;

#include "Identity.h"
#include "computerRoom.h"
#include <vector>
#include "globalFile.h"
#include <fstream>
#include "orderFile.h"

// ѧ����
class Student : public Identity
{
public:
	// Ĭ�Ϲ���
	Student();

	// �вι��죨ѧ�š����������룩
	Student(int id, string name, string pwd);

	// �˵�����
	virtual void operMune();

	// ѧ���˵�����
	void studentMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴����ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

	// ��ȡ������Ϣ
	void initComputer();

	// ��������
	vector<CoumputerRoom> vCom;
	
	// ѧ��ѧ��
	int m_Id;
};


