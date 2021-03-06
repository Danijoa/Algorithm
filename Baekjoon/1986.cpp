#include <iostream>
#define MAX 1001
using namespace std;

int x, y;
char map[MAX][MAX];
int visited[MAX][MAX];

//Queen 좌우대각선 
int qX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int qY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// Knight 두칸앞+좌or우
int kX[8] = { -2, -2, 2, 2, -1, 1, -1, 1 };
int kY[8] = { -1, 1, -1, 1, -2, -2, 2, 2 };

void Queen(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		int nextX = i + qX[k];
		int nextY = j + qY[k];

		while (true)
		{
			if (map[nextX][nextY] == 'k' || map[nextX][nextY] == 'p' || map[nextX][nextY] == 'q' || nextX < 1 || nextX > x || nextY < 1 || nextY > y)
				break;

			visited[nextX][nextY] = 1;

			nextX += qX[k];
			nextY += qY[k];
		}
	}
}

void Knight(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		int nextX = i + kX[k];
		int nextY = j + kY[k];
		if ((nextX >= 1 && nextX <= x) && (nextY >= 1 && nextY <= y))
			visited[nextX][nextY] = 1;
	}
}

void solve()
{
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (map[i][j] == 'q')
			{
				Queen(i, j);
			}
			if (map[i][j] == 'k')
			{
				Knight(i, j);
			}
		}
	}
}


int main()
{
	cin >> x >> y;

	//fill_n(map[0][0], map[MAX][MAX], '0');

	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			map[x][y] = '0';
		}
	}

	for (int i = 0; i < 3; i++)
	{
		char chess;
		switch (i) {
		case 0:
			chess = 'q';
			break;
		case 1:
			chess = 'k';
			break;
		case 2:
			chess = 'p';
			break;
		}

		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int a, b;
			cin >> a >> b; 
			map[a][b] = chess;
			visited[a][b] = 1;
		}
	}

	solve();

	int cnt = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (visited[i][j] != 1)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}
