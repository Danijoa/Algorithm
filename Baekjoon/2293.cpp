#include <iostream>
using namespace std;

int coinNum, total;
int coins[101];
int dp[10001] = { 0, };	//초기화

//i가치=i~coins-1 만을 사용한 경우의 수 + i을 무조건 포함한 경우의수
int main()
{
	cin >> coinNum >> total;		//3, 19
	for (int i = 0; i < coinNum; i++)
	{
		cin >> coins[i];
	}

	dp[0] = 1;	//초기화
	for (int i = 0; i < coinNum; i++)
	{
		for (int j = coins[i]; j <= total; j++) //2(2포함 2~toal 만들기), 7, 11
		{
			if (j >= coins[i])
			{
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
	}

	cout << dp[total];

	//2 2 2 2 2 2 7
	//2 2 2 2 11

	return 0;
} 
