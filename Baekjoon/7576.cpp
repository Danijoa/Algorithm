#include <iostream>
#include <queue>
using namespace std;

int m, n;
int** tomato;
queue<pair<int, pair<int, int>>> myQ;	//익은 토마토 저장
int dirX[4] = { 0,0,-1,1 };	//좌우
int dirY[4] = { -1,1,0,0 };	//상하
int lastDay = 0;

void solution()
{
	while (!myQ.empty())
	{
		int count = myQ.front().first;
		int curX = myQ.front().second.first;
		int curY = myQ.front().second.second;
		myQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
			{
				continue;
			}

			//비어있음
			if (tomato[nextX][nextY] == -1)
			{
				continue;
			}

			//안익음
			if (tomato[nextX][nextY] == 0)
			{
				tomato[nextX][nextY] = 1;	//1로 바꾸고
				myQ.push(make_pair(count + 1, make_pair(nextX, nextY)));
			}
		}

		lastDay = count;
	}
}

int main()
{
	//가로 세로
	cin >> m >> n;

	//토마토 -1(없) 0(안익) 1(익)
	tomato = new int* [m];
	for (int i = 0; i < m; i++)
	{
		tomato[i] = new int[n];
	}
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			scanf("%d", &tomato[x][y]);
			if (tomato[x][y] == 1)
			{
				myQ.push(make_pair(0, make_pair(x, y)));
			}
		}
	}

	//BFS
	solution();

	//값
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (tomato[x][y] == 0)	//안익은게 있으면
			{
				cout << - 1;
				return 0;
			}
		}
	}
	cout << lastDay;	//날짜 출력
}
