#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int x, y, trash;
int road[MAX][MAX];	//1부터 시작
int maxCnt = -1;
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

void BFS(int _x, int _y)
{
	queue<pair<int, int>> myQ;
	myQ.push(make_pair(_x, _y));
	road[_x][_y] = 0;

	int num = 0;
	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();
		num++;

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX >= 1 && nextX <= x && nextY >= 1 && nextY <= y
				&& road[nextX][nextY] == 1)
			{
				myQ.push(make_pair(nextX, nextY));
				road[nextX][nextY] = 0;
			}
		}
	}

	if (maxCnt < num)
		maxCnt = num;
}

int main()
{
	cin >> x >> y >> trash;
	for (int i = 0; i < trash; i++)
	{
		int a, b;
		cin >> a >> b;
		road[a][b] = 1;
	}

	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (road[i][j] == 1)	//아직 방문 안한 곳이라면
			{
				BFS(i, j);
			}
		}
	}

	cout << maxCnt;

	return 0;
}
