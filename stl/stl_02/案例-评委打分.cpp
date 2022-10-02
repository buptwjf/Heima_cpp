#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

/*
	1. 有5名选手：选手ABCDE.
	2. 10个评委分别对每一名选手打分.
	3. 去除最高分,去除评委中最低分，取平均分。
*/

class Person
{
public:
	Person(string name, int score = 0): m_Name(name), m_Score(score) {}

	string m_Name;  // 姓名
	int m_Score;  // 平均分
};


// 创建 5 个 Perosn 并放入 vector 对象
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Person p(name);

		// 将创建的Perosn 放入 vector 容器
		v.push_back(p);
	}
}


// 打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 将评委的打分放入 deque 容器
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60~100
			d.push_back(score);
		}

		// 显示打分
		cout << "姓名: " << it->m_Name << "分数: ";
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		// 排序
		sort(d.begin(), d.end());

		// 去除最高分和最低分
		d.pop_back();
		d.pop_front();

		// 取平均分
		int sum = 0;
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		// 将平均分赋予每个人
		it->m_Score = avg;
	}
}

// 显示平均分
void showSore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t平均分：" << it->m_Score << endl;
	}
}


void test_01()
{
	// 随机数种子  #include <ctime>
	srand((unsigned int)time(NULL));
	
	// 1. 创建 5 名选手
	vector<Person> v;
	createPerson(v);
	// 2. 给5名选手打分
	setScore(v);
	// 3. 显示最后得分
	showSore(v);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}