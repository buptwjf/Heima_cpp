#include <iostream>
using namespace std;
/*
	�̳еĺô������Լ����ظ��Ĵ���
	class A : class B;
	A ��Ϊ ���� �� ������
	B ��Ϊ ���� �� ����
*/

class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}

	void left()
	{
		cout << "Java, Python, C++...�����������б�" << endl;
	}
};

// Java ҳ��
class Java : public BasePage
{
public:
	void content()
	{
		cout << "Java ѧ����Ƶ" << endl;
	}
};

// Python ҳ��
class Python : public BasePage
{
public:
	void content()
	{
		cout << "Python ѧ����Ƶ" << endl;
	}
};

// C++ ҳ��
class CPP : public BasePage
{
public:
	void content()
	{
		cout << "C++ ѧ����Ƶ" << endl;
	}
};

void test_01()
{
	// Java ҳ��
	cout << "Java ��Ƶҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "-----------------------" << endl;
	// Python ҳ��
	cout << "Python ��Ƶҳ�����£� " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "-----------------------" << endl;
	// C++ ҳ��
	cout << "C++ ��Ƶҳ�����£� " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "-----------------------" << endl;
}
int main()
{
	test_01();
	system("pause");
	return 0;
}