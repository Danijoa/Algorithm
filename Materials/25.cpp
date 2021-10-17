#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int score[100];
	for (int i = 0; i < num; i++)
	{
		cin >> score[i];
	}

	int cnt;
	int ans[100];
	for (int i = 0; i < num; i++)
	{
		cnt = 1;
		for (int j = 0; j < num; j++)
		{
			if (score[i] < score[j])
				cnt++;
		}
		ans[i] = cnt;
	}

	for (int i = 0; i < num; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}
