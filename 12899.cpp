#include <iostream>
using namespace std;

string solution(int num) 
{
    string answer = "";
    string temp[3] = { "4", "1", "2" };

    while (num != 0)
    {
        answer = temp[num % 3] + answer;
        if (num % 3 == 0)
        {
            num = (num / 3) - 1;
        }
        else
        {
            num = num / 3;
        }
    }
    //cout << answer;
    return answer;
}

int main()
{
    int num;
    cin >> num;

    solution(num);
}
