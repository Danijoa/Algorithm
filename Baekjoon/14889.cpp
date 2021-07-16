#include <iostream>
#include <vector>
#define MAX 21
#define INF 987654321
using namespace std;

int player;
int chemi[MAX][MAX];
int minDiff = INF;

bool isUsed[MAX];

void calDiff(int cnt, int playerIndex)
{
	// DFS
	if (cnt == player / 2)
	{
		// 스타트팀 & 링크팀
		vector<int> start;
		vector<int> link;

		for (int i = 0; i < player; i++)
		{
			if (isUsed[i])
				start.push_back(i);
			else
				link.push_back(i);
		}

		int a = 0, b = 0;
		for (int i = 0; i < player / 2; i++)
		{
			for (int j = 0; j < player / 2; j++)
			{
				a += chemi[start[i]][start[j]];
				b += chemi[link[i]][link[j]];
			}
		}

		if (minDiff > abs(a - b))
			minDiff = abs(a - b);

		return;
	}

	// 백트레킹
	for (int i = playerIndex; i < player; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			calDiff(cnt + 1, i + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> player;
	
	for (int i = 0; i < player; i++)
		for (int j = 0; j < player; j++)
			cin >> chemi[i][j];

	calDiff(0, 0);

	cout << minDiff;
}
