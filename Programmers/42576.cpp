#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    // O(nlogn)
    sort(participant.begin(), participant.end());
    // O(nlogn)
    sort(completion.begin(), completion.end());
    
    int num = participant.size();
    string answer = participant[num - 1];
    // O(n)
    for (int i = 0; i < num - 1; i++)
    {
        if (participant[i].compare(completion[i]) != 0)
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}
