#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int h[101];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	int max = h[n - 1];
	int cnt = 0;
	for (int i = n-1; i >=0; i--)
	{
		if (max < h[i])
		{
			max = h[i];
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
