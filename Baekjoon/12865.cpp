#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num, total;
int weight[101];	
int value[101];
// i 번째 물건(의 무게)를 확인중이며, 이때 가방의 무게가 j 일때, 최대 값
int dp[101][100001];

void knapsack()
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			// 현재 탐색하고 있는 물건을 가방에 담을 수 있는 경우
			if (weight[i] <= j)
			{
				// 해당 물건을 가방에 담는 경우
				int in = dp[i - 1][j - weight[i]] + value[i];
				// 해당 물건을 가방에 담지 않는 경우
				int out = dp[i - 1][j];

				dp[i][j] = max(in, out);

			}
			// 현재 탐색하고 있는 물건을 가방에 담을 수 없는 경우
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[num][total];
}

int main()
{
	cin >> num >> total;

	for (int i = 1; i <= num; i++)
		cin >> weight[i] >> value[i];

	knapsack();

	return 0;
}
