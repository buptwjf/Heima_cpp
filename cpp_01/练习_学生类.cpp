#include <iostream>
#include <string>
using namespace std;

// ���ѧ����
class Student
{
public: // ����Ȩ��
	// ���� ��Ա����
	string m_Name;  // ����
	int m_Id;  // ѧ��
	
	// ��Ϊ ��Ա����

	// ��������
	void setName(string name)
	{
		m_Name = name;
	}
	// ����ѧ��
	void setId(int id)
	{
		m_Id = id;
	}
	

	// ��ʾ������ѧ��
	void showStudent()
	{
		cout << "������" << m_Name << "\tѧ�ţ�" << m_Id << endl;
	}
	// ��������
   
private:

};


int main()
{
	Student s1;
	s1.setName("����");
	s1.setId(1);
	s1.showStudent();
	system("pause");
	return 0;
}
