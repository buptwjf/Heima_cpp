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
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;

	cout << endl;
}

SpeechManger::SpeechManger()
{	
	// 初始化比赛属性
	this->initSpeech();

	// 创建选手姓名和编号
	this->creatSpeaker();

	// 获取往届记录
	this->loadRecord();

}

SpeechManger::~SpeechManger()
{

}

void SpeechManger::exitSystem()
{
	cout << " 欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManger::initSpeech()
{
	// 保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();

	// 初始化比赛轮数
	this->m_Index = 1;

	// 初始化记录容器，也清空， 每次开始重新读就可以了
	// 在情况所有内容的时候，也应该把这个清空
	this->m_Record.clear();



}

void SpeechManger::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIKLM";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		// 创建单个选手对象
		Speaker sp;

		// 1. 姓名
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		// 2. 编号  - 放入容器 v1
		this->v1.push_back(10000 + i);

		// 将编号和姓名放入 map 容器中
		this->m_Speaker.insert(make_pair((i + 10000), sp));
	}
	
}

void SpeechManger::showSpeaker()
{
	for (map<int, Speaker>::iterator it = this->m_Speaker.begin(); it != this->m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< "\t姓名" << it->second.m_Name
			<< "\t第一轮成绩: " << it->second.m_Score[0]
			<< "\t第二轮成绩: " << it->second.m_Score[1] << endl;
	}
}

void SpeechManger::startSpeech()
{
	// 第一轮比赛

	// 1. 抽签
	SpeechDraw();

	// 2. 比赛
	SpeechContest();

	// 3. 显示晋级结果
	ShowScore();

	// 第二轮比赛
	this->m_Index++;

	// 1. 抽签
	SpeechDraw();

	// 2. 比赛
	SpeechContest();

	// 3. 显示最终结果
	ShowScore();

	// 4. 保存分数
	saveRecord();

	// 重置比赛----注意！ 这里不能重新进行构造函数，因为 m_Index 不能重置
	// 初始化比赛属性
	this->initSpeech();
	// 创建选手姓名和编号
	this->creatSpeaker();
	// 获取往届记录
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManger::SpeechDraw()
{
	cout << "第 " << this->m_Index << " 轮比赛选手抽签" << endl;
	cout << "---------------------------" << endl;
	cout << "抽签结果如下:" << endl;

	// 设置随机数种子 直接放到 main 函数下面
	//srand((unsigned int)time(NULL));

	// 第一轮比赛时
	if (this->m_Index == 1 )
	{ 
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	// 第二轮比赛时
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
	cout << "----------------第" << this->m_Index << "轮比赛开始--------------------" << endl;;

	// 使用临时容器，保存选手的 value 编号(int) 和 key 成绩(doubel)
	multimap<double, int, greater<int>> groupScore;

	// 记录人员数 6 人为一组
	int num = 0;
	// 比赛人员的临时容器
	vector<int> v_Src;

	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// 遍历所有参赛选手，进行打分
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		// 使用 deque 存储 10 个评委的分数
		deque<double> d;
		
		// 每个人对应 10 个评委
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		
		sort(d.begin(), d.end(), greater<double>());  // 排序
		d.pop_back();  // 去掉最低分
		d.pop_front();  // 去掉最高分

		double sum = accumulate(d.begin(), d.end(), 0.0f);  // 获取总分
		double avg = sum / d.size();  // 计算平均分

		// 输出每个人的平均分   map[key]  ???
		//cout << "编号: " << *it << "\t姓名: " << this->m_Speaker[*it].m_Name << "\t获取平均分: " << avg << endl;

		// 存储到 map 容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		// 存储到临时容器 6人一组，每到六个人，输出一次
		groupScore.insert(make_pair(avg, *it));
		
		num++;

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组比赛名次" << endl;
		
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				//cout << "编号：" << it->second << "\t姓名：" << this->m_Speaker[it->second].m_Name << "\t成绩" << it->first << endl;
				cout << "编号：" << it->second << "\t姓名：" << this->m_Speaker[it->second].m_Name << "\t成绩" << this->m_Speaker[it->second].m_Score[this->m_Index -1] << endl;
			}

			int count = 0;
			// 取前三名，放入 v2 容器 (如果为第二轮结束，则放入 v3 容器)，
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
	cout << "------------第" << this->m_Index << "轮晋级的选手信息如下: -------------" << endl;
	// 临时容器
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}

	// 输出此轮比赛的结果
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "姓名：" << m_Speaker[*it].m_Name << "得分：" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
}

void SpeechManger::saveRecord()
{
	ofstream ofs;
	// 用输出 + 追加 的方式打开文件，进行写入操作
	ofs.open("speech.csv", ios::out | ios::app);  

	// 将 v3 的数据写入文件中
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "记录已经保存" << endl;

	// 当有一个新的记录之后，文件就不为空了。
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
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "文件为空" << endl;	
		ifs.close();
		return;
	}

	// 文件不为空
	this->fileIsEmpty = false;

	// 将读取的单个字符放回去
	ifs.putback(ch);

	string data;

	// 默认从第 0 届开始
	int index = 0;
	
	while (ifs >> data)
	{
		//cout << data << endl;
		//10006, 90.3875, 10003, 82.55, 10004, 76.8625,
		
		vector<string> v;

		int pos = -1;  // 查到 , 位置的变量
		int start = 0;


		while(true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				// 没有找到
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
		cout << "第 " <<it->first + 1 << " 届" << "冠军编号: " << it->second[0] << " 分数：" << it->second[1] << endl;
	}
}

void SpeechManger::showRecord()
{
	if (this->fileIsEmpty == true)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" <<
				"冠军编号" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1] << " "
				"亚军编号" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << " "
				"季军编号" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl;
		}
	}


	system("pause");
	system("cls");
}

void SpeechManger::clearRecord()
{
	cout << "清空记录 ？" << endl;
	cout << "1: 确认" << endl;
	cout << "2：取消" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs;
		ofs.open("speech.csv",ios::trunc);
		ofs.close();

		// 同时初始化比赛属性
		this->initSpeech();  // 清空容器

		// 创建选手姓名和编号
		this->creatSpeaker();  // 从新初始化选手

		// 获取往届记录
		this->loadRecord();  // this->fileIsEmpty 置为 true
	}
	system("pause");
	system("cls");
}



