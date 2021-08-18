#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int temp = numbers[i] + numbers[j];

            if(find(answer.begin(), answer.end(), temp) == answer.end())
                answer.push_back(temp);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
