#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int num)
{
    vector<vector<int>> tower(num, vector<int>(num, 0));

    int max_num = (num * (num + 1)) / 2;    //최대 수
    int top = 0;    //채워져야하는 맨 위
    int bottom = num - 1;   //맨 아래
    int left = 0;   //왼
    int right = 0;  //오른
    int cur = 1;    //현재 적고 있는 수
    int state = 0; //상태

    while (cur <= max_num)  //작성한 숫자가 최대 숫자를면 먼춤
    {
        if (state == 0) //0: 아래로
        {
            for (int i = top; i <= bottom; i++)
            {
                tower[i][left] = cur;
                cur++;
            }
            top++;  //맨 윗칸 이제 신경 안써두댐
            left++; //맨 오른칸 신경 안써두댐
            state = 1;
        }
        else if (state == 1)    //1: 오른쪽으로 
        {
            for (int i = left; i <= bottom - right; i++)
            {
                tower[bottom][i] = cur;
                cur++;
            }
            bottom--;   //맨 아래칸 신경 안써두댐 
            state = 2;
        }
        else if (state == 2)    //2: 왼위 대각선으로
        {
            for (int i = bottom; i >= top; i--)
            {
                tower[i][i-right] = cur;
                cur++;
            }
            top++;
            right++;
            state = 0;
        }
    }

    /*for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << tower[i][j] <<" ";
        } 
        cout << endl;
    }*/

    vector<int> answer;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(tower[i][j]);
        }
    }

    return answer;
}

int main()
{
    int num;
    cin >> num;

    solution(num);
}
