#include <iostream>
using namespace std;
#include "myArray.hpp"
/*
	Ҫ��
	1. ���Զ��������������Լ��Զ����������͵����ݽ��д洢
	2. �������е����ݴ洢������
	3. ���캯���п��Դ������������
	4. �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
	5. �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
	6. ����ͨ���±�ķ�ʽ���������е�Ԫ��
	7. ���Ի�ȡ�����е�ǰԪ�ظ��������������
*/

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


// �������õ���������
void test_01()
{
	MyArray<int> arr1(5);
	//MyArray<int> arr2(arr1);
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	
	for (int i = 0; i < 5; i++)
	{
		// β�巨
		arr1.Push_Back(i);
	}

	cout << "arr1 ��ӡ: " << endl;
	printIntArray(arr1);

	cout << "Size: " << arr1.getSize() << endl;
	cout << "Capacity: " << arr1.getCapacity() << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2 ��ӡ: " << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2 βɾ���ӡ: " << endl;
	printIntArray(arr2);
}


// �������õ���������
class Person
{
public:
	Person() { cout << "Person Ĭ�Ϲ���" << endl; }  // ��Ҫ����Ĭ�Ϲ��죡����ᱨ��
	Person(string name, int age) : Name(name), Age(age)
	{ 
		cout << "Person �вι���" << endl; 
	}
	
	void showPerson()
	{
		cout << "������" << this->Name << "���䣺" << this->Age << endl;

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
	// ��������
	MyArray<Person> pArray(10);  // 10 ��Ĭ�Ϲ���

	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	// ��������
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	printPersonArray(pArray);

	cout << "��������: " << pArray.getCapacity() << endl;
	cout << "�����С: " << pArray.getSize() << endl;

}

int main()
{
	test_01();
	test_02();
	system("pause");
	system("cls");
	return 0;
}