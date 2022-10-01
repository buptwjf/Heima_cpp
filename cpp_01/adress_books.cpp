# include <iostream>
using namespace std;
#include <string>
#define MAX 1000 // �������

// �����ϵ�˵Ľṹ��
struct Person
{
    // ����
    string m_Name;
    // �Ա�
    int m_Sex;  // 1 ��  2 Ů
        // ����
    int m_Age;
    // �绰
    string m_Phone;
    // סַ
    string m_Addr;
};

// ���ͨѶ¼�Ľṹ��
struct Addressbooks
{
    // ͨѶ¼�б�����ϵ�˵�����
    struct Person personArray[MAX];  
    // ͨѶ¼�е�ǰ��¼����ϵ�˵ĸ���
    int m_Size;
};

void ShowMenu();  // ��ʾ�˵�
void addPerson(Addressbooks&);  // �����ϵ��
void showPerson(const Addressbooks&);  // ��ʾ��ϵ��
int isExist(const Addressbooks&, const string);  // �ж���ϵ���Ƿ����
void deletPerson(Addressbooks&);  // ɾ����ϵ��
void findPerson(const Addressbooks&);  // Ѱ����ϵ��
void modifyPerson(Addressbooks&);  // �޸���ϵ��
void cleanPerson(Addressbooks&);  // �����ϵ��


int main()
{
    // ����ͨѶ¼
    Addressbooks abs;
    // ��ʼ��ͨѶ¼������
    abs.m_Size = 0;
    int select = 0;  // �û�����ı���
    while (true) 
    {
        ShowMenu();  // ��ʾ��ʼ����
        cin >> select;
        
        switch (select)
        {
        case 1:  // 1. �����ϵ��
            addPerson(abs);  // ���õ�ַ���ݣ���������ʵ��
            break;
        case 2:  // 2. ��ʾ��ϵ��
            showPerson(abs);
            break;
        case 3:  // 3. ɾ����ϵ��
            deletPerson(abs);
            break;
        case 4:  // 4. ������ϵ��
            findPerson(abs);
            break;
        case 5:  // 5. �޸���ϵ��
            modifyPerson(abs);
            break;
        case 6:  // 6. �����ϵ��
            cleanPerson(abs);
            break;
        case 0:  // 0. �Ƴ�ϵͳ
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");  // ���������
            return 0;  // �˳�ϵͳ
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}

// �˵�����
void ShowMenu()
{
    using namespace std;
    cout << "*************************" << endl;
    cout << "***** 1. �����ϵ�� *****" << endl;
    cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
    cout << "***** 3. ɾ����ϵ�� *****" << endl;
    cout << "***** 4. ������ϵ�� *****" << endl;
    cout << "***** 5. �޸���ϵ�� *****" << endl;
    cout << "***** 6. �����ϵ�� *****" << endl;
    cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
    cout << "*************************" << endl;
}


// 1. �����ϵ��
void addPerson(Addressbooks & abs)
{
    if (abs.m_Size >= 1000)
    {
        cout << "ͨѶ¼�������޷����" << endl;
    }
    else
    {
        // ��Ӿ������ϵ��
        
        // ����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs.personArray[abs.m_Size].m_Name = name;
        cout << "�������Ա�" << endl;
        cout << "1-- ��" << endl;
        cout << "2-- Ů" << endl;
        
        // �Ա�
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
                cout << "������������������" << endl;
            }
        }

        // ����
        cout << "����������" << endl;
        int age;
        cin >> age;
        abs.personArray[abs.m_Size].m_Age = age;

        // �绰
        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        abs.personArray[abs.m_Size].m_Phone = phone;

        // ��ͥ��ַ
        cout << "��ͥסַ" << endl;
        string add;
        cin >> add;
        abs.personArray[abs.m_Size].m_Addr = add;

        // ��������
        abs.m_Size++;

        cout << "��ӳɹ�" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    return;
}

// 2. ��ʾ������ϵ�˵���Ϣ
void showPerson(const Addressbooks & abs)
{
    if (abs.m_Size == 0)  // �ж�ͨѶ¼�Ƿ�Ϊ��
    {
        cout << "����Ϊ��" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    else
    {
        for (int i = 0; i < abs.m_Size; i++)
        {
            cout << "������" << abs.personArray[i].m_Name << "\t";
            cout << "�Ա�" << abs.personArray[i].m_Sex << "\t";
            cout << "���䣺" << abs.personArray[i].m_Age << "\t";
            cout << "�绰��" << abs.personArray[i].m_Phone << "\t";
            cout << "��ַ��" << abs.personArray[i].m_Addr << endl;
        }
        system("pause");  // �밴���������
        system("cls");  // ����
    }
}

// 3. ɾ����ϵ�ˣ���������ɾ��ָ����ϵ��
void deletPerson(Addressbooks & abs)
{
    cout << "����Ҫɾ����ϵ�˵�������" << endl;
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
        cout << "ɾ���ɹ�" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
}

// �ж���ϵ���Ƿ���ڣ������ڷ����������������򷵻� -1
int isExist(const Addressbooks & abs, const string name)
{
    for (int i = 0; i < abs.m_Size; i++)
    {
        if (abs.personArray[i].m_Name == name)
        {
            cout << "�ҵ�������" << endl;
            return i;
        }
    }
    return -1;
}

// 4. ������ϵ��
void findPerson(const Addressbooks& abs)
{
    cout << "������Ҫ���ҵ���ϵ������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);  // �жϴ����Ƿ����
    if (ret != -1)
    {
        cout << "������" << abs.personArray[ret].m_Name << "\t";
        cout << "�Ա�" << abs.personArray[ret].m_Sex << "\t";
        cout << "���䣺" << abs.personArray[ret].m_Age << "\t";
        cout << "�绰��" << abs.personArray[ret].m_Phone << "\t";
        cout << "��ַ��" << abs.personArray[ret].m_Addr << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    

}

// 5. �޸���ϵ��
void modifyPerson(Addressbooks& abs)
{
    cout << "������Ҫ�޸ĵ���ϵ������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);  // �жϴ����Ƿ����
    if (ret != -1)
    {
        cout << "����������" << endl;
        cin >> name;
        abs.personArray[ret].m_Name = name;
        cout << "�������Ա�" << endl;
        cout << "1-- ��" << endl;
        cout << "2-- Ů" << endl;

        // �Ա�
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
                cout << "������������������" << endl;
            }
        }

        // ����
        cout << "����������" << endl;
        int age;
        cin >> age;
        abs.personArray[ret].m_Age = age;

        // �绰
        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        abs.personArray[ret].m_Phone = phone;

        // ��ͥ��ַ
        cout << "��ͥסַ" << endl;
        string add;
        cin >> add;
        abs.personArray[ret].m_Addr = add;
        cout << "�޸ĳɹ�" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");  // �밴���������
        system("cls");  // ����
    }
}

// 6 �����ϵ��
void cleanPerson(Addressbooks& abs)
{
    abs.m_Size = 0;
    cout << "ͨѶ¼������" << endl;
    system("pause");  // �밴���������
    system("cls");  // ����
}