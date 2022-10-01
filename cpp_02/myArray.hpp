#pragma once
#include <iostream>

using namespace std;

template <class T>
class MyArray
{

public:

	// 构造函数
	MyArray(int capacity)
	{
		
		cout << "有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造  (防止浅拷贝)
	MyArray(const MyArray& arr)
	{
		cout << "拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// 深拷贝 -> 创建空间
		this->pAddress = new T[arr.m_Capacity];
		// 将 arr 的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator =  (防止浅拷贝)  a = b = c
	MyArray& operator = (const MyArray& arr)
	{
		cout << " = 重载 " << endl;
		// 判断左边来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 再做深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		// 将 arr 的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}


	// 析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "析构 数组" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

	// 利用下标的方式访问数组元素
	// 重载 operator []   arr[0] = 100
	T& operator [] (int index)
	{
		if (0 <= index && index < this->m_Size)
		{
			return this->pAddress[index];
		}
		else
			cout << "超出范围" << endl;
	}

	// 尾插法
	void Push_Back(const T& val)
	{
		// 判断容量等于大小
		if (this->m_Capacity == this->m_Size)
		{
			cout << "已满" << endl;
			return;
		}

		this->pAddress[this->m_Size] = val;  // 插入数据
		this->m_Size++;  // 更新大小
	}

	// 尾删法
	void Pop_Back()
	{
		// 判断大小等于0
		if (this->m_Size == 0)
		{
			cout << "数组空" << endl;
			return;
		}
		this->m_Size--;
	}

	// 获取数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	// 获取数组的大小
	int getSize()
	{
		return this->m_Size;
	}

private:
	// 数组
	T* pAddress;  // 指针指向数组
	// 容量
	int m_Capacity;  // 数组容量
	// 大小
	int m_Size;  // 数组大小
};