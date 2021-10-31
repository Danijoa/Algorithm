#include <iostream>

using namespace std;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main()
{
	int num;
	cin >> num;

	int matrix[51][51];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> matrix[i][j];
		}
	}

	bool bog;
	int cnt = 0;
	for (int cX = 0; cX < num; cX++)
	{
		for (int cY = 0; cY < num; cY++)
		{
			bog = true;
			for (int k = 0; k < 4; k++)
			{
				int nX = cX + dir[k][0];
				int nY = cY + dir[k][1];

				if (nX < 0 || nX >= num || nY < 0 || nY >= num)
					continue;

				if(matrix[nX][nY] >= matrix[cX][cY])
				{
					bog = false;
					break;
				}
			}
			if (bog == true)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}
