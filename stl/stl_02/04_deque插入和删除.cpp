#include <iostream>
#include <deque>
using namespace std;

/*
	���˲��������
- `push_back(elem);`          //������β�����һ������
- `push_front(elem);`        //������ͷ������һ������
- `pop_back();`                   //ɾ���������һ������
- `pop_front();`                 //ɾ��������һ����
ָ��λ�ò�����
* `insert(pos,elem);`         //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
* `insert(pos,n,elem);`     //��posλ�ò���n��elem���ݣ��޷���ֵ��
* `insert(pos,beg,end);`    //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
* `clear();`                           //�����������������
* `erase(beg,end);`             //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
* `erase(pos);`                    //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
*/

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n****************\n";
}


// ���˲���
void test_01()
{
	deque<int> d;
	// β��
	d.push_back(10);
	d.push_back(20);

	// ͷ��
	d.push_front(30);
	d.push_front(40);

	printDeque(d);

	// βɾ
	d.pop_back();
	d.pop_front();

	printDeque(d);
}


// ����
// ��vector ��ͬ�� deque �����ɾ���ṩ��λ���ǵ������� 
void test_02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2, 100);
	printDeque(d);

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_front(3);
	d2.push_front(4);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}

// ɾ��
void test_03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	// ��λ��ɾ��
	//erase(pos); //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	d.insert(d.erase(d.begin()), 5, 5);
	printDeque(d);

	deque<int>::const_iterator it = d.begin();
	it++;
	d.erase(it);
	printDeque(d);

	// ������ɾ��
	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

int main()
{
	//test_01();
	//test_02();
	test_03();
	system("pause");
	return 0;
}