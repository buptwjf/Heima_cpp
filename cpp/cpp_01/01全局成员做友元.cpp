#include <iostream>
#include <string>

using namespace std;
/*


*/

// ���彨������
class Building
{
	friend void goodBoy(Building* building);
public:
	Building()
	{
		m_SittingRoom = "����";
		m_Bedroom = "����";
	}
public:
	string m_SittingRoom;
private:
	string m_Bedroom;
};

// ȫ�ֺ���
void goodBoy(Building* building)
{
	cout << "goodBoy is accessing: " << building->m_SittingRoom << endl;
	// friend func
	cout << "goodBoy is accessing: " << building->m_Bedroom << endl;
}
	
void test_01()
{
	Building building;
	goodBoy(&building);
}

int main()
{
	test_01();
	system("pause");
	return 0;
}