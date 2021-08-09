#include <iostream>
//#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int const MAX = 1500 + 1;

struct coor
{
	int x, y;
};

int main()
{ 
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int R, C;
	cin >> R >> C;
	
	vector<coor> swanV;
	queue<coor> waterQ;

	//char lake[MAX][MAX];
	//string lake[MAX];
	char** lake = new char* [MAX];
	for (int i = 0; i < MAX; i++)
	{
		lake[i] = new char[MAX];
	}

	for (int i = 0; i < R; i++)
	{
		//cin >> lake[i];

		for (int j = 0; j < C; j++)
		{
			cin >> lake[i][j];

			// 백조위치
			if (lake[i][j] == 'L')
			{
				swanV.push_back({ i, j });
				waterQ.push({ i, j });
			}

			// 물 위치
			if (lake[i][j] == '.')
			{
				waterQ.push({ i, j });
			}
		}
	}
	
	// 이동 백조의 위치 확인해보자
	queue<coor> swanQ;
	swanQ.push(swanV[0]);

	bool** visited = new bool* [MAX];// [MAX] ;// = { false, };
	for (int i = 0; i < MAX; i++)
	{
		visited[i] = new bool[MAX];
		memset(visited[i], false, sizeof(bool) * MAX);
	}
	//fill(&visited[0][0], &visited[MAX-1][MAX], false);
	visited[swanV[0].x][swanV[0].y] = true;

	int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	
	// 백조 이동 + 얼음 녹이기
	int dayPass = 0;
	while (true)
	{
		// 다음날 백조가 탐색 할 곳
		queue<coor> nextQ;

		// 백조 이동
		bool flag = false;
		while (!swanQ.empty())
		{
			int curX = swanQ.front().x;
			int curY = swanQ.front().y;
			swanQ.pop();

			// 다른 백조 만났다
			if (curX == swanV[1].x && curY == swanV[1].y)
			{
				flag = true;
				break;
			}

			// 현재 백조 상하좌우 확인
			for (int i = 0; i < 4; i++)
			{
				int nextX = curX + dir[i][0];
				int nextY = curY + dir[i][1];

				// 범위 밖 or 이미 방문했던 곳
				if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || visited[nextX][nextY])
				{
					continue;
				}

				// 방문 표시
				visited[nextX][nextY] = true;

				// 물에 인첩한 얼음 저장
				if (lake[nextX][nextY] == 'X')
				{
					nextQ.push({ nextX, nextY });
					continue;
				}

				// 백조가 이동할 수 있는 위치는 큐에 넣기
				swanQ.push({ nextX , nextY });
			}
		}
		
		// 백조 만남
		if (flag)
			break;

		// 다음날 백조가 확인할 좌표를 저장해 준다
		swanQ = nextQ;

		// 얼음 녹이기
		int waterSize = waterQ.size();
		while (waterSize--)
		{
			int curX = waterQ.front().x;
			int curY = waterQ.front().y;
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextX = curX + dir[i][0];
				int nextY = curY + dir[i][1];

				if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || visited[nextX][nextY])
				{
					continue;
				}

				if (lake[nextX][nextY] == 'X')
				{
					lake[nextX][nextY] = '.';
					waterQ.push({ nextX , nextY });
				}
			}
		}

		dayPass++;
	}

	cout << dayPass;
	
	return 0;	
}
