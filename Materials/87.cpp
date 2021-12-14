#include <queue>

using namespace std;

int mapS;
int map[20][20];
bool visit[20][20] = { false, };
int cnt = 0;
int dirX[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dirY[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

void bfs(int x, int y)
{
    queue<pair<int, int> > myQ;
    myQ.push(make_pair(x, y));
    visit[x][y] = true;

    while (!myQ.empty())
    {
        int curX = myQ.front().first;
        int curY = myQ.front().second;
        myQ.pop();

        for (int i = 0; i < 8; i++)
        {
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];

            if (nextX < 0 || nextX >= mapS || nextY < 0 || nextY >= mapS)
                continue;

            if (visit[nextX][nextY] == false && map[nextX][nextY] == 1)
            {
                visit[nextX][nextY] = true;
                myQ.push(make_pair(nextX, nextY));
            }
        }
    }

}

int main(void)
{    
    cin >> mapS;

    for (int i = 0; i < mapS; i++)
        for (int j = 0; j < mapS; j++)
            cin >> map[i][j];

    for (int i = 0; i < mapS; i++)
    {
        for (int j = 0; j < mapS; j++)
        {
            if (visit[i][j] == false && map[i][j] == 1)
            {
                cnt += 1;
                bfs(i, j);
            }
        }
    }
    bfs(0, 0);

    cout << cnt;

    return 0;
}
