#include <iostream>
#include <queue>
using namespace std;

int n, m;
//int** virus;
int virus[8][8];
//int** test;
int test[8][8];
int room;
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

void spread()
{
	//바이러스
	//int**  test2 = new int* [n];
	//for (int i = 0; i < n; i++)
	//{
	//	test2[i] = new int[m];
	//}
	//test2 = test;

	int test2[8][8];

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			test2[x][y] = test[x][y];
		}
	}

	queue <pair<int, int>> myQ;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (test2[x][y] == 2)
			{
				myQ.push(make_pair(x, y));
			}
		}
	}

	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();

		for (int i=0; i< 4; i++)
		{
			int tempX = curX + dirX[i];
			int tempY = curY + dirY[i];

			if (0 <= tempX && tempX < n && 0 <= tempY && tempY < m)
			{
				if (test2[tempX][tempY] == 0)
				{
					test2[tempX][tempY] = 2;
					myQ.push(make_pair(tempX, tempY));
				}
			}
		}
	}

	int count = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (test2[x][y] == 0)
			{
				count++;
			}
		}
	}

	room = max(room, count);
}

void wall(int num)
{
	if (num == 3)
	{
		spread();
		return;
	}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (test[x][y] == 0)
			{
				test[x][y] = 1;
				wall(num + 1);
				test[x][y] = 0;
			}
		}
	}
	
}

int main()
{
	//입력
	cin >> n >> m;

	//연구소
	//virus = new int* [n];
	//for (int i = 0; i < n; i++)
	//{
	//	virus[i] = new int[m];
	//}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			cin >> virus[x][y];
		}
	}

	//벽
	//test = new int* [n];
	//for (int i = 0; i < n; i++)
	//{
	//	test[i] = new int[m];
	//}

	//계산
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (virus[x][y] == 0)
			{
				for (int x = 0; x < n; x++)
				{
					for (int y = 0; y < m; y++)
					{
						test[x][y] = virus[x][y];
					}
				}

				test[x][y] = 1;
				wall(1);
				test[x][y] = 0;
			}
		}
	}

	//출력
	cout << room;
}
