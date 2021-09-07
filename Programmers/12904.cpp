#include <iostream>
#include <string>
using namespace std;

bool dp[2501][2501] = { false, };

int solution(string s)
{
    int answer = 1;

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        // 크기 1
        dp[i][i] = true;

        //크기 2
        if (i != 0 && s[i - 1] == s[i])
        {
            dp[i - 1][i] = true;
            answer = 2;
        }
    }

    // 크기 3~len (i + 1)
    for (int i = 2; i <= len - 1; i++)
    {
        // 시작 위치
        for (int j = 0; j + i < len; j++)
        {
            if (s[j] == s[j + i]
                && dp[j + 1][(j + i) - 1] == true)
            {
                dp[j][j + i] = true;
                answer = i + 1;
            }
        }
    }
    
    return answer;
}

int main() 
{
    string s = "abcdcba";
    string s = "abacde";
    cout << solution(s);

    return 0;
}
