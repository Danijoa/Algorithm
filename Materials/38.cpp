#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int invS[101];
	for (int i = 1; i <= num; i++)
	{
		cin >> invS[i];
	}

	int ori[101] = { 0, };
	for (int i = 1; i <= num; i++)
	{
		int j = 1;
		int cnt = 0;
		while (true)
		{
			if (ori[j] == 0 && cnt == invS[i])
				break;

			if (ori[j] == 0 || ori[j] > i)
				cnt++;

			j++;
		}

		ori[j] = i;
	}

	for (int i = 1; i <= num; i++)
	{
		cout << ori[i] << " ";
	}

	return 0;
}

/*
0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 2 0 1 0 0
0 0 0 2 0 1 3 0
4 0 0 2 0 1 3 0
4 0 0 2 5
*/
