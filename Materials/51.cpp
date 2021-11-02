#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;

	int** dp = new int* [x + 1];
	for (int i = 0; i < x + 1; i++)
	{
		dp[i] = new int[y + 1];
		for (int j = 0; j < y + 1; j++)
			dp[i][j] = 0;
	}

  // dp[i][j] = [1][1]~[i][j] 영역의 합
	int orange;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
		{
			cin >> orange;
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + orange;
		}

	int h, w;
	cin >> h >> w;

  // size = [i-h-1][j-w-1]~[i][j] 영역의 합
	int max = 0, size = 0;
	for (int i = h; i <= x; i++)
		for (int j = w; j <= y; j++)
		{
			size = dp[i][j] - dp[i][j - w] - dp[i - h][j] + dp[i - h][j - w];
			if (max < size)
				max = size;
		}

	cout << max;

	return 0;
}
