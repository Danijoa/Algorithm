#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct myIndex
{
    int x;
    int y;
}MyCorr;

//상 하 좌 우
MyCorr dir[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int solution(vector<vector<int> > maps)
{   
    // 세로 x 가로 (X x Y) (n x m)
    int n = maps.size();
    int m = maps[0].size();

    int answer = 0;
    MyCorr startCorr = { 0,0 };

    /*bool** visited;
    visited = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
    }*/
    bool visited[101][101];
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            visited[i][j] = false;
        }
    }

    queue<pair<int, MyCorr>> myData;    //지나온 거리 , 현재 좌표
    myData.push(make_pair(0, startCorr));
    visited[startCorr.x][startCorr.y] = true;

    int minDis = 987654321;
    while(!myData.empty())  
    {
        int currDis = myData.front().first;
        MyCorr currCorr = myData.front().second;
        myData.pop();

        if (currCorr.x == n - 1 && currCorr.y == m -1) //타겟과 일치하면
        {
            if (minDis > currDis)
            {
                minDis = currDis;
                answer = minDis + 1;
            }
        }
        
        for (int i = 0; i < 4; i++) //상하좌우 확인
        {
            int nextDis = currDis + 1;
            MyCorr nextCorr = { currCorr.x + dir[i].x, currCorr.y + dir[i].y };

            if(nextCorr.x >= 0 && nextCorr.x < n && nextCorr.y >=0 && nextCorr.y < m)    //범위 안에 있으면
            {
                if (maps[nextCorr.x][nextCorr.y] == 1 && visited[nextCorr.x][nextCorr.y] == false)   //지나갈 수 있는 길이라면
                {
                    visited[nextCorr.x][nextCorr.y] = true;
                    myData.push(make_pair(nextDis, nextCorr));
                }
            }
        }
    }

    if (answer == 0)
    {
        answer = -1;
    }    

    return answer;
}

int main()
{
    vector<vector<int> > maps;
    
    maps.resize(5);

    maps[0].push_back(1);
    maps[0].push_back(0);
    maps[0].push_back(1);
    maps[0].push_back(1);
    maps[0].push_back(1);

    maps[1].push_back(1);
    maps[1].push_back(0);
    maps[1].push_back(1);
    maps[1].push_back(0);
    maps[1].push_back(1);

    maps[2].push_back(1);
    maps[2].push_back(0);
    maps[2].push_back(1);
    maps[2].push_back(1);
    maps[2].push_back(1);

    maps[3].push_back(1);
    maps[3].push_back(1);
    maps[3].push_back(1);
    maps[3].push_back(0);
    maps[3].push_back(1);

    maps[4].push_back(0);
    maps[4].push_back(0);
    maps[4].push_back(0);
    maps[4].push_back(0);
    maps[4].push_back(1);

    cout << solution(maps);
}
