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
}
