#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

// ���캯��
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// ��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\t��λ" << this->getDeptId()
		<< "\t��λְ����ɾ�����������" << endl;
}

// ��ȡ��λ����
string Employee::getDeptId()
{
	return "ְ��";
}
