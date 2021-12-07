#include <iostream>
#include <vector>

using namespace std;

// 복면산 - 서로 다른 문자는 서로 다른 숫자

string s;
char nums[10];
bool alpha[26] = { false, };

void dfs(int idx, int i)
{
    char cur = s[i];


    if (cur == '=')
    {
        return;
    }
     
    if (cur == '+' || alpha[cur - 'A'] == true)
        continue;

    if (alpha[cur - 'A'] == false)
    {
        nums[idx] = cur;
        idx++;
    }
}

int main(void)
{    
    cin >> s;
    dfs(0, 0);

    return 0;
}
