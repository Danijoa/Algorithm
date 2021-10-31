#include <iostream>

using namespace std;

int main()
{
	int m[9][9], hap, mid, min, result;
	float temp;
	for (int i = 0; i < 9; i++)
	{
		hap = 0;

		for (int j = 0; j < 9; j++)
		{
			cin >> m[i][j];
			hap += m[i][j];
		}

		temp = (float)hap / 9;
		mid = (int)(temp + 0.5);
		cout << mid << " ";

		min = abs(mid - m[i][0]);
		result = m[i][0];
		for (int k = 1; k < 9; k++)
		{
			if (min > abs(mid - m[i][k]))
			{
				min = abs(mid - m[i][k]);
				result = m[i][k];
			}
			else if (min == abs(mid - m[i][k]))
			{
				if (result < m[i][k])
					result = m[i][k];
			}
		}
		cout << result << "\n";
	}

	return 0;
}
