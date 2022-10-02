#include <iostream>
using namespace std;
/*


*/


class AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil() = 0;

	// ����
	virtual void Brew() = 0;

	// ���뱭��
	virtual void PourIncup() = 0;

	// ��������
	virtual void PutSomething() = 0;

	// ������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};


// ������
class Tea : public AbstractDrinking
{
	// ��ˮ
	virtual void Boil()
	{
		cout << "���ˮ" << endl;
	}

	// ����
	virtual void Brew()
	{
		cout << "�ݲ�" << endl;
	}

	// ���뱭��
	virtual void PourIncup()
	{
		cout << "����豭" << endl;
	}

	// ��������
	virtual void PutSomething()
	{
		cout << "���������" << endl;
	}

	// ������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};

// ��������
class Coffe : public AbstractDrinking
{
	// ��ˮ
	virtual void Boil()
	{
		cout << "�󴿾�ˮ" << endl;
	}

	// ����
	virtual void Brew()
	{
		cout << "�ݿ���" << endl;
	}

	// ���뱭��
	virtual void PourIncup()
	{
		cout << "���뿧�ȱ�" << endl;
	}

	// ��������
	virtual void PutSomething()
	{
		cout << "������" << endl;
	}

	// ������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};


// ��������
void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;  // delete
}
void test_01()
{
	doWork(new Tea);
	cout << "---------------------------------" << endl;
	doWork(new Coffe);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}