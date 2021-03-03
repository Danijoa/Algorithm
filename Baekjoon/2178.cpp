#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int garo, searo;
int maze[MAX][MAX];
int visited[MAX][MAX];   //방문했으면 1 안했으면 0
queue <pair<int, int>> dataQ;  //(cost, (i, j))
int dX[4] = { -1,1,0,0 };
int dY[4] = { 0,0,-1,1 };

void bfs()
{
    while (!dataQ.empty())
    {
        int curX = dataQ.front().first;
        int curY = dataQ.front().second;
        dataQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];

            if ((nextX >= 1 && nextX <= searo) && (nextY >= 1 && nextY <= garo))   //범위안에 있는
            {
                if (maze[nextX][nextY] == 1 && visited[nextX][nextY] == 0)  //길이면서, 아직 방문 전이면
                {
                    dataQ.push(make_pair(nextX, nextY));
                    visited[nextX][nextY] = visited[curX][curY] + 1;
                }
            }
        }
    }
}

int main()
{
    //입력
    cin >> searo >> garo;
    for (int i = 1; i <= searo; i++)
    {
        for (int j = 1; j <= garo; j++)
        {
            scanf_s("%1d", &maze[i][j]);   //붙여서 출력(0: 벽  /  1:길)
        }
    } 

    //초기화
    visited[1][1] = 1;
    dataQ.push(make_pair(1, 1));

    //4가지 방향을 확인해 가며 전진하니까 bfs를 사용해 보자
    bfs();

    //결과
    cout << visited[searo][garo];

	return 0;
}
