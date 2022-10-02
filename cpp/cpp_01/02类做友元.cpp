#include <iostream>
using namespace std;
/*


*/

class Building;  // state Building

class GoodGay
{
public:
	GoodGay();
public:
	void visit();  // access Building

	Building * building;
};

class Building
{
	friend class GoodGay;  // GoodGay 类作为 Building 的友元
public:
	Building();
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};


// 类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	// 创建建筑物对象
	building = new Building;
}


void GoodGay::visit()
{
	cout << "goodBoy is accessing: " << building->m_SittingRoom  << endl;
	// friend class
	cout << "goodBoy is accessing: " << building->m_BedRoom << endl;
}


int main()
{
	system("pause");
	return 0;
}