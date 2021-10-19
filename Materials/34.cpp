#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = n - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (a[i] > a[i + 1])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
