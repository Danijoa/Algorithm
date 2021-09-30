#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int array[1001];
	for (int i = 1; i <= num; i++)
		cin >> array[i];

	// 이전에 나온 숫자들 array[1]~array[i-1] 중에서
	// 현재 값 array[i]보다 작은 값 중에서
	// 가지고 있는 부분 수열의 길이 dp[1]~dp[i-1]중에서
	// 가장 긴 부분 수열을 가진 길이에 +1을 한 값을
	// dp[i] 값으로 선택

	int dp[1001];
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (array[i] > array[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= num; i++)
	{
		answer = max(dp[i], answer);
	}

	cout << answer;
} 
