#pragma once
#include "SpeechManager.h"

#include <map>
#include <algorithm>
//#include <ctime>
#include <vector>
#include <deque>
#include <numeric>
#include <fstream>
#include <string>
void SpeechManger::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;

	cout << endl;
}

SpeechManger::SpeechManger()
{	
	// ��ʼ����������
	this->initSpeech();

	// ����ѡ�������ͱ��
	this->creatSpeaker();

	// ��ȡ�����¼
	this->loadRecord();

}

SpeechManger::~SpeechManger()
{

}

void SpeechManger::exitSystem()
{
	cout << " ��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManger::initSpeech()
{
	// ��֤����Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();

	// ��ʼ����������
	this->m_Index = 1;

	// ��ʼ����¼������Ҳ��գ� ÿ�ο�ʼ���¶��Ϳ�����
	// ������������ݵ�ʱ��ҲӦ�ð�������
	this->m_Record.clear();



}

void SpeechManger::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIKLM";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		// ��������ѡ�ֶ���
		Speaker sp;

		// 1. ����
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		// 2. ���  - �������� v1
		this->v1.push_back(10000 + i);

		// ����ź��������� map ������
		this->m_Speaker.insert(make_pair((i + 10000), sp));
	}
	
}

void SpeechManger::showSpeaker()
{
	for (map<int, Speaker>::iterator it = this->m_Speaker.begin(); it != this->m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< "\t����" << it->second.m_Name
			<< "\t��һ�ֳɼ�: " << it->second.m_Score[0]
			<< "\t�ڶ��ֳɼ�: " << it->second.m_Score[1] << endl;
	}
}

void SpeechManger::startSpeech()
{
	// ��һ�ֱ���

	// 1. ��ǩ
	SpeechDraw();

	// 2. ����
	SpeechContest();

	// 3. ��ʾ�������
	ShowScore();

	// �ڶ��ֱ���
	this->m_Index++;

	// 1. ��ǩ
	SpeechDraw();

	// 2. ����
	SpeechContest();

	// 3. ��ʾ���ս��
	ShowScore();

	// 4. �������
	saveRecord();

	// ���ñ���----ע�⣡ ���ﲻ�����½��й��캯������Ϊ m_Index ��������
	// ��ʼ����������
	this->initSpeech();
	// ����ѡ�������ͱ��
	this->creatSpeaker();
	// ��ȡ�����¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void SpeechManger::SpeechDraw()
{
	cout << "�� " << this->m_Index << " �ֱ���ѡ�ֳ�ǩ" << endl;
	cout << "---------------------------" << endl;
	cout << "��ǩ�������:" << endl;

	// ������������� ֱ�ӷŵ� main ��������
	//srand((unsigned int)time(NULL));

	// ��һ�ֱ���ʱ
	if (this->m_Index == 1 )
	{ 
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	// �ڶ��ֱ���ʱ
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "--------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManger::SpeechContest()
{
	cout << "----------------��" << this->m_Index << "�ֱ�����ʼ--------------------" << endl;;

	// ʹ����ʱ����������ѡ�ֵ� value ���(int) �� key �ɼ�(doubel)
	multimap<double, int, greater<int>> groupScore;

	// ��¼��Ա�� 6 ��Ϊһ��
	int num = 0;
	// ������Ա����ʱ����
	vector<int> v_Src;

	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// �������в���ѡ�֣����д��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		// ʹ�� deque �洢 10 ����ί�ķ���
		deque<double> d;
		
		// ÿ���˶�Ӧ 10 ����ί
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		
		sort(d.begin(), d.end(), greater<double>());  // ����
		d.pop_back();  // ȥ����ͷ�
		d.pop_front();  // ȥ����߷�

		double sum = accumulate(d.begin(), d.end(), 0.0f);  // ��ȡ�ܷ�
		double avg = sum / d.size();  // ����ƽ����

		// ���ÿ���˵�ƽ����   map[key]  ???
		//cout << "���: " << *it << "\t����: " << this->m_Speaker[*it].m_Name << "\t��ȡƽ����: " << avg << endl;

		// �洢�� map ������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		// �洢����ʱ���� 6��һ�飬ÿ�������ˣ����һ��
		groupScore.insert(make_pair(avg, *it));
		
		num++;

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "���������" << endl;
		
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				//cout << "��ţ�" << it->second << "\t������" << this->m_Speaker[it->second].m_Name << "\t�ɼ�" << it->first << endl;
				cout << "��ţ�" << it->second << "\t������" << this->m_Speaker[it->second].m_Name << "\t�ɼ�" << this->m_Speaker[it->second].m_Score[this->m_Index -1] << endl;
			}

			int count = 0;
			// ȡǰ���������� v2 ���� (���Ϊ�ڶ��ֽ���������� v3 ����)��
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v3.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	//	
	
}

void SpeechManger::ShowScore()
{
	cout << "------------��" << this->m_Index << "�ֽ�����ѡ����Ϣ����: -------------" << endl;
	// ��ʱ����
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}

	// ������ֱ����Ľ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "������" << m_Speaker[*it].m_Name << "�÷֣�" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
}

void SpeechManger::saveRecord()
{
	ofstream ofs;
	// ����� + ׷�� �ķ�ʽ���ļ�������д�����
	ofs.open("speech.csv", ios::out | ios::app);  

	// �� v3 ������д���ļ���
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "��¼�Ѿ�����" << endl;

	// ����һ���µļ�¼֮���ļ��Ͳ�Ϊ���ˡ�
	this->fileIsEmpty = false;
	system("pause");
	system("cls");
}

void SpeechManger::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�Ϊ��" << endl;	
		ifs.close();
		return;
	}

	// �ļ���Ϊ��
	this->fileIsEmpty = false;

	// ����ȡ�ĵ����ַ��Ż�ȥ
	ifs.putback(ch);

	string data;

	// Ĭ�ϴӵ� 0 �쿪ʼ
	int index = 0;
	
	while (ifs >> data)
	{
		//cout << data << endl;
		//10006, 90.3875, 10003, 82.55, 10004, 76.8625,
		
		vector<string> v;

		int pos = -1;  // �鵽 , λ�õı���
		int start = 0;


		while(true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				// û���ҵ�
				break;
			}

			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << "�� " <<it->first + 1 << " ��" << "�ھ����: " << it->second[0] << " ������" << it->second[1] << endl;
	}
}

void SpeechManger::showRecord()
{
	if (this->fileIsEmpty == true)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				"�ھ����" << this->m_Record[i][0] << "�÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ����" << this->m_Record[i][2] << "�÷֣�" << this->m_Record[i][3] << " "
				"�������" << this->m_Record[i][4] << "�÷֣�" << this->m_Record[i][5] << endl;
		}
	}


	system("pause");
	system("cls");
}

void SpeechManger::clearRecord()
{
	cout << "��ռ�¼ ��" << endl;
	cout << "1: ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs;
		ofs.open("speech.csv",ios::trunc);
		ofs.close();

		// ͬʱ��ʼ����������
		this->initSpeech();  // �������

		// ����ѡ�������ͱ��
		this->creatSpeaker();  // ���³�ʼ��ѡ��

		// ��ȡ�����¼
		this->loadRecord();  // this->fileIsEmpty ��Ϊ true
	}
	system("pause");
	system("cls");
}



