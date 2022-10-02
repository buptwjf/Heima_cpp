#pragma once
#include <iostream>
using namespace std;

#include <map>
#include "globalFile.h"
#include <fstream>

class OrderFile
{
public:

	// 构造函数
	OrderFile();

	// 更新预约记录
	void updateOrder();

	// 记录容器 
	// key 记录的条数 value 记录的信息
	map<int, map<string, string>> m_orderData;

	// 记录预约条数
	int m_Size;
};