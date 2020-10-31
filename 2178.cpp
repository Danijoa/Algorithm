#include <iostream>
#include <queue>
using namespace std;

int n, m;   //행렬
int** myMetrix;
int** visited; //방문 확인 및 1에서 몇번째 자식 확인

void BFS(int sX, int sY)
{
	visited[sX][sY] = 1;

	queue<pair<int, int>> myQ;
	myQ.push(make_pair(sX, sY));

	int dX[4] = { -1, 1, 0 , 0 };   //상하
	int dY[4] = { 0, 0, -1, 1 };   //좌우
	while (myQ.empty() != true)
	{
		int x = myQ.front().first;
		int y = myQ.front().second;
		myQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int tX = x + dX[i];
			int tY = y + dY[i];
			if ((1 <= tX && tX <= n) && (1 <= tY && tY <= m))
			{
				if (myMetrix[tX][tY] == 1 && visited[tX][tY] == 0)
				{
					myQ.push(make_pair(tX, tY));
					visited[tX][tY] = visited[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;   //행렬

	//myMetrix 생성 및 값 입력
	myMetrix = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		myMetrix[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &myMetrix[i][j]);
		}
	}

	//visited 생성 및 초기화
	visited = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		visited[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			visited[i][j] = 0;
		}
	}

	BFS(1, 1);

	cout << visited[n][m];
}
