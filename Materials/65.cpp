#include <iostream>
#include <vector>

using namespace std;

int maze[7][7];
int cnt = 0;
bool visited[7][7] = { false, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void DFS(int x, int y)
{
	if (x == 6 && y == 6)
	{
		cnt += 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int _x = x + dir[i][0], _y = y + dir[i][1];
		if (_x < 0 || _x >= 7 || _y < 0 || _y >= 7)
			continue;

		if (maze[_x][_y] == 0 && visited[_x][_y] == false)
		{
			visited[_x][_y] = true;
			DFS(_x, _y);
			visited[_x][_y] = false;
		}
	}
}

int main() 
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			cin >> maze[i][j];

	visited[0][0] = true;
	DFS(0, 0);

	cout << cnt;
	
	return 0;
}
