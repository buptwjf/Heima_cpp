#pragma once
#include <iostream>
using namespace std;

// ��ݳ�����
class Identity
{
public:

	// �����˵�
	virtual void operMune() = 0;

	string m_Name;  // �û���
	string m_Pwd;  // ����
};