#include "workerManager.h"
#include <string.h>
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;


#include <fstream>
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// 1. �ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		
		// ��ʼ������Ϊ 0
		this->m_EmpNum = 0;
		// ��ʼ��ָ��Ϊ��
		this->m_EmpArray = NULL;
		// ��ʼ����־λΪ��
		this->m_FileIsEmpty = true;
		// �ر��ļ�
		ifs.close();
		return;
	}
	
	// 2. �ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())  // �ļ�������
	{
		// �ļ�Ϊ��
		cout << "�ļ�Ϊ�� !" << endl;
		// ��ʼ������Ϊ 0
		this->m_EmpNum = 0;
		// ��ʼ��ָ��Ϊ��
		this->m_EmpArray = NULL;
		// ��ʼ����־λΪ��
		this->m_FileIsEmpty = true;
		// �ر��ļ�
		ifs.close();
		return;
	}
	
	// 3. �ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	// ���³�Ա����
	this->m_EmpNum = num;
	
	// ����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ��ʼ��ְ������
	init_Emp();

	// ���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id 
	//		<< "\tְ������: " << this->m_EmpArray[i]->m_Name
	//		<< "\t���ű��: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		// �ͷŶ������е����ݣ�������λ NULL
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];  // delete �����ָ��
			}
		}	
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


// ��ʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// �˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);  // �˳�ϵͳ
}

// ����ְ��
void WorkerManager::Add_Emp()
{
	cout << "Ҫ���ӵ�ְ������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// �����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ�пռ�����ݷ����¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// ����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:  // ��ͨԱ��
				worker = new Employee(id, name, 1);
			case 2:  // ����
				worker = new Employee(id, name, 2);
			case 3:  // �ϰ�
				worker = new Employee(id, name, 3);
			default:
				break;
			}

			// ��������
			newSpace[this->m_EmpNum + i] = worker;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		// ����ָ���µĿռ�
		this->m_EmpArray = newSpace;

		// �����µĸ���
		this->m_EmpNum = newSize;

		// ��ʾ��Ϣ
		cout << "�����" << addNum << "����Ա����Ϣ" << endl;

		// ����ְ���ļ���Ϊ��
		this->m_FileIsEmpty = false;

		// ���浽�ļ���
		this->save();
	}

	else
		cout << "��������" << endl;

	system("pause");
	system("cls");
}

// �����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  // ������ķ�ʽ���ļ�  -- д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

// ͳ���ļ��е�����
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)  // �����ļ�д��ʱ�����м��һ���ո�
	{
		// ��¼����
		num++;
	}
	
	ifs.close();
	return num;
}

// ��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		// ���ݲ�ͬ���ŵ� dId ������ͬ�Ķ���
		if (dId == 1)  // ��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		
		if (dId == 2)  // ����
		{
			worker = new Manager(id, name, dId);
		}

		if (dId == 3)  // �ϰ�
		{
			worker = new Boss(id, name, dId);
		}

		// �����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}

// ��ʾְ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

// ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		// ��ְ�����ɾ��
		cout << "������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index == -1)
		{
			cout << "�����ڴ�ְ��" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();  // ͬ�����ݵ��ļ�

			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");

}

// �ж�ְ�����Ƿ����
int WorkerManager::IsExist(int id)
{
	// ����ְ����ŷ���ְ���������е�λ�ã������ڷ��� -1
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// �޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		// ��ְ�����ɾ��
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);

		if (ret == -1)
		{
			cout << "�����ڴ�ְ��" << endl;
		}
		else
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "���ҵ�" << id << "��ְ��, ��������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "��������ְλ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// ���µ�������
			this->m_EmpArray[ret] = worker;
			
			cout << "�޸ĳɹ�" << endl;

			// ���浽�ļ���
			this->save();
		}

		// ������� ����
		system("pause");
		system("cls");
	}
}

// Ѱ��ְ����ְ����/������
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ: " << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
	}

	int select = 0;
	cin >> select;

	if (select == 1) // ��ְ���Ų���
	{
		int id;
		cout << "������ְ�����" << endl;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			cout << "����ְ���ɹ�! ְ����Ϣ����: " << endl;
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}

	else if (select == 2) // ����������
	{
		string name;
		cout << "������ְ������" << endl;
		cin >> name;

		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				cout << "���ҳɹ���ְ�����Ϊ��"
					<< this->m_EmpArray[i]->m_Id
					<< "\t��Ϣ���£�";

				flag = true;

				this->m_EmpArray[i]->showInfo();
			}
		}

		if (flag == false)
		{
			cout << "���޴���" << endl;
		}
	}


	else
	{
		cout << "����ѡ���������������롣" << endl;
	}

	system("pause");
	system("cls");

}

// ����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)  // ����
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)  // ÿ��ѡ����Сֵ
					{
						minOrMax = j;
					}
				}

				if (select == 2)  // ����
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)  // ÿ��ѡ�����ֵ
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
	
}

// ��պ���
void WorkerManager::Clean_File()
{
	cout << "ȷ�����" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// ɾ���ļ������´��� ios::trunc
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();


		if (this->m_EmpArray != NULL)
		{
			// �ͷŶ������е����ݣ�������λ NULL
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];  // delete �����ָ��
				}
			}
		}

		// �޸ĳ�Ա����
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		cout << "��ճɹ�" << endl;
	}

	system("pause");
	system("cls");
}


