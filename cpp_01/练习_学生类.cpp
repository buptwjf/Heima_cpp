#include <iostream>
#include <string>
using namespace std;

// 设计学生类
class Student
{
public: // 公共权限
	// 属性 成员属性
	string m_Name;  // 姓名
	int m_Id;  // 学号
	
	// 行为 成员函数

	// 设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	// 设置学号
	void setId(int id)
	{
		m_Id = id;
	}
	

	// 显示姓名和学号
	void showStudent()
	{
		cout << "姓名：" << m_Name << "\t学号：" << m_Id << endl;
	}
	// 设置姓名
   
private:

};


int main()
{
	Student s1;
	s1.setName("张三");
	s1.setId(1);
	s1.showStudent();
	system("pause");
	return 0;
}
