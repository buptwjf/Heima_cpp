#pragma once  // ��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include "worker.h"

class WorkerManager
{
public:

	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void Show_Menu();

	// ��������
	~WorkerManager();

	// �˳�����
	void exitSystem();

	// ����ְ��
	void Add_Emp();

	// �����ļ�
	void save();


	// ��¼�ļ���Ա��������
	int m_EmpNum;

	// Ա�������ָ��
	Worker** m_EmpArray;

	// ��־�ļ��Ƿ����  ���캯���и�ֵ
	bool m_FileIsEmpty;

	// ͳ������
	int get_EmpNum();

	// ��ʼ��ְ��
	void init_Emp();

	// ��ʾְ������
	void Show_Emp();

	// ɾ��ְ��
	void Del_Emp();

	// �ж�ְ���Ƿ����
	int IsExist(int id);

	// �޸�ְ��
	void Mod_Emp();

	// ����ְ��
	void Find_Emp();

	// ����ְ��������ţ�
	void Sort_Emp();

	// ����ļ�
	void Clean_File();
};