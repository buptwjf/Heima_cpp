#include <iostream>
using namespace std;

// 设置立方体类
class Cube
{
public:
	// 设置长
	void setLength(float len)
	{
		length = len;
	}
	// 设置宽
	void setWidth(float wid)
	{
		width = wid;
	}
	// 设置高
	void setHeight(float hei)
	{
		height = hei;
	}
	// 获取长
	float getLength()
	{
		return length;
	}
	// 获取宽
	float getWidth()
	{
		return width;
	}
	// 获取高
	float getHeight()
	{
		return height;
	}
	// 计算面积
	float calculateS()
	{
		return 2 * (length * width + length * height + width * height);
	}
	// 计算体积
	float calculateV()
	{
		return length * width * height;
	}
	// 利用成员函数判断两立方体是否相等
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


// 全局函数判断两立方体是否相等
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
	cout << "c1 的面积：" << c1.calculateS() << endl;
	cout << "c1 的体积：" << c1.calculateV() << endl;
	cout << "利用全局函数判断两立方体是否相同" << endl;
	bool ret = isSame(c1, c2);
	if (ret)
		cout << "两立方体相同" << endl;
	else
		cout << "两立方体不同" << endl;
	cout << "利用成员函数判断两立方体是否相同" << endl;
	ret = c1.isSameByClass(c2);
	if (ret)
		cout << "两立方体相同" << endl;
	else
		cout << "两立方体不同" << endl;
	system("pause");
	return 0;
}