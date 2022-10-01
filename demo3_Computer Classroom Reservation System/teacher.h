#pragma once
#include <iostream>
using namespace std;

#include "Identity.h"
#include "globalFile.h"
#include "fstream"
#include "orderFile.h"
#include <vector>

// ��ʦ��
class Teacher : public Identity
{
public:
	// Ĭ�Ϲ���
	Teacher();

	// �вι��죨��š����������룩
	Teacher(int empId, string name, string pwd);

	// ��ʾ�˵�����
	virtual void operMune();

	// �˵�����
	void TeacherMenu();

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void validOrder();

	// ��ʦְ��
	int m_EmpId;
};


