#include <iostream>
using namespace std;
#include "myArray.hpp"
/*
	要求
	1. 可以对内置数据类型以及自定义数据类型的数据进行存储
	2. 将数组中的数据存储到堆区
	3. 构造函数中可以传入数组的容量
	4. 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
	5. 提供尾插法和尾删法对数组中的数据进行增加和删除
	6. 可以通过下标的方式访问数组中的元素
	7. 可以获取数组中当前元素个数和数组的容量
*/

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


// 测试内置的数据类型
void test_01()
{
	MyArray<int> arr1(5);
	//MyArray<int> arr2(arr1);
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	
	for (int i = 0; i < 5; i++)
	{
		// 尾插法
		arr1.Push_Back(i);
	}

	cout << "arr1 打印: " << endl;
	printIntArray(arr1);

	cout << "Size: " << arr1.getSize() << endl;
	cout << "Capacity: " << arr1.getCapacity() << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2 打印: " << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2 尾删后打印: " << endl;
	printIntArray(arr2);
}


// 测试内置的数据类型
class Person
{
public:
	Person() { cout << "Person 默认构造" << endl; }  // 需要这里默认构造！否则会报错
	Person(string name, int age) : Name(name), Age(age)
	{ 
		cout << "Person 有参构造" << endl; 
	}
	
	void showPerson()
	{
		cout << "姓名：" << this->Name << "年龄：" << this->Age << endl;

	}
public:
	string Name;
	int Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++)
	{
		personArr[i].showPerson();
	}
}

void test_02()
{
	// 创建数组
	MyArray<Person> pArray(10);  // 10 次默认构造

	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	// 插入数组
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	printPersonArray(pArray);

	cout << "数组容量: " << pArray.getCapacity() << endl;
	cout << "数组大小: " << pArray.getSize() << endl;

}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}