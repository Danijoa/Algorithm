#include <iostream>
using namespace std;

bool dp[2001][2001] = { false, };    // index i부터 j까지 펠린드롬 여부 확인
int numArray[2001] = { 0, };
int len;
int loop;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> len;

    for (int i = 1; i <= len; i++)
    {
        cin >> numArray[i];

        // 크기가 1
        dp[i][i] = true;

        // 크기가 2
        if (i != 1 && numArray[i - 1] == numArray[i]) 
            dp[i - 1][i] = true;
    }
    
    // 크기가 i + 1
    for (int i = 2; i <= len - 1; i++)
    {
        // 인덱스 시작 위치
        for (int j = 1; j <= len - i; j++)
        {
            if (numArray[j] == numArray[j + i]
                && dp[j + 1][(j + i) - 1] == true)
            {
                dp[j][j + i] = true;
            }
        }
    }

    cin >> loop;

    for (int i = 0; i < loop; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << dp[start][end] << '\n';
    }

    return 0;
}
