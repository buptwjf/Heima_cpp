#pragma once
#include <iostream>
using namespace std;

#include <vector>
#include "speaker.h"
#include <map>

class SpeechManger
{
public:
	// 比赛选手 容器 12 人
	vector <int> v1;

	// 第一轮晋级 容器 6 人
	vector <int> v2;

	// 胜利前三名 容器 3 人
	vector <int> v3;

	// 存放编号 及 对应选手 的容器
	map<int, Speaker> m_Speaker;

	// 比赛轮数
	int m_Index;

	// 判断文件是否为空
	bool fileIsEmpty;

	// 存放往届记录
	map<int, vector<string>> m_Record;

	// 构造函数
	SpeechManger();

	// 展示菜单
	void show_Menu();

	// 析构函数
	~SpeechManger();

	// 退出函数
	void exitSystem();

	// 初始化比赛属性
	void initSpeech();

	// 创建选手姓名和编号
	void creatSpeaker();

	// 初始化显示
	void showSpeaker();

	// 比赛开始 - 比赛流程控制
	void startSpeech();

	// 抽签
	void SpeechDraw();

	// 开始比赛
	void SpeechContest();

	// 显示这轮比赛的结果
	void ShowScore();

	// 保存比赛记录
	void saveRecord();

	// 读取记录
	void loadRecord();

	// 显示往届记录
	void showRecord();

	// 清空记录
	void clearRecord();
};