#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<string> numV[500];
    int index = 0;

    for (int i = 0 + 1; i < s.length() - 1; i++)
    {
        // , 만나면 무시 
        // { 만나면 숫자 저장
        if (s[i] == '{')
        {
            string numS = "";
            int j = i + 1;
            while (true)
            {
                // } 만나면 앞에 숫자 저장하고 탈출
                if (s[j] == '}')
                {
                    numV[index].push_back(numS);
                    break;
                }

                // , 만나면 앞에 숫자 저장하고 리셋
                if (s[j] == ',')
                {
                    numV[index].push_back(numS);
                    j++;
                    numS = "";
                    continue;
                }

                numS += s[j];
                j++;
            }

            index++;
        }
    }

    bool* visited = new bool[index];
    for (int i = 0; i < index; i++)
    {
        visited[i] = false;
    }
    //memset(visited, false, sizeof(visited));

    for (int i = 0; i < index; i++)
    {
        // 확인안한 곳 중 가장 길이가 짧은 곳
        int minL = 501;
        int minIdx = 0;
        for (int j = 0; j < index; j++)
        {
            if (minL > numV[j].size() && visited[j] == false)
            {
                minL = numV[j].size();
                minIdx = j;
            }
        }
        visited[minIdx] = true;

        // 값 넣기
        for (int j = 0; j < numV[minIdx].size(); j++)
        {
            int tempNum = stoi(numV[minIdx][j]);

            // 새로운 값이면
            if (find(answer.begin(), answer.end(), tempNum) == answer.end())
            {
                answer.push_back(tempNum);
            }
        }
    }

    return answer;
}

int main()
{
    //string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"; // 2 1 3 4
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}"; // 2 1 3 4
    //string s = "{{20,111},{111}}"; // 111 20
    //string s = "{{123}}"; // 123
    //string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"; // 3 2 4 1

    vector<int> temp = solution(s);
    cout << "[";
    for (int i = 0; i < temp.size(); i++)
    {
        if (i != temp.size() - 1)
            cout << temp[i] << ", ";
        else
            cout << temp[i];
    }
    cout << "]";
}
