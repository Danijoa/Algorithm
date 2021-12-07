#include <iostream>
#include <vector>

using namespace std;

// 복면산, 서로 다른 문자는 서로 다른 숫자
// SEND+MORE=MONEY
string s;
int fF = 0, fE, bF, bE;
bool numUsed[10] = { false, };
int alphaNUM[26];  

/*
예를 들어 E 값이 1인 경우
alphaIdx[4]는 1
*/

int FRONT()
{
    int num = 0;
    int gop = 1;
    for (int i = fE; i >= fF; i--)
    {
        int idx = s[i] - 'A';
        num += (alphaNUM[idx] * gop);
        gop *= 10;
    }
    return num;
}

int BACK()
{
    int num = 0;
    int gop = 1;
    for (int i = bE; i >= bF; i--)
    {
        int idx = s[i] - 'A';
        num += (alphaNUM[idx] * gop);
        gop *= 10;
    }
    return num;
}

int RESULT()
{
    int num = 0;
    int gop = 1;
    for (int i = s.length() - 1; i >= bE + 2; i--)
    {
        int idx = s[i] - 'A';
        num += (alphaNUM[idx] * gop);
        gop *= 10;
    }
    return num;
}

void dfs(int idx)
{
    if (idx == fE + 1)
        idx = bF;

    if (s[idx] == '=')
    {
        if (FRONT() + BACK() == RESULT())
        {
            if (alphaNUM[s[fF] - 'A'] != 0 && alphaNUM[s[bF] - 'A'] != 0)
            {
                cout << "\n  " << FRONT();
                cout << "\n+ " << BACK();
                cout << "\n----------\n";
                cout << "  " << RESULT() <<"\n";
            }
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (numUsed[i] == false)
            {
                alphaNUM[s[idx] - 'A'] = i;
                numUsed[i] = true;
                dfs(idx + 1);
                //alphaNUM[s[idx] - 'A'] = -1;
                numUsed[i] = false;
            }
        }
    }
}

int main(void)
{    
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            fE = i - 1;
            bF = i + 1;
        }
        else if (s[i] == '=')
            bE = i - 1;
    }

    fill(alphaNUM, alphaNUM + 26, -1);

    dfs(0);

    return 0;
}
