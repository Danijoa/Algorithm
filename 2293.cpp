#include <iostream>
using namespace std;

int coinNum, k;
int coins[101];
int dp[10001] = {0};

//k가치=1~coins-1 만을 사용한 경우의 수 + coins을 무조건 포함한 경우의수
int main()
{
	cin >> coinNum >> k;
	for (int i = 0; i < coinNum; i++)
	{
		cin >> coins[i];
	}

	dp[0] = 1; //0가치=0으로 만들 수 있는 경우의 수

	for (int i = 0; i < coinNum; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			if (j - coins[i] >= 0)
			{
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
	}	

	cout << dp[k];
	return 0;
}
