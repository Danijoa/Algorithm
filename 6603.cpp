#include <iostream>
#define MAX 13
using namespace std;

int k = -1;	//6<k<13
int s[MAX];
int lotto[6];

void solution(int node, int lottoIndex)
{
	if (lottoIndex == 6)	//출력 solution(k, 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = node; i < k; i++)
	{
		lotto[lottoIndex] = s[i];
		solution(i + 1, lottoIndex + 1);
	}
}

int main()
{
	while (1)
	{
		cin >> k;
		if (k == 0)
		{
			break;
		}

		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
		}

		solution(0, 0);
		cout << "\n";
	}
}
