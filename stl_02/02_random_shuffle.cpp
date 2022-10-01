#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>
#include <ctime>

/*
    random_shuffle(iterator beg, iterator end);
*/

class MyPrint
{
public:
    void operator() (int val)
    {
        cout << val << " ";
    }
};


void test_01()
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    // ´òÂÒË³Ðò
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main()
{
	test_01();
	system("pause");
	system("clc");
	return 0;
}