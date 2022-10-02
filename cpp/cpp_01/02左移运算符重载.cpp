#include <iostream>
using namespace std;
/*


*/
class Person
{
	friend ostream& operator << (ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//  ���ó�Ա������������������� p.operator<<(cout),�򻯰汾 p << cout
	//  �������ó�Ա����ʵ������ << ���������Ϊ�޷�ʵ�� cout �����
	//void operator << (Person& p)
	//{

	//}
private:
	int m_A;
	int m_B;
};


// ֻ������ȫ�ֺ����������������������ֵ�� & ��Ϊ cout ֻ����һ��
ostream & operator << (ostream& cout, Person& p)  // ����operator << (cout, p)����Ϊ cout << p
{
	cout << "m_A: " << p.m_A << "\tm_B" << p.m_B;
	return cout;
}
void test_01()
{
	Person p(10, 20);
	cout << p; // �޷���� endl; 
	cout << "\n" << p << endl;  // ���ӷ���ֵ�����
}
int main()
{
	test_01();
	system("pause");
	return 0;
}