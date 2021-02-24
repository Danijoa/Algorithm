#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int farm[MAX][MAX];
int width, height;
int answer = 0;
int dp[MAX][MAX] = {0};	//0 정사각형 못만듬 1..2....3..등은 그 사이즈 만큼 만들 수 있다는 뜻

void solution()
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (farm[i][j] == 0)	//비어 있는 땅 주변 확인
			{
				//←↖↑위치에서 만들 수 있는 정사각형 사이즈중 최소의 사이즈 + 1
				//= 현재 위치에서 만들 수 있는  
				dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
}

int main()
{
	cin >> height;	//세로
	cin >> width;	//가로

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			cin >> farm[i][j];
		}
	}

	solution();

	cout << answer;
	
	return 0;
}
