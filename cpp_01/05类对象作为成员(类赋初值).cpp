#include <iostream>
#include <string>
using namespace std;

// �������Ϊ���Ա
class Phone
{
public:
	Phone(string pName)
	{
		m_pName = pName;  // ������Phone���в������캯��
		cout << "Phone �Ĺ��캯��" << endl;
	}

	string m_pName;
	~Phone() {
		cout << "Phone����������" << endl;
	}
};

class Person
{
public:
	// ��һ���൱�ڣ�Phone m_Phone = pName; ����ת����
	Person(string name, string pName): m_Name(name), m_Phone(pName)  //�ȹ���Phone���ٹ���Person
	{
		cout << "Person �Ĺ��캯��" << endl;
	}
	~Person() {
		cout << "Person����������" << endl;  // ������ Person�������� Phone
	}

	// ����
	string m_Name;
	Phone m_Phone;
};

void test_01()
{
	Person p("����", "iphone max");
	cout << p.m_Name << "����" << p.m_Phone.m_pName << "�ֻ�" << endl;
}

int main()
{
	test_01();
	system("pause");
	return 0;
}