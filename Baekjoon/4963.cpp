#include <iostream>
#include <queue>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int dir[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
queue<pair<int, int> > myQ;

void BFS(int x, int y)
{
	visited[x][y] = true;
	myQ.push(make_pair(x, y));

	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dir[i][0];
			int nextY = curY + dir[i][1];

			if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w)
				continue;

			if (map[nextX][nextY] == 1 && visited[nextX][nextY] == false)
			{
				visited[nextX][nextY] = true;
				myQ.push(make_pair(nextX, nextY));
			}
		}
	}
}

int main()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		fill(&map[0][0], &map[51 - 1][51 - 1], 0);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		int cnt = 0;
		fill(&visited[0][0], &visited[51 - 1][51 - 1], 0);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == false)
				{
					cnt++;
					BFS(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}
 
