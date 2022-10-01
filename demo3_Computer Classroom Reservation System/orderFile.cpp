#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;	// 日期
	string interval;// 时间段
	string stuId;	// 学号
	string name;	// 姓名
	string roomId;	// 机房好
	string status;	// 状态

	this->m_Size = 0;  // 预约的条数

	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> name && ifs >> roomId && ifs >> status)
	{
		// 测试
		//cout << data << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << name << endl;
		//cout << roomId << endl;
		//cout << status << endl;

		// 截取数据  如：data:1111
		string key;
		string value;

		map<string, string> m;

		int pos = data.find(":");
		if (pos != 1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != 1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != 1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if (pos != 1)
		{
			key = name.substr(0, pos);
			value = name.substr(pos + 1, name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != 1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != 1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

		// 测试代码
		//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
		//{
		//	cout << "key = " << it->first << "value = " << endl;
		//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		//	{
		//		cout << mit->first << "=" << mit->second << " ";
		//	}
		//	cout << endl;
		//}
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "name:" << this->m_orderData[i]["name"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";
	}
	ofs.close();
}
