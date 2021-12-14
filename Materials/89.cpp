#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w, h;
int tomato = 0;
int box[1000][1000];

int dir[4][2] = { {0,-1}, {0, 1}, {-1, 0}, {1, 0} };
int day = 0;
int cnt = 0;

struct Tomato
{
    int x, y, d;
    Tomato(int _x, int _y, int _d)
    {
        x = _x;
        y = _y;
        d = _d;
    }
};
queue<Tomato> myQ;

void bfs()
{
    while (!myQ.empty())
    {
        // 익은 토마토
        int curX = myQ.front().x;
        int curY = myQ.front().y;
        int curD = myQ.front().d;
        // day 갱신
        day = curD;
        myQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];
            int nextD = curD + 1;

            // 범위 밖
            if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w)
                continue;

            // 주변에 있는 안익은 토마토
            if (box[nextX][nextY] == 0)
            {
                box[nextX][nextY] = 1;
                cnt += 1;
                myQ.push(Tomato(nextX, nextY, nextD));
            }
        }
    }
}

int main(void)
{    
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> box[i][j];
            // 안익은 토마토
            if (box[i][j] == 0)
                tomato += 1;
            // 익은 토마토 큐에 넣기
            else if (box[i][j] == 1)
                myQ.push(Tomato(i, j, 0));
        }
    }

    bfs();

    //cout << tomato << " " << cnt<< "\n";
    if (cnt != tomato)
        cout << -1;
    else
        cout << day;

    return 0;
}
