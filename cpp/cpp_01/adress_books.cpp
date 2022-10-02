# include <iostream>
using namespace std;
#include <string>
#define MAX 1000 // 最大人数

// 设计联系人的结构体
struct Person
{
    // 姓名
    string m_Name;
    // 性别
    int m_Sex;  // 1 男  2 女
        // 年龄
    int m_Age;
    // 电话
    string m_Phone;
    // 住址
    string m_Addr;
};

// 设计通讯录的结构体
struct Addressbooks
{
    // 通讯录中保存联系人的数组
    struct Person personArray[MAX];  
    // 通讯录中当前记录的联系人的个数
    int m_Size;
};

void ShowMenu();  // 显示菜单
void addPerson(Addressbooks&);  // 添加联系人
void showPerson(const Addressbooks&);  // 显示联系人
int isExist(const Addressbooks&, const string);  // 判断联系人是否存在
void deletPerson(Addressbooks&);  // 删除联系人
void findPerson(const Addressbooks&);  // 寻找联系人
void modifyPerson(Addressbooks&);  // 修改联系人
void cleanPerson(Addressbooks&);  // 清空联系人


int main()
{
    // 创建通讯录
    Addressbooks abs;
    // 初始化通讯录的人数
    abs.m_Size = 0;
    int select = 0;  // 用户输入的变量
    while (true) 
    {
        ShowMenu();  // 显示初始界面
        cin >> select;
        
        switch (select)
        {
        case 1:  // 1. 添加联系人
            addPerson(abs);  // 利用地址传递，可以修饰实参
            break;
        case 2:  // 2. 显示联系人
            showPerson(abs);
            break;
        case 3:  // 3. 删除联系人
            deletPerson(abs);
            break;
        case 4:  // 4. 查找联系人
            findPerson(abs);
            break;
        case 5:  // 5. 修改联系人
            modifyPerson(abs);
            break;
        case 6:  // 6. 清空联系人
            cleanPerson(abs);
            break;
        case 0:  // 0. 推出系统
            cout << "欢迎下次使用" << endl;
            system("pause");  // 任意键继续
            return 0;  // 退出系统
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}

// 菜单界面
void ShowMenu()
{
    using namespace std;
    cout << "*************************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}


// 1. 添加联系人
void addPerson(Addressbooks & abs)
{
    if (abs.m_Size >= 1000)
    {
        cout << "通讯录已满，无法添加" << endl;
    }
    else
    {
        // 添加具体的联系人
        
        // 姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs.personArray[abs.m_Size].m_Name = name;
        cout << "请输入性别" << endl;
        cout << "1-- 男" << endl;
        cout << "2-- 女" << endl;
        
        // 性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs.personArray[abs.m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        // 年龄
        cout << "请输入年龄" << endl;
        int age;
        cin >> age;
        abs.personArray[abs.m_Size].m_Age = age;

        // 电话
        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs.personArray[abs.m_Size].m_Phone = phone;

        // 家庭地址
        cout << "家庭住址" << endl;
        string add;
        cin >> add;
        abs.personArray[abs.m_Size].m_Addr = add;

        // 更新人数
        abs.m_Size++;

        cout << "添加成功" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    return;
}

// 2. 显示所有联系人的信息
void showPerson(const Addressbooks & abs)
{
    if (abs.m_Size == 0)  // 判断通讯录是否为空
    {
        cout << "人数为空" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    else
    {
        for (int i = 0; i < abs.m_Size; i++)
        {
            cout << "姓名：" << abs.personArray[i].m_Name << "\t";
            cout << "性别：" << abs.personArray[i].m_Sex << "\t";
            cout << "年龄：" << abs.personArray[i].m_Age << "\t";
            cout << "电话：" << abs.personArray[i].m_Phone << "\t";
            cout << "地址：" << abs.personArray[i].m_Addr << endl;
        }
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
}

// 3. 删除联系人：按照姓名删除指定联系人
void deletPerson(Addressbooks & abs)
{
    cout << "输入要删除联系人的姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < (abs.m_Size - 1); i++)
        {
            abs.personArray[i] = abs.personArray[i + 1];
        }
        abs.m_Size--;
        cout << "删除成功" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
}

// 判断联系人是否存在，若存在返回数组索引，否则返回 -1
int isExist(const Addressbooks & abs, const string name)
{
    for (int i = 0; i < abs.m_Size; i++)
    {
        if (abs.personArray[i].m_Name == name)
        {
            cout << "找到此姓名" << endl;
            return i;
        }
    }
    return -1;
}

// 4. 查找联系人
void findPerson(const Addressbooks& abs)
{
    cout << "请输入要查找的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);  // 判断此人是否存在
    if (ret != -1)
    {
        cout << "姓名：" << abs.personArray[ret].m_Name << "\t";
        cout << "性别：" << abs.personArray[ret].m_Sex << "\t";
        cout << "年龄：" << abs.personArray[ret].m_Age << "\t";
        cout << "电话：" << abs.personArray[ret].m_Phone << "\t";
        cout << "地址：" << abs.personArray[ret].m_Addr << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    

}

// 5. 修改联系人
void modifyPerson(Addressbooks& abs)
{
    cout << "请输入要修改的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);  // 判断此人是否存在
    if (ret != -1)
    {
        cout << "请输入姓名" << endl;
        cin >> name;
        abs.personArray[ret].m_Name = name;
        cout << "请输入性别" << endl;
        cout << "1-- 男" << endl;
        cout << "2-- 女" << endl;

        // 性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs.personArray[ret].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        // 年龄
        cout << "请输入年龄" << endl;
        int age;
        cin >> age;
        abs.personArray[ret].m_Age = age;

        // 电话
        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs.personArray[ret].m_Phone = phone;

        // 家庭地址
        cout << "家庭住址" << endl;
        string add;
        cin >> add;
        abs.personArray[ret].m_Addr = add;
        cout << "修改成功" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");  // 请按任意键继续
        system("cls");  // 清屏
    }
}

// 6 清空联系人
void cleanPerson(Addressbooks& abs)
{
    abs.m_Size = 0;
    cout << "通讯录已清零" << endl;
    system("pause");  // 请按任意键继续
    system("cls");  // 清屏
}