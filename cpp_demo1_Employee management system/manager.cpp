#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "manager.h"

// ���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// ��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\t��λ" << this->getDeptId()
		<< "\t��λְ�𣺽����ϰ彻�������񣬲��·���ְ��" << endl;
}

// ��ȡ��λ����
string Manager::getDeptId()
{
	return "����";
}
