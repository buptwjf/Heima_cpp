#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

/*
	1. ��5��ѡ�֣�ѡ��ABCDE.
	2. 10����ί�ֱ��ÿһ��ѡ�ִ��.
	3. ȥ����߷�,ȥ����ί����ͷ֣�ȡƽ���֡�
*/

class Person
{
public:
	Person(string name, int score = 0): m_Name(name), m_Score(score) {}

	string m_Name;  // ����
	int m_Score;  // ƽ����
};


// ���� 5 �� Perosn ������ vector ����
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Person p(name);

		// ��������Perosn ���� vector ����
		v.push_back(p);
	}
}


// ���
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����ί�Ĵ�ַ��� deque ����
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60~100
			d.push_back(score);
		}

		// ��ʾ���
		cout << "����: " << it->m_Name << "����: ";
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		// ����
		sort(d.begin(), d.end());

		// ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		// ȡƽ����
		int sum = 0;
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		// ��ƽ���ָ���ÿ����
		it->m_Score = avg;
	}
}

// ��ʾƽ����
void showSore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << it->m_Name << "\tƽ���֣�" << it->m_Score << endl;
	}
}


void test_01()
{
	// ���������  #include <ctime>
	srand((unsigned int)time(NULL));
	
	// 1. ���� 5 ��ѡ��
	vector<Person> v;
	createPerson(v);
	// 2. ��5��ѡ�ִ��
	setScore(v);
	// 3. ��ʾ���÷�
	showSore(v);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}