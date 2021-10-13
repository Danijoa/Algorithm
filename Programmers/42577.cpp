#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;

    // 사전순 정렬
    sort(phone_book.begin(), phone_book.end());

    int pblen = phone_book.size();

    string cur, cut, pre;
    int len;
    for (int i = 1; i < pblen; i++)
    {
        cur = phone_book[i];
        pre = phone_book[i - 1];
        // 인접한 전화번호만 비교
        if (pre.compare(cur.substr(0, pre.size())) == 0)
        {
            answer = false;
            return answer;
        }
    }

    return answer;
}
