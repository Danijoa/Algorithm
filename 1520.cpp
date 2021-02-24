#include <iostream>
#define MAX 501
using namespace std;

int w, h;
int map[MAX][MAX];
int dp[MAX][MAX];	//dp[i][j] 지점 일 때 존재하는 경로의 개수
int dy[4] = { 0, 0, -1, 1 };	//좌우
int dx[4] = { -1, 1, 0, 0 };	//상하
int answer = 0;

int solution(int x, int y)
{
	if (x == h-1 && y == w-1)	//도착지 도달
	{
		return 1;
	}

	if (dp[x][y] == -1)	//아직 방문 안한 곳이라면(방문 했는곳은 뒤로 되돌아간거니까 패스)
	{
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++)	//상하좌우 확인할거임
		{
			int n_x = x + dx[i];
			int n_y = y + dy[i];

			if (n_x >= 0 && n_x < h && n_y >= 0 && n_y < w)	//범위 안에 있다면
			{
				if (map[n_x][n_y] < map[x][y])	//내리막이 있다면
				{
					dp[x][y] += solution(n_x, n_y);
				}
			}
		}
	}

	return dp[x][y];
}

int main()
{
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;	//방문 했는기 확인을 위한 초기화
		}
	}

	cout << solution(0, 0);	//(0,0)에서 시작

	return 0;
}
