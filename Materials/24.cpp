#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int jump[101];
	int idx;
	int cha[101] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> jump[i];

		if (i > 0)
		{
			idx = abs(jump[i] - jump[i - 1]); // 정수 - 정수
			if (idx <= n - 1)
				cha[idx] = 1;
		}
	}

	string ans = "YES";
	for (int i = 1; i <= n - 1; i++)
	{
		if (cha[i] != 1)
		{
			ans = "NO";
			break;
		}
	}

	cout << ans;

	return 0;
}
