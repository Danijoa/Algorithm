#include <iostream>
#include <vector>
#define MAX 1111
using namespace std;

int n, m; // 세로, 가로
int q;	//퀸 개수
int k;	//나이트 개수
int p;	//포운 개수
char chess[MAX][MAX];	//체스판
int chess2[MAX][MAX];	//체스판

//오위 오아래 왼위 왼 아래
int dirKX[8] = { -2, 2, -2, 2, -1, 1, -1, 1 };
int dirKY[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };

//상 하 좌 우 오위 오아래 왼위 왼아래(방향)
int dirQX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
int dirQY[8] = { 0, 0, -1, 1, 1, 1, -1, -1};

void queen(int i, int j)
{
	//좌 직선
	for (int k = 0; k < 8; k++)
	{
		int tempQX = i + dirQX[k];
		int tempQY = j + dirQY[k];

		while (true)
		{
			if (chess[tempQX][tempQY] == 'k' || chess[tempQX][tempQY] == 'p' || chess[tempQX][tempQY] == 'q' ||
				tempQX < 1 || tempQX > n || tempQY < 1 || tempQY > m)
			{
				break;
			}
			
			chess2[tempQX][tempQY] = 1;

			tempQX += dirQX[k];
			tempQY += dirQY[k];
		}
	}
}

void knight(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		int tempKX = i + dirKX[k];
		int tempKY = j + dirKY[k];

		if ((tempKX >=1 && tempKX <=n) && (tempKY >= 1 && tempKY <= m))
		{
			chess2[tempKX][tempKY] = 1;
		}
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (chess[i][j] == 'k')
			{
				knight(i, j);
			}

			if (chess[i][j] == 'q')
			{
				queen(i, j);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		chess[a][b] = 'q';
		chess2[a][b] = 1;
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		chess[a][b] = 'k';
		chess2[a][b] = 1;
	}

	cin >> p;
	for (int i = 0; i < p; i++)
	{
		int a, b;
		cin >> a >> b;
		chess[a][b] = 'p';
		chess2[a][b] = 1;
	}

	solution();

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (chess2[i][j] != 1)
			{
				cnt += 1;
			}
		}
	}
	cout << cnt;

	return 0;
}
