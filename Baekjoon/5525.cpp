#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    // make Pn
    string pn = "I";
    for (int i = 0; i < num; i++)
        pn += "OI";

    int sLen;
    cin >> sLen;

    string s;
    cin >> s;

    int answer = 0;

    // count Pn : KMP
    for (int i = 0; i < sLen; i++)
    {
        int cnt = 0;
        if (s[i] == 'I')
        {
            while (s[i + 1]=='O' && s[i + 2] == 'I')
            {
                i += 2;
                cnt++;

                if (cnt == num)
                {
                    answer++;

                    // 다음 중복확인 할 때
                    // pn-2 문자열은 이미 일치한다는 것을 알고 있으있으니까
                    // 뒤에 두개만 더 확인 하면 된다
                    cnt--;
                }
            }
        }
    }

    cout << answer;
}
