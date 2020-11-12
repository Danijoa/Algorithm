#include <iostream>
#include <vector>
using namespace std;

int N;
int S[21][21];
int diff = 987654321;
bool isUsed[21];

void solution(int cnt, int index)
{
	if (cnt == N / 2)
	{
		vector<int> start;
		vector<int> link;

		for (int i = 1; i <= N; i++)
		{
			if (isUsed[i])
			{
				start.push_back(i);
			}
			else
				link.push_back(i);
		}

		int a = 0, b = 0;
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				a += S[start[i]][start[j]];// +S[start[j]][start[i]];
				b += S[link[i]][link[j]];// +S[link[j]][link[i]];
			}
		}

		diff = diff > abs(a - b) ? abs(a - b) : diff;

		return;
	}
 
	for (int i = index + 1; i <= N; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			solution(cnt + 1, i);
			isUsed[i] = false;
		}
	}

}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> S[i][j];
		}
	}

	solution(0, 0);

	cout << diff;

	return 0;
}
