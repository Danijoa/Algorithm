#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LPS(string &s)
{
    int sLen = s.length();
    vector<int> p(sLen, 0); //sLen 만큼 공간 만들고, 0으로 초기화

    int i=0;
    for(int j=1; j<sLen; j++)
    {
        while(i > 0 && s[i] != s[j])
        {
            i = p[i - 1];
        }
        
        if(s[i] == s[j])
        {
            p[j] = i + 1;
            i++;
        }
    }
    
    return p;
}

int main()
{
    string s;
    cin >> s;
    int sLen = s.length();
    
    int answer = 0;
    for(int i=0; i<sLen; i++)
    {
        string subS = s.substr(i, sLen);
        vector<int> p = LPS(subS);
        sort(p.begin(), p.end(), greater<int>()); // 하나의 subS의 반복 길이 내림차순 
        answer = max(answer, p[0]);    // 여러 subS중 최대 반복 길이
    }
    
    cout << answer;
}
