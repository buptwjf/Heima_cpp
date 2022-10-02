#include <iostream>
#include <list>
using namespace std;

/*
* `size(); `                       //返回容器中元素的个数
* `empty(); `                    //判断容器是否为空
* `resize(num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					    //如果容器变短，则末尾超出容器长度的元素被删除。
* `resize(num, elem); `   //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
   //如果容器变短，则末尾超出容器长度的元素被删除。
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


// 赋值和交换
void test_01()
{
	list<int> L1;
	if (!L1.empty())
	{
		cout << "列表为空" << endl;
	}
	else
	{
		cout << "列表不为空，大小为：" << L1.size() << endl;
	}

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	// 重新制定大小
	L1.resize(10);
	printList(L1);

	L1.resize(2);
	printList(L1);
}



int main()
{
	test_01();
	system("pause");
	return 0;
}