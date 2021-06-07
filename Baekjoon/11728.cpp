#include <iostream>
using namespace std;

int size_1, size_2;
int list_1[1000001];
int list_2[1000001];
int list_HAP[2000002];

void sort()
{
	int i = 0, j = 0, k = 0;

	// 비교 삽입
	while (i < size_1 && j < size_2)
	{
		if (list_1[i] <= list_2[j])
		{
			list_HAP[k] = list_1[i];
			i++;
		}
		else
		{
			list_HAP[k] = list_2[j];
			j++;
		}
		k++;
	}

	// 남아있는 애들 삽입
	while (i < size_1)
	{
		list_HAP[k] = list_1[i];
		k++, i++;
	}
	while (j < size_2)
	{
		list_HAP[k] = list_2[j];
		k++, j++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> size_1 >> size_2;

	for (int i = 0; i < size_1; i++)
		cin >> list_1[i];

	for (int i = 0; i < size_2; i++)
		cin >> list_2[i];

	sort();

	for (int i = 0; i < size_1 + size_2; i++)
		cout << list_HAP[i] << " ";

	return 0;
}
