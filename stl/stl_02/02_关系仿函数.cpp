#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

/*
	¹ØÏµ·Âº¯Êý
*/

class MyCompare
{
public:
	bool operator() (int v1, int v2)
	{
		return v1 > v2;
	}
};
void test_01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ½µÐò
	//sort(v.begin(), v.end(), MyCompare());
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	test_01();
	system("pause");
	return 0;
}