#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int dir[2] = { -1, 1 };

/*int solution(vector<int> numbers, int target, int sum, int index)
{
    if (index == numbers.size())
    {
        if (sum == target)
            answer++;
        return 0;
    }

    for (int i = 0; i < 2; i++)
    {
        int cal = numbers[index] * dir[i];
        sum += cal;
        solution(numbers, target, sum, index + 1);
        sum -= cal;
    }

    return answer;
}*/

void DFS(vector<int> numbers, int target, int sum, int index)
{
    if (index == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int cal = numbers[index] * dir[i];
        sum += cal;
        DFS(numbers, target, sum, index + 1);
        sum -= cal;
    }
}

int solution(vector<int> numbers, int target)
{
    DFS(numbers, target, 0, 0);
    return answer;
}
