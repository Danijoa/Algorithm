#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int x, y;
int shark[MAX][MAX];
queue<pair<int, int>> myQ;
int dX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS()
{
	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];

			if (nextX >= 0 && nextX < x && nextY >= 0 && nextY < y
				&& shark[nextX][nextY] == 0)
			{
				myQ.push(make_pair(nextX, nextY));
				shark[nextX][nextY] = shark[curX][curY] + 1;
			}
		}
	}
}

int main()
{
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> shark[i][j];
			if (shark[i][j] == 1)
				myQ.push(make_pair(i, j));
		}
	}

	BFS();

	int check = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (check < shark[i][j])
				check = shark[i][j];
		}
	}

	cout << check - 1;

	return 0;
}
