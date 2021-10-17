#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int array[100001];
	for (int i = 0; i < num; i++)
	{
		cin >> array[i];
	}

	// 나보다 큰수 개수 + 1 = 나의 output
	int cnt;
	for (int i = 0; i < num; i++)
	{
		cnt = 1;
		for (int j = 0; j < i; j++)
		{
			if (array[j] >= array[i])
				cnt++;
		}
		cout << cnt << " ";
	}

	return 0;
}
