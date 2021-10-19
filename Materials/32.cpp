#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		int temp, min = a[i], index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				index = j;
			}
		}

		temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
