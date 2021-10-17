#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int array[100001];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	int dp[100001];
	dp[0] = 1;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		if (array[i - 1] <= array[i])
		{
			dp[i] = dp[i - 1] + dp[i];
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}
