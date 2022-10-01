#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>

/*
    reverse(iterator beg, iterator end);
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
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "反转前: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    cout << "反转后: " << endl;
    reverse(v.begin(), v.end());
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