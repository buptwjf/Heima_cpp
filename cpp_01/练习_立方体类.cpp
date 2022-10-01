#include <iostream>
using namespace std;

// ������������
class Cube
{
public:
	// ���ó�
	void setLength(float len)
	{
		length = len;
	}
	// ���ÿ�
	void setWidth(float wid)
	{
		width = wid;
	}
	// ���ø�
	void setHeight(float hei)
	{
		height = hei;
	}
	// ��ȡ��
	float getLength()
	{
		return length;
	}
	// ��ȡ��
	float getWidth()
	{
		return width;
	}
	// ��ȡ��
	float getHeight()
	{
		return height;
	}
	// �������
	float calculateS()
	{
		return 2 * (length * width + length * height + width * height);
	}
	// �������
	float calculateV()
	{
		return length * width * height;
	}
	// ���ó�Ա�����ж����������Ƿ����
	bool isSameByClass(Cube& c)
	{
		if (length == c.getLength() && width == c.getWidth()
			&& height == c.getHeight())
			return 1;
		else
			return 0;
	}

	
private:
	float length;
	float width;
	float height;
};


// ȫ�ֺ����ж����������Ƿ����
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth()
		&& c1.getHeight() == c2.getHeight())
		return true;
	else
		return false;
}

int main()
{
	Cube c1, c2;
	c1.setLength(10);
	c1.setWidth(10);
	c1.setHeight(10);
	c2.setLength(10);
	c2.setWidth(11);
	c2.setHeight(10);
	cout << "c1 �������" << c1.calculateS() << endl;
	cout << "c1 �������" << c1.calculateV() << endl;
	cout << "����ȫ�ֺ����ж����������Ƿ���ͬ" << endl;
	bool ret = isSame(c1, c2);
	if (ret)
		cout << "����������ͬ" << endl;
	else
		cout << "�������岻ͬ" << endl;
	cout << "���ó�Ա�����ж����������Ƿ���ͬ" << endl;
	ret = c1.isSameByClass(c2);
	if (ret)
		cout << "����������ͬ" << endl;
	else
		cout << "�������岻ͬ" << endl;
	system("pause");
	return 0;
}