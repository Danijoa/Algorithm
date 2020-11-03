#include <iostream>
using namespace std;

int main()
{
	int cycle;
	cin >> cycle;

	//cal[i][j] -> cur = i, 끝자리 = j (누적)
	long long int cal[65][10] = {0};
	while (cycle!= 0)
	{
		int cur;
		cin >> cur;

		for (int j = 0; j < 10; j++)
		{
			cal[1][j] = j + 1.0;
		}
		for (int i = 2; i <= cur; i++)
		{
			cal[i][0] = 1;
			for(int j = 1; j<10; j++)
			{
				cal[i][j] = cal[i - 1][j] + cal[i][j - 1];
			}
		}

		cout << cal[cur][9] << "\n";

		cycle--;
	}
}
