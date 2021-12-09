#include <iostream>
#include <vector>

using namespace std;

int tDay;
vector<pair<int, int>> myV;
int tPay = 0;

/*
void dfs(int day, int cPay)
{
    if (day >= tDay + 1)
    {
        if (tPay < cPay)
            tPay = cPay;
        return;
    }

    for (int i = day; i <= tDay; i++)
    {
        if (day + myV[day - 1].first <= tDay + 1)
            dfs(day + myV[i - 1].first, cPay + myV[i - 1].second);
        else
            dfs(day + myV[i - 1].first, cPay);
    }
}
*/


void dfs(int day, int cPay)
{
    if (day == tDay + 1)
    {
        if (tPay < cPay)
            tPay = cPay;
        return;
    }
    else
    {
        // 진행
        if (day + myV[day - 1].first <= tDay + 1)
            dfs(day + myV[day - 1].first, cPay + myV[day - 1].second);
        // 미진행
        dfs(day + 1, cPay);
    }
}

int main(void)
{    
    cin >> tDay;
    for (int i = 0; i < tDay; i++)
    {
        int d, p;
        cin >> d >>p;
        myV.push_back(make_pair(d, p));
    }

    dfs(1, 0);
    cout << tPay;

    return 0;
}
