#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ���ػ�����Ϣ
	initComputer();
}

void Student::operMune()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::studentMenu()
{
	while (true)
	{
		// ��ʾѧ���˵�
		operMune();

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:  // ����ԤԼ
			applyOrder();
			break;
		case 2:  // �鿴�ҵ�ԤԼ
			showMyOrder();
			break;
		case 3:  // �鿴����ԤԼ
			showAllOrder();
			break;
		case 4:  // ȡ��ԤԼ
			cancelOrder();
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

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������! " << endl;
	cout << "����������ԤԼʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	// ����
	int data = 0;
	// ʱ���
	int interval = 0;
	// ����
	int room = 0;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼʱ��" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << " ��ѡ����� " << endl;
	cout << "1 �Ż�������" << vCom[0].m_MaxNum << endl;
	cout << "2 �Ż�������" << vCom[1].m_MaxNum << endl;
	cout << "3 �Ż�������" << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	// д���ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "name:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		// string ʹ�� .c_str תΪ c�����ַ���
		// ���� atoi תΪ int ���� 
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)  // ���ı�������ַ�������ת��Ϊ int ��
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];

			string status = " ״̬��";  
			// 0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "��" << i + 1 << "���� ";
		cout << " ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["name"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];

		string status = " ״̬��";
		// 0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;

	// ����ԤԼ���ļ�
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			// ��ѯ����л�ԤԼ�ɹ���jilu
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);  // ��¼�¶�Ӧ�ĵڼ�����¼
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];

				string status = " ״̬��";
				// 0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
				cout << status << endl;
			}
		}
	}

	if (v.size() == 0)
	{
		cout << "û������ԤԼ��¼" << endl;
		return;
	}

	cout << "������ȡ���ļ�¼��0 ������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				// cout << "��¼���ڵ�λ�ã�" << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";  // �޸ļ�¼
				of.updateOrder();  // ���¼�¼
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

void Student::initComputer()
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
