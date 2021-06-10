#include <iostream>
#include <queue>
#define MAX 9
using namespace std;

int n, m;
int lab[MAX][MAX];
int test[MAX][MAX];
int testCopy[MAX][MAX];
int dir[4][2] = { {0, 1 }, {0, -1}, {-1, 0}, {1, 0} };
queue<pair<int, int> > myQ;
int maxSafe;

void BFS()
{
	// 현재 테스트랩 기준으로 확인할 것
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			testCopy[i][j] = test[i][j];
		}
	}

	// 바이러스 위치 담기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (testCopy[i][j] == 2)
			{
				myQ.push(make_pair(i, j));
			}
		}
	}
	
	// 바이러스 퍼트리기
	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dir[i][0];
			int nextY = curY + dir[i][1];

			// 범위 안에 있음
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)	
				continue;

			// 비어있는 곳 바이러스로 채우고 큐에 넣기
			if (testCopy[nextX][nextY] == 0)	
			{
				testCopy[nextX][nextY] = 2;
				myQ.push(make_pair(nextX, nextY));
			}
		}
	}

	// 초종적 비어있는곳 확인
	int safe = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (testCopy[i][j] == 0)
				safe += 1;
		}
	}
	maxSafe = max(maxSafe, safe);
}

void makeWall(int wallNum)
{	
	// 벽을 3개 세웠으면
	if (wallNum == 3)
	{
		// 안전지역 영역 확인
		BFS();
		return;
	}

	// 현재 test에 저장된 곳 중심으로 확인
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (test[i][j] == 0)
			{
				test[i][j] = 1;
				makeWall(wallNum + 1);
				test[i][j] = 0;
			}
		}
	}
}

int main()
{
	// 연구실 생성
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
		}
	}

	// 최대 안전
	maxSafe = 0;

	// 연구실 비어있는곳 하나씩 확인
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 여기 포함 3개 벽 세우러 가자
			if (lab[i][j] == 0)
			{
				//현재 연구실 상태 복사(lab은 그대로 두기 위함)
				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < m; l++)
					{
						test[k][l] = lab[k][l];
					}
				}

				// 벽 3개 만들기
				test[i][j] = 1;	// 빈 곳에 벽 세우고
				makeWall(1);
				test[i][j] = 0;	//다시 허물고
			}
		}
	}

	cout << maxSafe;

	return 0;
}
