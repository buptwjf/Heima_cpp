#pragma once
#include <iostream>
using namespace std;

#include <vector>
#include "speaker.h"
#include <map>

class SpeechManger
{
public:
	// ����ѡ�� ���� 12 ��
	vector <int> v1;

	// ��һ�ֽ��� ���� 6 ��
	vector <int> v2;

	// ʤ��ǰ���� ���� 3 ��
	vector <int> v3;

	// ��ű�� �� ��Ӧѡ�� ������
	map<int, Speaker> m_Speaker;

	// ��������
	int m_Index;

	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	// ��������¼
	map<int, vector<string>> m_Record;

	// ���캯��
	SpeechManger();

	// չʾ�˵�
	void show_Menu();

	// ��������
	~SpeechManger();

	// �˳�����
	void exitSystem();

	// ��ʼ����������
	void initSpeech();

	// ����ѡ�������ͱ��
	void creatSpeaker();

	// ��ʼ����ʾ
	void showSpeaker();

	// ������ʼ - �������̿���
	void startSpeech();

	// ��ǩ
	void SpeechDraw();

	// ��ʼ����
	void SpeechContest();

	// ��ʾ���ֱ����Ľ��
	void ShowScore();

	// ���������¼
	void saveRecord();

	// ��ȡ��¼
	void loadRecord();

	// ��ʾ�����¼
	void showRecord();

	// ��ռ�¼
	void clearRecord();
};