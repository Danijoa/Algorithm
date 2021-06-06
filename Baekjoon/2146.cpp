#include<iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int mapSize;
int map[101][101] = { 0, };
int landMap[101][101] = { 0, };
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
bool visited[101][101];

// memset: 바이트 단위로 메모리 초기화 -> bool형 배열 초기화 or 0초기화
// memset(visited, false, sizeof(visited));

int BFS(int label)
{
	// 큐 초기화
	queue<pair<int, int>> myQ;

	// 현재 섬 좌표 모두 큐에
	for (int x = 0; x < mapSize; x++)
	{
		for (int y = 0; y < mapSize; y++)
		{
			if (landMap[x][y] == label)
			{
				visited[x][y] = true;
				myQ.push(make_pair(x, y));
			}
		}
	}

	// 다른 섬까지 거리 
	int len = 0;
	while (!myQ.empty())
	{
		int qSize = myQ.size();
		for (int j = 0; j < qSize; j++)
		{
			int curX = myQ.front().first;
			int curY = myQ.front().second;
			myQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < mapSize
					&& nextY >= 0 && nextY < mapSize)
				{
					// 다른 섬이라면
					if (landMap[nextX][nextY] != 0 && landMap[nextX][nextY] != label)
					{
						return len;
					}
					// 섬이 아니라면
					else if (landMap[nextX][nextY] == 0 && visited[nextX][nextY] == false)
					{
						visited[nextX][nextY] = true;
						myQ.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		// 섬이 아닌 부분부터 1회전씩 시작
		len++;
	}
    return len;
}

void DFS(int x, int y, int label)
{
	landMap[x][y] = label;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >=0 && nextX <mapSize 
			&& nextY >= 0 && nextY < mapSize)
		{
			if (map[nextX][nextY] == 1 && landMap[nextX][nextY] == 0)
			{
				DFS(nextX, nextY, label);
			}
		}
	}
}

int main()
{
	// map
	cin >> mapSize;
	for (int x = 0; x < mapSize; x++)
	{
		for (int y = 0; y < mapSize; y++)
		{
			cin >> map[x][y];
		}
	}

	// labeling 
	int label = 0;
	for (int x = 0; x < mapSize; x++)
	{
		for (int y = 0; y < mapSize; y++)
		{
			if (map[x][y] == 1 && landMap[x][y] == 0)
			{
				label++;
				DFS(x, y, label);
			}
		}
	}

	// 각 섬에서 다른 섬까지 거리 구하기
	int bridgeLen = 987654321;
	for (int i = 1; i <= label; i++)
	{
		memset(visited, false, sizeof(visited));
		bridgeLen = min(bridgeLen, BFS(i));
	}

	// 다리 최단길이  
	cout << bridgeLen;

	return 0;
}
