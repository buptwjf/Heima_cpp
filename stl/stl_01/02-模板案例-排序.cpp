#include <iostream>
using namespace std;

/*
	使用模板，排序字符数组和整形数组
*/

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Sort(T arr[], int len)
// 从小到大排序
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}

template <typename T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "\t" << endl;
	}
}


// 测试 int 类型
void test_01()  
{
	int arr_a[] = { 3,2,6,7,3,7,0,8,9};
	int len = sizeof(arr_a) / sizeof(int);
	Sort(arr_a, len);
	printArray(arr_a, len);
}


// 测试 char 类型
void test_02()  
{
	char arr_b[] = {"kubeEdge"};
	int len = sizeof(arr_b) / sizeof(char);
	Sort(arr_b, len);
	printArray(arr_b, len);
}

int main()
{
	test_01();
	cout << "**************" << endl;
	test_02();
	system("pause");
	system("cls");
	return 0;
}