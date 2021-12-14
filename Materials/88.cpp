#include <iostream>
#include <queue>

using namespace std;

int mazeS = 7;
int maze[7][7];
bool visit[7][7] = { false, };
int dirX[4] = { 0, 0, 1, -1};
int dirY[4] = { 1, -1, 0, 0};
struct Data
{
    int x, y, m;
    Data(int _x, int _y, int _m)
    {
        x = _x;
        y = _y;
        m = _m;
    }
};

int bfs(int  x, int y)
{
    int move = -1;

    queue<Data> myQ;
    myQ.push(Data(x, y, 0));
    visit[x][y] = true;

    while (!myQ.empty())
    {
        int curX = myQ.front().x;
        int curY = myQ.front().y;
        int curM = myQ.front().m;
        myQ.pop();

        if (curX == 6 && curY == 6)
        {
            move = curM;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];

            if (nextX < 0 || nextX >= mazeS || nextY < 0 || nextY >= mazeS)
                continue;

            if (visit[nextX][nextY] == false && maze[nextX][nextY] == 0)
            {
                visit[nextX][nextY] = true;
                myQ.push(Data(nextX, nextY, curM + 1));
            }
        }
    }

    return move;
}

int main(void)
{    
    for (int i = 0; i < mazeS; i++)
        for (int j = 0; j < mazeS; j++)
            cin >> maze[i][j];

    cout << bfs(0, 0);

    return 0;
}
