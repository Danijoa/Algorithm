#include <iostream>
#include <algorithm>
#define MAX 625
using namespace std;

int num;
int** vill;

int** label;
int dir[4][2] = { {-1, 0},  {1, 0}, {0, -1}, {0, 1} };

int curLabel;
int people[MAX] = { 0, };

void DFS(int x, int y)
{
	label[x][y] = curLabel;
	people[curLabel]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < 0 || nx >= num || ny < 0 || ny >= num)
			continue;

		if (vill[nx][ny] == 1 && label[nx][ny] == 0)
			DFS(nx, ny);
	}
}

int main()
{
	cin >> num;

	vill = new int*[num];
	label = new int* [num];
	for (int i = 0; i < num; i++)
	{
		vill[i] = new int[num];
		label[i] = new int[num];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			vill[i][j] = 0;
			label[i][j] = 0;
			scanf_s("%1d", &vill[i][j]);
		}
	}

	curLabel = 1;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (vill[i][j] == 1 && label[i][j] == 0)
			{
				DFS(i, j);
				curLabel++;
			}
		}
	}

	/*
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << label[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cout << curLabel - 1 << endl;
	sort(people + 1, people + curLabel);
	for (int i = 1; i <= curLabel - 1; i++)
	{
		cout << people[i] << endl;
	}
}
