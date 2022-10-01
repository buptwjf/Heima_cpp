#include "manager.h"


Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ������
	this->initVector();

	// ��ȡ������Ϣ
	initComputerRoom();
}

void Manager::operMune()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "��������ӵ��˺�����" << endl;
	cout << "1. ���ѧ��" << endl;
	cout << "2. �����ʦ" << endl;

	string fileName;  // �������ļ���
	string tip;  // ��ʾ id ��

	ofstream ofs;  // �ļ���������
	
	int select = 0;
	cin >> select;  // �����û���ѡ��
	string errorTip;  // �ظ�������ʾ

	if (select == 1)
	{
		cout << "���ѧ����Ϣ" << endl;
		fileName = STUDENT_FILE;
		tip = "������ѧ�����";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		cout << "�����ʦ��Ϣ" << endl;
		fileName = TEACHER_FILE;
		tip = "������ְ�����";
		errorTip = "ְ�����ظ�������������";
	}

	// ����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;  // ѧ��/ְ����
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret)  // ���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	// ���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ� " << endl;

	system("pause");
	system("cls");
	ofs.close();
}

 //�º���
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}



void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1. �鿴����ѧ��" << endl;
	cout << "2. �鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<CoumputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()
{
	// ��������յ�ģʽ���ļ�
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�! " << endl;
	system("pause");
	system("cls");
}

void Manager::managerMenu()
{
	while (true)
	{
		// ����Ա�˵�
		operMune();

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			this->addPerson();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			this->showPerson();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "�鿴����" << endl;
			this->showComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			this->clearFile();
			break;
		default:
			delete this;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Manager::initVector()
{
	// ��ȡѧ���ļ�
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	
	// ѧ����ʼ��
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ: " << vStu.size() << endl;
	ifs.close();  

	// ��ȡ��ʦ�ļ�
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ʧ��" << endl;
		return;
	}
	
	// ��ʦ��ʼ��
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ: " << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{	
	// �ж�ѧ��ѧ�������ظ�
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}

	// �ж���ʦְ���������ظ�
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::initComputerRoom()
{
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	CoumputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
}