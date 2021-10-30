#include <iostream>

using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int num = i;
		while (num != 0)
		{
			if (num % 10 == d)
				result++;

			num /= 10;
		}
	}
	cout << result;

	return 0;
}
