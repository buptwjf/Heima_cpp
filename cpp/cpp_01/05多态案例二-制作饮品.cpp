#include <iostream>
using namespace std;
/*


*/


class AbstractDrinking
{
public:
	// 烧水
	virtual void Boil() = 0;

	// 冲泡
	virtual void Brew() = 0;

	// 倒入杯中
	virtual void PourIncup() = 0;

	// 加入佐料
	virtual void PutSomething() = 0;

	// 制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};


// 制作茶
class Tea : public AbstractDrinking
{
	// 烧水
	virtual void Boil()
	{
		cout << "煮茶水" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "泡茶" << endl;
	}

	// 倒入杯中
	virtual void PourIncup()
	{
		cout << "倒入茶杯" << endl;
	}

	// 加入佐料
	virtual void PutSomething()
	{
		cout << "加入茶佐料" << endl;
	}

	// 制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};

// 制作咖啡
class Coffe : public AbstractDrinking
{
	// 烧水
	virtual void Boil()
	{
		cout << "煮纯净水" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "泡咖啡" << endl;
	}

	// 倒入杯中
	virtual void PourIncup()
	{
		cout << "倒入咖啡杯" << endl;
	}

	// 加入佐料
	virtual void PutSomething()
	{
		cout << "加入糖" << endl;
	}

	// 制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};


// 制作函数
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