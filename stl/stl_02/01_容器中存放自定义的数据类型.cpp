#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age) : Name(name), Age(age) {}

	string Name;
	int Age;
};



void test_01()
{
	//// 创建 vector 容器
	//vector<Person> v;

	//Person p1("aaa", 10);
	//Person p2("aaa", 20);
	//Person p3("aaa", 30);
	//Person p4("aaa", 40);
	//Person p5("aaa", 50);
	//// 向容器内放入数据
	//v.push_back(p1);
	//v.push_back(p2);
	//v.push_back(p3);
	//v.push_back(p4);
	//v.push_back(p5);
	//
	//// 遍历容器中的数据
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名: " << (*it).Name << "年龄:" << (*it).Age << endl;
	//}

}

// 存放自定义数据类型的指针
void test_02()
{
	// 创建 vector 容器
	vector<Person*> v;

	Person p1("aaa", 10);
	Person p2("aaa", 20);
	Person p3("aaa", 30);
	Person p4("aaa", 40);
	Person p5("aaa", 50);
	// 向容器内放入数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历容器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名: " << (*it)->Name << "年龄:" << (*it)->Age << endl;
	}

}

int main()
{
	//test_01();
	test_02();
	system("pause");
	return 0;
}