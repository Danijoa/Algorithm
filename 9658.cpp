// 9658.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

//상근(홀수) 창영(짝수)
int number;
int cnt = 0;

int main()
{
    cin >> number;
    cnt = number;

    if (cnt % 2 == 1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }