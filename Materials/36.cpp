#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int i, j;
	for (i = 1; i < n; i++)
	{
		int temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < a[j])
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = temp;
	}

	for (i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
