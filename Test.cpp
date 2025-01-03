#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    SimpleVector<int> sv1;
    SimpleVector<int> sv2(15);

    //�迭 ũ�� Ȯ��
    cout << "***�迭 ũ�� Ȯ��***" << '\n';
    cout << sv1.Capacity() << '\n';
    cout << sv2.Capacity() << '\n';

    cout << "***���� ���� ����***" << '\n';
    cout << sv1.Size() << '\n';

    //���� �߰�
    sv1.PushBack(3);
    sv1.PushBack(87);
    sv1.PushBack(29);

    //������ ���
    cout << "***sv1 ������ ���***" << '\n';
    sv1.PrintData();

    cout << "***���� ���� ����***" << '\n';
    cout << sv1.Size() << '\n';
    
    //����
    cout << "***sv1 ����***" << '\n';
    sv1.SortData();
    sv1.PrintData();

    //���� ������
    cout << "***���� ������ Ȯ��***" << '\n';
    SimpleVector<int> sv3(sv1);
    sv3.PrintData();

    //���� ����
    cout << "***sv1 ���� ���� Ȯ��***" << '\n';
    sv1.PopBack();
    sv1.PrintData();
}