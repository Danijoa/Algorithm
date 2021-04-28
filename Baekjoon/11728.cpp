#include <iostream>
using namespace std;

int n, m;
int list_1[1000001];
int list_2[1000001];
int list_HAP[2000002];

void merge()
{
	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
	{
		if (list_1[i] <= list_2[j])
		{
			list_HAP[k] = list_1[i];
			k++, i++;
		}
		else
		{
			list_HAP[k] = list_2[j];
			k++, j++;
		}
	}

	while (i < n)
	{
		list_HAP[k] = list_1[i];
		k++, i++;
	}
	while (j < m)
	{
		list_HAP[k] = list_2[j];
		k++, j++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> list_1[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> list_2[i];
	}

	merge();

	for (int i = 0; i < n + m; i++)
	{
		cout << list_HAP[i] << " ";
	}
}
