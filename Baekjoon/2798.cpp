#include <iostream>
#define MAX 101
using namespace std;

int main()
{
	int num, pivot;
	cin >> num >> pivot;

	int card[MAX];
	for (int i = 0; i < num; i++)
	{
		cin >> card[i];
	}

	int findMax = 0;
	for (int i = 0; i < num - 2; i++)
	{
		for (int j = i + 1; j < num - 1; j++)
		{
			for (int k = j + 1; k < num; k++)
			{
				int sum = card[i] + card[j] + card[k];
				if (findMax < sum && sum <= pivot)
				{
					findMax = sum;
				}
			}
		}
	}

	cout << findMax;
	return 0;
}
