#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int len = s.length();

    if (len != 4 && len != 6)
        return false;

    for (int i = 0; i < len; i++)
    {
        if (s[i] - '0' < 0 || s[i] - '0' > 9)
            return false;
    }

    return answer;
}
