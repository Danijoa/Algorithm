#include <iostream>

using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;

	int cnt = 0;
	int d;
	int s[101] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		cin >> d;

		if (d > p)
			s[i] = s[i - 1] + 1;
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < s[i])
			max = s[i];
	}

	cout << max;

	return 0;
}
