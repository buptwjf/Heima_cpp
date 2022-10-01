#include <iostream>
#include <string>
using namespace std;


class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();  // 让visit 可以访问 building 中的私有成员
	void visit2();  // 让visit2 不可以访问 building 中的私有成员
private:
	Building * building;

};

class Building
{
	friend void GoodGay::visit();  
	// 设置 GoodGay 下的 visit成员函数为友元
public:
	Building();
	string m_SittingRoom;
private:

	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit is accessing: " << building->m_SittingRoom << endl;
	cout << "visit is accessing: " << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit is accessing: " << building->m_SittingRoom << endl;
	//cout << "visit is accessing: " << building->m_BedRoom << endl; // 不可访问
}

void test_01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}



int main()
{
	test_01();
	system("pause");
	return 0;
}