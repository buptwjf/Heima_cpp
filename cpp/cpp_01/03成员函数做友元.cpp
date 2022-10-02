#include <iostream>
#include <string>
using namespace std;


class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();  // ��visit ���Է��� building �е�˽�г�Ա
	void visit2();  // ��visit2 �����Է��� building �е�˽�г�Ա
private:
	Building * building;

};

class Building
{
	friend void GoodGay::visit();  
	// ���� GoodGay �µ� visit��Ա����Ϊ��Ԫ
public:
	Building();
	string m_SittingRoom;
private:

	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
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
	//cout << "visit is accessing: " << building->m_BedRoom << endl; // ���ɷ���
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