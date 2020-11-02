#include <iostream>
#include <algorithm>
#define MAX 625
using namespace std;

int v;

int** myVill;
int** check;

int people[MAX];
int number = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y)
{
	check[x][y] = 1;
	people[number]++;

	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if ((0 <= tx && tx < v) && (0 <= ty && ty < v))
		{
			if (myVill[tx][ty] == 1 && check[tx][ty] == 0)
			{
				DFS(tx, ty);
			}
		}
	}
}

int main()
{
	//크기
	cin >> v;

	//myVill 생성
	myVill = new int* [v];
	for (int i = 0; i < v; i++)
	{
		myVill[i] = new int[v];
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			scanf("%1d", &myVill[i][j]);
		}
	}

	//check 생성
	check = new int* [v];
	for (int i = 0; i < v; i++)
	{
		check[i] = new int[v];
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			check[i][j] = 0;
		}
	}

	//people 생성
	for (int i = 0; i < v*v; i++)
	{
		people[i] = 0;
	}

	//DFS
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (myVill[i][j] == 1 && check[i][j] == 0)
			{
				DFS(i, j);
				number++;
			}
		}
	}

	//출력
	cout << number << endl;
	sort(people, people + number);
	for (int i = 0; i < number; i++)
	{
		cout << people[i];
		if (i != number - 1)
			cout << endl;
	}
}
