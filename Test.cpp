#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    SimpleVector<int> sv1;
    SimpleVector<int> sv2(15);

    //배열 크기 확인
    cout << "***배열 크기 확인***" << '\n';
    cout << sv1.Capacity() << '\n';
    cout << sv2.Capacity() << '\n';

    cout << "***현재 원소 개수***" << '\n';
    cout << sv1.Size() << '\n';

    //원소 추가
    sv1.PushBack(3);
    sv1.PushBack(87);
    sv1.PushBack(29);

    //데이터 출력
    cout << "***sv1 데이터 출력***" << '\n';
    sv1.PrintData();

    cout << "***현재 원소 개수***" << '\n';
    cout << sv1.Size() << '\n';
    
    //정렬
    cout << "***sv1 정렬***" << '\n';
    sv1.SortData();
    sv1.PrintData();

    //복사 생성자
    cout << "***복사 생성자 확인***" << '\n';
    SimpleVector<int> sv3(sv1);
    sv3.PrintData();

    //원소 삭제
    cout << "***sv1 원소 삭제 확인***" << '\n';
    sv1.PopBack();
    sv1.PrintData();
}