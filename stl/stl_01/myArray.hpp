#pragma once
#include <iostream>

using namespace std;

template <class T>
class MyArray
{

public:

	// ���캯��
	MyArray(int capacity)
	{
		
		cout << "�вι���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// ��������  (��ֹǳ����)
	MyArray(const MyArray& arr)
	{
		cout << "��������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// ��� -> �����ռ�
		this->pAddress = new T[arr.m_Capacity];
		// �� arr �����ݿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator =  (��ֹǳ����)  a = b = c
	MyArray& operator = (const MyArray& arr)
	{
		cout << " = ���� " << endl;
		// �ж�����������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// �������
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		// �� arr �����ݿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}


	// ��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "���� ����" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

	// �����±�ķ�ʽ��������Ԫ��
	// ���� operator []   arr[0] = 100
	T& operator [] (int index)
	{
		if (0 <= index && index < this->m_Size)
		{
			return this->pAddress[index];
		}
		else
			cout << "������Χ" << endl;
	}

	// β�巨
	void Push_Back(const T& val)
	{
		// �ж��������ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����" << endl;
			return;
		}

		this->pAddress[this->m_Size] = val;  // ��������
		this->m_Size++;  // ���´�С
	}

	// βɾ��
	void Pop_Back()
	{
		// �жϴ�С����0
		if (this->m_Size == 0)
		{
			cout << "�����" << endl;
			return;
		}
		this->m_Size--;
	}

	// ��ȡ���������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	// ��ȡ����Ĵ�С
	int getSize()
	{
		return this->m_Size;
	}

private:
	// ����
	T* pAddress;  // ָ��ָ������
	// ����
	int m_Capacity;  // ��������
	// ��С
	int m_Size;  // �����С
};