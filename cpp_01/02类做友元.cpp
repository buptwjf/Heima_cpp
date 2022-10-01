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
	friend class GoodGay;  // GoodGay ����Ϊ Building ����Ԫ
public:
	Building();
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};


// ����д��Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	// �������������
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